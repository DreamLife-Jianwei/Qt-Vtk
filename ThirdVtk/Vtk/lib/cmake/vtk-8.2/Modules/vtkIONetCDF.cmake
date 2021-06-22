set(vtkIONetCDF_LOADED 1)
set(vtkIONetCDF_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtknetcdf;vtksys")
set(vtkIONetCDF_LIBRARIES "vtkIONetCDF")
set(vtkIONetCDF_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkIONetCDF_LIBRARY_DIRS "")
set(vtkIONetCDF_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIONetCDF_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIONetCDFHierarchy.txt")
set(vtkIONetCDF_KIT "vtkIO")
set(vtkIONetCDF_TARGETS_FILE "")


