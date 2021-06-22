set(vtkhdf5_LOADED 1)
set(vtkhdf5_DEPENDS "vtkzlib")
set(vtkhdf5_LIBRARIES "vtkhdf5_src;vtkhdf5_hl_src")
set(vtkhdf5_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkhdf5_LIBRARY_DIRS "")
set(vtkhdf5_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkhdf5_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkhdf5Hierarchy.txt")
set(vtkhdf5_KIT "")
set(vtkhdf5_TARGETS_FILE "")
set(vtkhdf5_EXCLUDE_FROM_WRAPPING 1)


