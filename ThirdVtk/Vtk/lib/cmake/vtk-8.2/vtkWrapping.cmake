# This file ensures that any module that should be wrapped has the
# vtkWrapHierarchy command executed on it, and also dispatches to the language
# specific wrapping for each module.

# First, ensure we include the correct CMake code so that we can wrap.
if(VTK_WRAP_PYTHON)
#  include(vtkPythonWrapping)
endif()
if(VTK_WRAP_JAVA)
  include(vtkJavaWrapping)
endif()

include(vtkWrapHierarchy)

# This is the main function, always called from the vtk_module_library function
# when a new module library is added.
function(vtk_add_wrapping module_name module_srcs module_hdrs)
  if(NOT ${module_name}_EXCLUDE_FROM_WRAPPING)
    set(_wrap_module FALSE)
    if(VTK_WRAP_PYTHON OR VTK_WRAP_JAVA OR VTK_WRAP_HIERARCHY)
      set(_wrap_module TRUE)
    endif()

    if(_wrap_module)
      # The list of include dirs to pass to wrapper tool command lines
      set(VTK_WRAP_INCLUDE_DIRS)
      if(${vtk-module}_DEPENDS_INCLUDE_DIRS)
        list(APPEND VTK_WRAP_INCLUDE_DIRS ${${vtk-module}_DEPENDS_INCLUDE_DIRS})
      endif()
      if(${vtk-module}_INCLUDE_DIRS)
        list(APPEND VTK_WRAP_INCLUDE_DIRS ${${vtk-module}_INCLUDE_DIRS})
      endif()
      if(${vtk-module}_SYSTEM_INCLUDE_DIRS)
        list(APPEND VTK_WRAP_INCLUDE_DIRS ${${vtk-module}_SYSTEM_INCLUDE_DIRS})
      endif()

      # The module is wrapped by at least one language - invoke wrap hierarchy.
      if(NOT ${module_name}_EXCLUDE_FROM_WRAP_HIERARCHY)
        set(_all_files ${module_srcs} ${modules_hdrs})
        vtk_wrap_hierarchy(${module_name} ${VTK_MODULES_DIR}
          "${_all_files}")
        set (${module_name}_WRAP_HIERARCHY_FILE
          "${VTK_MODULES_DIR}/${module_name}Hierarchy.txt"
          PARENT_SCOPE)
        set (${module_name}_WRAP_HIERARCHY_FILE
          "${VTK_MODULES_DIR}/${module_name}Hierarchy.txt")
      endif()

      # Now to wrap the languages that are on.
      if(VTK_WRAP_PYTHON AND NOT ${module_name}_EXCLUDE_FROM_PYTHON_WRAPPING)
        # Note that the module should be Python wrapped.
        set_property(GLOBAL APPEND PROPERTY VTK_PYTHON_WRAPPED ${module_name})
      endif()
      if(VTK_WRAP_JAVA AND NOT ${module_name}_EXCLUDE_FROM_JAVA_WRAPPING)
        set_property(GLOBAL APPEND PROPERTY VTK_JAVA_WRAPPED ${module_name})
        vtk_add_java_wrapping(${module_name} "${module_srcs}" "${module_hdrs}")
      endif()
    endif()
  endif()
endfunction()
