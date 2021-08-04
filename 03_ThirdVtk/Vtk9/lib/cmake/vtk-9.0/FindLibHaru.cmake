find_path(LibHaru_INCLUDE_DIR
  NAMES hpdf.h
  DOC "libharu include directory")
mark_as_advanced(LibHaru_INCLUDE_DIR)

find_library(LibHaru_LIBRARY_RELEASE
  NAMES hpdf hpdfs libhpdf libhpdfs
  DOC "libharu release library")
mark_as_advanced(LibHaru_LIBRARY_RELEASE)
find_library(LibHaru_LIBRARY_DEBUG
  NAMES hpdfd hpdfsd libhpdfd libhpdfsd
  DOC "libharu debug library")
mark_as_advanced(LibHaru_LIBRARY_DEBUG)

if (LibHaru_INCLUDE_DIR)
  file(STRINGS "${LibHaru_INCLUDE_DIR}/hpdf_version.h" _libharu_version_lines
    REGEX "#define HPDF_(MAJOR|MINOR|BUGFIX|EXTRA)_VERSION")
  string(REGEX REPLACE ".*HPDF_MAJOR_VERSION *\([0-9]*\).*" "\\1" _libharu_version_major "${_libharu_version_lines}")
  string(REGEX REPLACE ".*HPDF_MINOR_VERSION *\([0-9]*\).*" "\\1" _libharu_version_minor "${_libharu_version_lines}")
  string(REGEX REPLACE ".*HPDF_BUGFIX_VERSION *\([0-9]*\).*" "\\1" _libharu_version_bugfix "${_libharu_version_lines}")
  string(REGEX REPLACE ".*HPDF_EXTRA_VERSION *\"\([^\"]*\)\".*" "\\1" _libharu_version_extra "${_libharu_version_lines}")
  set(LibHaru_VERSION "${_libharu_version_major}.${_libharu_version_minor}.${_libharu_version_bugfix}")
  if (_libharu_version_extra)
    string(APPEND LibHaru_VERSION
      "-${_libharu_version_extra}")
  endif ()
  unset(_libharu_version_major)
  unset(_libharu_version_minor)
  unset(_libharu_version_bugfix)
  unset(_libharu_version_extra)
  unset(_libharu_version_lines)
endif ()

include(SelectLibraryConfigurations)
select_library_configurations(LibHaru)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibHaru
  REQUIRED_VARS LibHaru_LIBRARY LibHaru_INCLUDE_DIR
  VERSION_VAR LibHaru_VERSION)

if (LibHaru_FOUND)
  set(LibHaru_INCLUDE_DIRS "${LibHaru_INCLUDE_DIR}")
  set(LibHaru_LIBRARIES "${LibHaru_LIBRARY}")

  if (NOT TARGET LibHaru::LibHaru)
    include(vtkDetectLibraryType)
    set(libharu_library_type UNKNOWN)
    if (LibHaru_LIBRARY_RELEASE)
      vtk_detect_library_type(libharu_release_library_type
        PATH "${LibHaru_LIBRARY_RELEASE}")
    endif ()
    if (LibHaru_LIBRARY_DEBUG)
      vtk_detect_library_type(libharu_debug_library_type
        PATH "${LibHaru_LIBRARY_DEBUG}")
    endif ()
    if (libharu_release_library_type AND libharu_debug_library_type)
      if (libharu_release_library_type STREQUAL libharu_debug_library_type)
        set(libharu_library_type "${libharu_release_library_type}")
      endif ()
    elseif (libharu_release_library_type)
      set(libharu_library_type "${libharu_release_library_type}")
    elseif (libharu_debug_library_type)
      set(libharu_library_type "${libharu_debug_library_type}")
    endif ()
    add_library(LibHaru::LibHaru "${libharu_library_type}" IMPORTED)
    unset(libharu_release_library_type)
    unset(libharu_debug_library_type)
    unset(libharu_library_type)
    set_target_properties(LibHaru::LibHaru PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${LibHaru_INCLUDE_DIR}")
    if (LibHaru_LIBRARY_RELEASE)
      set_property(TARGET LibHaru::LibHaru APPEND PROPERTY
        IMPORTED_CONFIGURATIONS RELEASE)
      set_target_properties(LibHaru::LibHaru PROPERTIES
        IMPORTED_LOCATION_RELEASE "${LibHaru_LIBRARY_RELEASE}"
        IMPORTED_IMPLIB_RELEASE "${LibHaru_LIBRARY_RELEASE}")
    endif ()
    if (LibHaru_LIBRARY_DEBUG)
      set_property(TARGET LibHaru::LibHaru APPEND PROPERTY
        IMPORTED_CONFIGURATIONS DEBUG)
      set_target_properties(LibHaru::LibHaru PROPERTIES
        IMPORTED_LOCATION_DEBUG "${LibHaru_LIBRARY_DEBUG}"
        IMPORTED_IMPLIB_DEBUG "${LibHaru_LIBRARY_DEBUG}")
    endif ()
  endif ()
endif ()
