#
# a cmake implementation of the Wrap Java command
#

MACRO(VTK_WRAP_JAVA2 TARGET SOURCE_LIST_NAME)
  # convert to the WRAP3 signature
  vtk_wrap_java3(${TARGET} ${SOURCE_LIST_NAME} "${ARGN}")
ENDMACRO()

macro(vtk_wrap_java3 TARGET SRC_LIST_NAME SOURCES)
  if(NOT VTK_PARSE_JAVA_EXE)
    if(TARGET vtkParseJava)
      set(VTK_PARSE_JAVA_EXE vtkParseJava)
    else()
      message(SEND_ERROR
        "VTK_PARSE_JAVA_EXE not specified when calling VTK_WRAP_JAVA3")
    endif()
  endif()
  if(NOT VTK_WRAP_JAVA_EXE)
    if(TARGET vtkWrapJava)
      set(VTK_WRAP_JAVA_EXE vtkWrapJava)
    else()
      message(SEND_ERROR
        "VTK_WRAP_JAVA_EXE not specified when calling VTK_WRAP_JAVA3")
    endif()
  endif()

  # Initialize the custom target counter.
  IF(VTK_WRAP_JAVA_NEED_CUSTOM_TARGETS)
    SET(VTK_WRAP_JAVA_CUSTOM_COUNT "")
    SET(VTK_WRAP_JAVA_CUSTOM_NAME ${TARGET})
    SET(VTK_WRAP_JAVA_CUSTOM_LIST)
  ENDIF()

  # collect the common wrapper-tool arguments
  set(_common_args)
  if(VTK_WRAP_HINTS)
    set(_common_args "${_common_args}--hints \"${VTK_WRAP_HINTS}\"\n")
  endif()
  if(KIT_HIERARCHY_FILE)
    set(_common_args "${_common_args}--types \"${KIT_HIERARCHY_FILE}\"\n")
  endif()

  if(NOT VTK_ENABLE_KITS)
    # write wrapper-tool arguments to a file
    set(_args_file ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.$<CONFIGURATION>.args)
    file(GENERATE OUTPUT ${_args_file} CONTENT "${_common_args}
$<$<BOOL:$<TARGET_PROPERTY:${TARGET},COMPILE_DEFINITIONS>>:
-D\"$<JOIN:$<TARGET_PROPERTY:${TARGET},COMPILE_DEFINITIONS>,\"
-D\">\">
$<$<BOOL:$<TARGET_PROPERTY:${TARGET},INCLUDE_DIRECTORIES>>:
-I\"$<JOIN:$<TARGET_PROPERTY:${TARGET},INCLUDE_DIRECTORIES>,\"
-I\">\">
")
  else()
    # all the include directories
    if(VTK_WRAP_INCLUDE_DIRS)
      set(TMP_INCLUDE_DIRS ${VTK_WRAP_INCLUDE_DIRS})
    else()
      set(TMP_INCLUDE_DIRS ${VTK_INCLUDE_DIRS})
    endif()
    foreach(INCLUDE_DIR ${TMP_INCLUDE_DIRS})
      set(_common_args "${_common_args}-I\"${INCLUDE_DIR}\"\n")
    endforeach()
    get_directory_property(_def_list DEFINITION COMPILE_DEFINITIONS)
    foreach(TMP_DEF ${_def_list})
      set(_common_args "${_common_args}-D${TMP_DEF}\n")
    endforeach()
    # write wrapper-tool arguments to a file
    string(STRIP "${_common_args}" CMAKE_CONFIGURABLE_FILE_CONTENT)
    set(_args_file ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.args)
    configure_file(${CMAKE_ROOT}/Modules/CMakeConfigurableFile.in
                   ${_args_file} @ONLY)
  endif()

  SET(VTK_JAVA_DEPENDENCIES)
  SET(VTK_JAVA_DEPENDENCIES_FILE)

  if (CMAKE_GENERATOR MATCHES "Ninja")
    set(hierarchy_depend ${KIT_HIERARCHY_FILE})
  else ()
    string(LENGTH "${TARGET}" target_length)
    math(EXPR target_length "${target_length} - 4")
    string(SUBSTRING "${TARGET}" 0 "${target_length}" target_basename)
    set(hierarchy_depend "${target_basename}Hierarchy")
  endif ()

  # For each class
  FOREACH(FILE ${SOURCES})
    # some wrapped files need to be compiled as objective C++
    get_source_file_property(TMP_WRAP_OBJC ${FILE} WRAP_JAVA_OBJC)

    # what is the filename without the extension
    GET_FILENAME_COMPONENT(TMP_FILENAME ${FILE} NAME_WE)

    # the input file might be full path so handle that
    GET_FILENAME_COMPONENT(TMP_FILEPATH ${FILE} PATH)

    # compute the input filename
    IF (TMP_FILEPATH)
      SET(TMP_INPUT ${TMP_FILEPATH}/${TMP_FILENAME}.h)
    ELSE ()
      SET(TMP_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${TMP_FILENAME}.h)
    ENDIF ()

    # ensure that header exists
    if(NOT EXISTS ${TMP_INPUT})
      continue ()
    endif()

    # use ".mm" suffix if file must be compiled with objective C++
    IF(TMP_WRAP_OBJC)
      SET(TMP_WRAPPED_FILENAME ${TMP_FILENAME}Java.mm)
    ELSE()
      SET(TMP_WRAPPED_FILENAME ${TMP_FILENAME}Java.cxx)
    ENDIF()

    # new source file is nameJava.cxx, add to resulting list
    SET(${SRC_LIST_NAME} ${${SRC_LIST_NAME}}
      ${TMP_WRAPPED_FILENAME})

    # add custom command to output
    ADD_CUSTOM_COMMAND(
      OUTPUT ${VTK_JAVA_HOME}/${TMP_FILENAME}.java
      DEPENDS ${VTK_PARSE_JAVA_EXE}
              ${VTK_WRAP_HINTS}
              ${TMP_INPUT}
              ${_args_file}
              ${hierarchy_depend}
      COMMAND ${VTK_PARSE_JAVA_EXE}
              @${_args_file}
              -o ${VTK_JAVA_HOME}/${TMP_FILENAME}.java
              ${TMP_INPUT}
      COMMENT "Java Wrappings - generating ${TMP_FILENAME}.java"
      VERBATIM
      )

    # add custom command to output
    ADD_CUSTOM_COMMAND(
      OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${TMP_WRAPPED_FILENAME}
      DEPENDS ${VTK_WRAP_JAVA_EXE}
              ${VTK_WRAP_HINTS}
              ${TMP_INPUT}
              ${_args_file}
              ${KIT_HIERARCHY_FILE}
      COMMAND ${VTK_WRAP_JAVA_EXE}
              @${_args_file}
              -o ${CMAKE_CURRENT_BINARY_DIR}/${TMP_WRAPPED_FILENAME}
              ${TMP_INPUT}
      COMMENT "Java Wrappings - generating ${TMP_WRAPPED_FILENAME}"
      VERBATIM
      )

    SET(VTK_JAVA_DEPENDENCIES ${VTK_JAVA_DEPENDENCIES} "${VTK_JAVA_HOME}/${TMP_FILENAME}.java")
    SET(VTK_JAVA_DEPENDENCIES_FILE
      "${VTK_JAVA_DEPENDENCIES_FILE}\n  \"${VTK_JAVA_HOME}/${TMP_FILENAME}.java\"")

    # Add this output to a custom target if needed.
    IF(VTK_WRAP_JAVA_NEED_CUSTOM_TARGETS)
      SET(VTK_WRAP_JAVA_CUSTOM_LIST ${VTK_WRAP_JAVA_CUSTOM_LIST}
        ${CMAKE_CURRENT_BINARY_DIR}/${TMP_WRAPPED_FILENAME}
        )
      SET(VTK_WRAP_JAVA_CUSTOM_COUNT ${VTK_WRAP_JAVA_CUSTOM_COUNT}x)
      IF(VTK_WRAP_JAVA_CUSTOM_COUNT MATCHES "^${VTK_WRAP_JAVA_CUSTOM_LIMIT}$")
        SET(VTK_WRAP_JAVA_CUSTOM_NAME ${VTK_WRAP_JAVA_CUSTOM_NAME}Hack)
        ADD_CUSTOM_TARGET(${VTK_WRAP_JAVA_CUSTOM_NAME} DEPENDS ${VTK_WRAP_JAVA_CUSTOM_LIST})
        SET(KIT_JAVA_DEPS ${VTK_WRAP_JAVA_CUSTOM_NAME})
        SET(VTK_WRAP_JAVA_CUSTOM_LIST)
        SET(VTK_WRAP_JAVA_CUSTOM_COUNT)
      ENDIF()
    ENDIF ()
  ENDFOREACH()

  ADD_CUSTOM_TARGET("${TARGET}JavaClasses" ALL DEPENDS ${VTK_JAVA_DEPENDENCIES})
  SET(dir ${CMAKE_CURRENT_SOURCE_DIR})
  IF(VTK_WRAP_JAVA3_INIT_DIR)
    SET(dir ${VTK_WRAP_JAVA3_INIT_DIR})
  ENDIF()
  CONFIGURE_FILE("${dir}/JavaDependencies.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/JavaDependencies.cmake" @ONLY)
endmacro()

# VS 6 does not like needing to run a huge number of custom commands
# when building a single target.  Generate some extra custom targets
# that run the custom commands before the main target is built.  This
# is a hack to work-around the limitation.  The test to enable it is
# done here since it does not need to be done for every macro
# invocation.
IF(CMAKE_GENERATOR STREQUAL "Visual Studio 6")
  SET(VTK_WRAP_JAVA_NEED_CUSTOM_TARGETS 1)
  SET(VTK_WRAP_JAVA_CUSTOM_LIMIT x)
  # Limit the number of custom commands in each target
  # to 2^7.
  FOREACH(t 1 2 3 4 5 6 7)
    SET(VTK_WRAP_JAVA_CUSTOM_LIMIT
      ${VTK_WRAP_JAVA_CUSTOM_LIMIT}${VTK_WRAP_JAVA_CUSTOM_LIMIT})
  ENDFOREACH()
ENDIF()
