include(vtkPythonPackages)

#------------------------------------------------------------------------------
# This file extends vtkModuleMacros.cmake to add support for VTK modules that
# are pure Python packages or modules.
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Corresponds to vtk_module_library(), instead we're now adding a Python
# package. This is designed for packages and hence do not use when dealing with
# Python modules.
# Typical usage is as follows:
# vtk_module_python_package(
#   AutobahnPython  # name of the vtk-module
#   autobahn        # package directory i.e. the directory with __init__.py file.
#   ...             # additional packages.
#   [NO_INSTALL]    # if present, install rules are skipped.
#   [CAN_USE_SYSTEM]    # if present, user will be provided with an option to use
#                       # system package.
#   [RELATIVE dir]  # If present, the destination package location is determined
#                   # using the source location relative to the ${dir} (see
#                   VTK/Web/Python/CMakeLists.txt for usage).
#   [DEPENDS [depends ...]] # if present, provides dependencies before the
#                           # module files are copied, built, etc.
# )
# Uses following global variables:
# VTK_BUILD_PYTHON_MODULES_DIR :- location where the entire package will be
#           copied and built. Thus, for the above example we'd get a
#           ${VTK_BUILD_PYTHON_MODULES_DIR}/autobahn package.
#
# VTK_INSTALL_PYTHON_MODULES_DIR :- location where the entire package will be
#           installed if NO_INSTALL is not provided.
#
# VTK_INSTALL_NO_RUNTIME :- install rules are skipped if set.
#------------------------------------------------------------------------------
function (vtk_module_python_package name)
  if(NOT "${name}" STREQUAL "${vtk-module}")
    message(FATAL_ERROR "vtk_module_library must be invoked with module name")
  endif()

  vtk_module_impl()
  vtk_module_export("")
  vtk_python_package(${name} ${ARGN})
endfunction()


#------------------------------------------------------------------------------
# This is same as vtk_module_python_package except it can be used for a Python
# package that's not a VTK module. This is indeed called by
# `vtk_module_python_package` once the VTK module specific init/export calls are
# invoked.
#------------------------------------------------------------------------------
function(vtk_python_package name)
  set(_packages)
  set(_no_install)
  set(_can_use_system)
  set(_doing)
  set(_relative)
  set(_depends)
  foreach(arg ${ARGN})
    if(arg STREQUAL "NO_INSTALL")
      set (_no_install TRUE)
      set (_doing)
    elseif(arg STREQUAL "CAN_USE_SYSTEM")
      set (_can_use_system TRUE)
      set (_doing)
    elseif (arg MATCHES "^(RELATIVE|DEPENDS)$")
      set(_doing "${arg}")
    elseif (_doing STREQUAL "RELATIVE")
      set (_relative "${arg}")
      set (_doing)
    elseif(_doing STREQUAL "DEPENDS")
      list(APPEND _depends "${arg}")
    else()
      list(APPEND _packages "${arg}")
    endif()
  endforeach()

  find_package(PythonInterp ${VTK_PYTHON_VERSION} QUIET)

  set (_depencies)
  foreach(pkg ${_packages})
    get_filename_component(_dir "${pkg}" ABSOLUTE)
    get_filename_component(_name "${pkg}" NAME)
    if(_relative)
      file(RELATIVE_PATH _name_target "${_relative}" "${_dir}")
    else()
      set (_name_target "${_name}")
    endif()

    set (_use_system FALSE)
    if (_can_use_system)
      string(TOUPPER "${_name}" _name_upper)
      option(VTK_USE_SYSTEM_${_name_upper} "Use system '${_name}' Python package" OFF)
      mark_as_advanced(VTK_USE_SYSTEM_${_name_upper})
      set (_use_system ${VTK_USE_SYSTEM_${_name_upper}})
    endif()

    if (NOT _use_system)
      # copy the sources *.py files to build directory.
      if(_depends)
        set(_extra_args DEPENDS ${_depends})
      endif()
      copy_files_recursive("${_dir}"
        DESTINATION ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_target}
        LABEL "Copying files for Python package '${_name}'"
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${_name}.copy-complete"
        REGEX "^(.*\\.py)$"
        ${_extra_args})
      unset(_extra_args)

      if (PYTHON_EXECUTABLE)
        add_custom_command(
          COMMAND ${PYTHON_EXECUTABLE} -m compileall ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_target}
          COMMAND ${PYTHON_EXECUTABLE} -O -m compileall ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_target}
          COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_CURRENT_BINARY_DIR}/${_name}.build-complete"
          DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${_name}.copy-complete"
          OUTPUT  "${CMAKE_CURRENT_BINARY_DIR}/${_name}.build-complete"
          COMMENT "Compiling Python package '${_name}'")

        # save the output file so we can add a target for the module with proper
        # dependency.
        list(APPEND _depencies "${CMAKE_CURRENT_BINARY_DIR}/${_name}.build-complete")
      else()
        # skip compiling Python modules since PYTHON_EXECUTABLE is not
        # available. In that case, we just depend on the copying to have
        # completed.
        list(APPEND _depencies "${CMAKE_CURRENT_BINARY_DIR}/${_name}.copy-complete")
      endif()

      # add install rules.
      if (NOT _no_install AND NOT VTK_INSTALL_NO_RUNTIME)
        install(DIRECTORY ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_target}/
                DESTINATION ${VTK_INSTALL_PYTHON_MODULES_DIR}/${_name_target}
                COMPONENT RuntimeLibraries
                # Add exclusions to avoid installing VTK's C++ Python modules
                # These have their own install rules.
                PATTERN "vtk*Python.so" EXCLUDE
                PATTERN "vtk*Python.pyd" EXCLUDE)
      endif()
    endif() # NOT _use_system
  endforeach()

  if (_depencies)
    add_custom_target(${name} ALL DEPENDS ${_depencies})
  endif()
endfunction()

#------------------------------------------------------------------------------
# This is similar to vtk_module_python_package(), except designed to be used for
# Python modules (not packages). Modules are simply Py files without any
# directory structure and __init__.py file.
# Typical usage:
# vtk_module_python_module(
#   SixPython           # name of the vtk-module
#   six.py              # name of the module py file
#   ...                 # additional module files.
#   [NO_INSTALL]        # if present, install rules are skipped.
#   [CAN_USE_SYSTEM]    # if present, user will be provided with an option to use
#                       # system module.
#
# Uses following global variables:
# VTK_BUILD_PYTHON_MODULES_DIR :- location where the entire package will be
#           copied and built. Thus, for the above example we'd get a
#           ${VTK_BUILD_PYTHON_MODULES_DIR}/autobahn package.
#
# VTK_INSTALL_PYTHON_MODULES_DIR :- location where the entire package will be
#           installed if NO_INSTALL is not provided.
#
# VTK_INSTALL_NO_RUNTIME :- install rules are skipped if set.
#------------------------------------------------------------------------------
function (vtk_module_python_module name)
  if(NOT "${name}" STREQUAL "${vtk-module}")
    message(FATAL_ERROR "vtk_module_library must be invoked with module name")
  endif()
  vtk_module_impl()
  vtk_module_export("")
  vtk_python_module(${name} ${ARGN})
endfunction()

function(vtk_python_module name)
  set(_modules)
  set(_no_install)
  set(_can_use_system)
  foreach(arg ${ARGN})
    if(arg STREQUAL "NO_INSTALL")
      set (_no_install TRUE)
    elseif(arg STREQUAL "CAN_USE_SYSTEM")
      set (_can_use_system TRUE)
    else()
      list(APPEND _modules "${arg}")
    endif()
  endforeach()

  find_package(PythonInterp REQUIRED)

  set (_depencies)
  foreach(mdl ${_modules})
    get_filename_component(_module "${mdl}" ABSOLUTE)
    get_filename_component(_name_we   "${mdl}" NAME_WE)
    get_filename_component(_name   "${mdl}" NAME)

    set (_use_system FALSE)
    if (_can_use_system)
      string(TOUPPER "${_name_we}" _name_we_upper)
      option(VTK_USE_SYSTEM_${_name_we_upper} "Use system '${_name_we}' Python Module" OFF)
      mark_as_advanced(VTK_USE_SYSTEM_${_name_we_upper})
      set (_use_system ${VTK_USE_SYSTEM_${_name_we_upper}})
    endif()

    if (NOT _use_system)
      # copy the *.py file to the build directory and compile it.
      add_custom_command(
        COMMAND ${CMAKE_COMMAND} -E copy ${_module} ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name}
        COMMAND ${PYTHON_EXECUTABLE} -m py_compile ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name}
        COMMAND ${PYTHON_EXECUTABLE} -O -m py_compile ${VTK_BUILD_PYTHON_MODULES_DIR}/${_name}
        COMMAND ${CMAKE_COMMAND} -E touch "${CMAKE_CURRENT_BINARY_DIR}/${_name_we}.build-complete"
        DEPENDS ${_module}
        OUTPUT  "${CMAKE_CURRENT_BINARY_DIR}/${_name_we}.build-complete"
        COMMENT "Copying and compiling Python module '${_name_we}'")

      # save the output file so we can add a target for the module with proper
      # dependency.
      list(APPEND _depencies "${CMAKE_CURRENT_BINARY_DIR}/${_name_we}.build-complete")

      # add install rules.
      if (NOT _no_install AND NOT VTK_INSTALL_NO_RUNTIME)
        if(PYTHON_VERSION_STRING VERSION_LESS 3)
          install(FILES "${VTK_BUILD_PYTHON_MODULES_DIR}/${_name}"
                        "${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_we}.pyc"
                        "${VTK_BUILD_PYTHON_MODULES_DIR}/${_name_we}.pyo"
                  DESTINATION "${VTK_INSTALL_PYTHON_MODULES_DIR}"
                  COMPONENT RuntimeLibraries)
        else()
          # python 3 uses a different directory for .pyc files, and .pyo files are gone.
          install(FILES "${VTK_BUILD_PYTHON_MODULES_DIR}/${_name}"
                  DESTINATION "${VTK_INSTALL_PYTHON_MODULES_DIR}"
                  COMPONENT RuntimeLibraries)
          file(GLOB file_matches "${VTK_BUILD_PYTHON_MODULES_DIR}/__pycache__/${_name_we}.*.pyc")
          install(FILES ${file_matches}
                  DESTINATION "${VTK_INSTALL_PYTHON_MODULES_DIR}/__pycache__"
                  COMPONENT RuntimeLibraries)
        endif()
      endif()
    endif() # NOT _use_system
  endforeach()

  if (_depencies)
    add_custom_target(${name} ALL DEPENDS ${_depencies})
  endif()
endfunction()
