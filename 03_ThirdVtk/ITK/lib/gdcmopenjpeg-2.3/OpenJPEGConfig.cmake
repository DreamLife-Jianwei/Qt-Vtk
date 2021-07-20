#-----------------------------------------------------------------------------
#
# OPENJPEGConfig.cmake - CMake configuration file for external projects.
#
# This file is configured by OPENJPEG and used by the UseOPENJPEG.cmake
# module to load OPENJPEG's settings for an external project.

# The OPENJPEG version number.
set(OPENJPEG_VERSION_MAJOR "2")
set(OPENJPEG_VERSION_MINOR "3")
set(OPENJPEG_VERSION_BUILD "0")

# The libraries.
set(OPENJPEG_LIBRARIES "gdcmopenjp2")

# The CMake macros dir.
set(OPENJPEG_CMAKE_DIR "lib/gdcmopenjpeg-2.3")

# The configuration options.
set(OPENJPEG_BUILD_SHARED_LIBS "OFF")

# The "use" file.
set(OPENJPEG_USE_FILE "")

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
if(EXISTS ${SELF_DIR}/OpenJPEGTargets.cmake)
  # This is an install tree
  include(${SELF_DIR}/OpenJPEGTargets.cmake)
  get_filename_component(OPENJPEG_INCLUDE_ROOT "${SELF_DIR}/../../../include/ITK-5.2/gdcmopenjpeg" ABSOLUTE)
  set(OPENJPEG_INCLUDE_DIRS ${OPENJPEG_INCLUDE_ROOT})

else()
  if(EXISTS ${SELF_DIR}/OpenJPEGExports.cmake)
    # This is a build tree
    set( OPENJPEG_INCLUDE_DIRS )

    include(${SELF_DIR}/OpenJPEGExports.cmake)

  else()
    message(FATAL_ERROR "ooops")
  endif()
endif()

set(OPENJPEG_USE_FILE ${SELF_DIR}/UseOPENJPEG.cmake)

# Backward compatible part:
set(OPENJPEG_FOUND       TRUE)

