set(_vtk_module_find_package_quiet)
if (${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
  set(_vtk_module_find_package_quiet QUIET)
endif ()

set(_vtk_module_find_package_components_checked)
set(_vtk_module_find_package_components_to_check
  ${${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS})
set(_vtk_module_find_package_components)
set(_vtk_module_find_package_components_required)
while (_vtk_module_find_package_components_to_check)
  list(GET _vtk_module_find_package_components_to_check 0 _vtk_module_component)
  list(REMOVE_AT _vtk_module_find_package_components_to_check 0)
  if (_vtk_module_component IN_LIST _vtk_module_find_package_components_checked)
    continue ()
  endif ()
  list(APPEND _vtk_module_find_package_components_checked
    "${_vtk_module_component}")

  list(APPEND _vtk_module_find_package_components
    "${_vtk_module_component}")
  if (${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_vtk_module_component})
    list(APPEND _vtk_module_find_package_components_required
      "${_vtk_module_component}")
  endif ()

  if (TARGET "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_module_component}")
    set(_vtk_module_find_package_component_target "${CMAKE_FIND_PACKAGE_NAME}::${_vtk_module_component}")
  elseif (TARGET "${_vtk_module_component}")
    set(_vtk_module_find_package_component_target "${_vtk_module_component}")
  else ()
    # No such target for the component; skip.
    continue ()
  endif ()
  get_property(_vtk_module_find_package_depends
    TARGET    "${_vtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_vtk_module_depends")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_module_find_package_depends "${_vtk_module_find_package_depends}")
  list(APPEND _vtk_module_find_package_components_to_check
    ${_vtk_module_find_package_depends})
  get_property(_vtk_module_find_package_depends
    TARGET    "${_vtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_vtk_module_private_depends")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_module_find_package_depends "${_vtk_module_find_package_depends}")
  list(APPEND _vtk_module_find_package_components_to_check
    ${_vtk_module_find_package_depends})
  get_property(_vtk_module_find_package_depends
    TARGET    "${_vtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_vtk_module_optional_depends")
  foreach (_vtk_module_find_package_depend IN LISTS _vtk_module_find_package_depends)
    if (TARGET "${_vtk_module_find_package_depend}")
      string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_module_find_package_depend "${_vtk_module_find_package_depend}")
      list(APPEND _vtk_module_find_package_components_to_check
        "${_vtk_module_find_package_depend}")
    endif ()
  endforeach ()
  get_property(_vtk_module_find_package_depends
    TARGET    "${_vtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_vtk_module_forward_link")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_module_find_package_depends "${_vtk_module_find_package_depends}")
  list(APPEND _vtk_module_find_package_components_to_check
    ${_vtk_module_find_package_depends})

  get_property(_vtk_module_find_package_kit
    TARGET    "${_vtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_vtk_module_kit")
  if (_vtk_module_find_package_kit)
    get_property(_vtk_module_find_package_kit_modules
      TARGET    "${_vtk_module_find_package_kit}"
      PROPERTY  "INTERFACE_vtk_kit_kit_modules")
    string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _vtk_module_find_package_kit_modules "${_vtk_module_find_package_kit_modules}")
    list(APPEND _vtk_module_find_package_components_to_check
      ${_vtk_module_find_package_kit_modules})
  endif ()
endwhile ()
unset(_vtk_module_find_package_component_target)
unset(_vtk_module_find_package_components_to_check)
unset(_vtk_module_find_package_components_checked)
unset(_vtk_module_component)
unset(_vtk_module_find_package_depend)
unset(_vtk_module_find_package_depends)
unset(_vtk_module_find_package_kit)
unset(_vtk_module_find_package_kit_modules)

if (_vtk_module_find_package_components)
  list(REMOVE_DUPLICATES _vtk_module_find_package_components)
endif ()
if (_vtk_module_find_package_components_required)
  list(REMOVE_DUPLICATES _vtk_module_find_package_components_required)
endif ()

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("ViewsQt" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("ViewsQt" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Qt5
    5.14
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          Widgets
    OPTIONAL_COMPONENTS )
  if (NOT Qt5_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Qt5")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_ViewsQt_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_ViewsQt_NOT_FOUND_MESSAGE"
      "Failed to find the Qt5 package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("loguru" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("loguru" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_loguru_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_loguru_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("RenderingQt" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("RenderingQt" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Qt5
    5.14
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          Widgets
    OPTIONAL_COMPONENTS )
  if (NOT Qt5_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Qt5")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_RenderingQt_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_RenderingQt_NOT_FOUND_MESSAGE"
      "Failed to find the Qt5 package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("opengl" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("opengl" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(OpenGL
    
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          OpenGL
    OPTIONAL_COMPONENTS )
  if (NOT OpenGL_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: OpenGL")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_opengl_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_opengl_NOT_FOUND_MESSAGE"
      "Failed to find the OpenGL package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("exodusII" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("exodusII" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_exodusII_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_exodusII_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("GUISupportQtSQL" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("GUISupportQtSQL" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Qt5
    5.14
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          Widgets;Sql
    OPTIONAL_COMPONENTS )
  if (NOT Qt5_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Qt5")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_GUISupportQtSQL_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_GUISupportQtSQL_NOT_FOUND_MESSAGE"
      "Failed to find the Qt5 package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("GUISupportQt" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("GUISupportQt" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Qt5
    5.14
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          Widgets
    OPTIONAL_COMPONENTS )
  if (NOT Qt5_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Qt5")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_GUISupportQt_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_GUISupportQt_NOT_FOUND_MESSAGE"
      "Failed to find the Qt5 package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("CommonSystem" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("CommonSystem" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_CommonSystem_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_CommonSystem_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if ("CommonCore" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if ("CommonCore" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_vtk_module_find_package_quiet}
    ${_vtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_CommonCore_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_CommonCore_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)

unset(_vtk_module_find_package_components)
unset(_vtk_module_find_package_components_required)
unset(_vtk_module_find_package_quiet)
