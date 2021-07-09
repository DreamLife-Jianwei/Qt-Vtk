set(vtkIOParallel_LOADED 1)
set(vtkIOParallel_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMisc;vtkCommonSystem;vtkFiltersCore;vtkFiltersExtraction;vtkFiltersParallel;vtkIOCore;vtkIOGeometry;vtkIOImage;vtkIOLegacy;vtkIONetCDF;vtkParallelCore;vtkexodusII;vtkjsoncpp;vtknetcdf;vtksys")
set(vtkIOParallel_LIBRARIES "vtkIOParallel")
set(vtkIOParallel_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkIOParallel_LIBRARY_DIRS "")
set(vtkIOParallel_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIOParallel_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOParallelHierarchy.txt")
set(vtkIOParallel_KIT "vtkParallel")
set(vtkIOParallel_TARGETS_FILE "")


