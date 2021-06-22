set(vtkIOImage_LOADED 1)
set(vtkIOImage_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkCommonMath;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkDICOMParser;vtkMetaIO;vtkjpeg;vtkpng;vtksys;vtktiff;vtkzlib")
set(vtkIOImage_LIBRARIES "vtkIOImage")
set(vtkIOImage_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-8.2")
set(vtkIOImage_LIBRARY_DIRS "")
set(vtkIOImage_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkIOImage_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkIOImageHierarchy.txt")
set(vtkIOImage_KIT "vtkIO")
set(vtkIOImage_TARGETS_FILE "")


