set(ITKVtkGlue_LOADED 1)
set(ITKVtkGlue_ENABLE_SHARED "1")
set(ITKVtkGlue_DEPENDS "ITKCommon;ITKImageIntensity;ITKVTK")
set(ITKVtkGlue_PUBLIC_DEPENDS "ITKCommon;ITKVTK")
set(ITKVtkGlue_TRANSITIVE_DEPENDS "ITKCommon;ITKImageIntensity;ITKVTK")
set(ITKVtkGlue_PRIVATE_DEPENDS "")
set(ITKVtkGlue_LIBRARIES "ITKVtkGlue")
set(ITKVtkGlue_INCLUDE_DIRS "${ITK_INSTALL_PREFIX}/include/ITK-5.2;C:/Dev/VTK/Bin/include/vtk-8.2")
set(ITKVtkGlue_LIBRARY_DIRS "")
set(ITKVtkGlue_RUNTIME_LIBRARY_DIRS "${ITK_INSTALL_PREFIX}/bin")
set(ITKVtkGlue_TARGETS_FILE "")
set(ITKVtkGlue_FACTORY_NAMES "")

set(VTK_DIR "C:/Dev/VTK/Bin/lib/cmake/vtk-8.2")

find_package(VTK NO_MODULE REQUIRED)

  if(NOT COMMAND vtk_module_config)
    macro(vtk_module_config ns)
       foreach(arg ${ARGN})
        if(${arg} MATCHES "^[Vv][Tt][Kk]")
          string(REGEX REPLACE "^[Vv][Tt][Kk]" "" _arg ${arg})
        else()
          set(_arg ${arg})
        endif()
        set(${ns}_LIBRARIES ${${ns}_LIBRARIES} VTK::${_arg})
       endforeach()
    endmacro()
  endif()

if(NOT VTK_VERSION)
  set(VTK_VERSION "8.2.0")
endif()
if(NOT VTK_RENDERING_BACKEND)
  if(NOT COMMAND vtk_module_config)
    set(VTK_RENDERING_BACKEND OpenGL2)
  else()
    set(VTK_RENDERING_BACKEND OpenGL)
  endif()
endif()
set(_target_freetypeopengl)
if(TARGET vtkRenderingFreeTypeOpenGL2)
  set(_target_freetypeopengl vtkRenderingFreeTypeOpenGL2)
endif()

set(_required_vtk_libraries
  vtkIOImage
  vtkImagingSources
  )
if(ITK_WRAP_PYTHON)
  list(APPEND _required_vtk_libraries vtkWrappingPythonCore)
endif()
if(NOT VTK_RENDERING_BACKEND STREQUAL "None")
  list(APPEND _required_vtk_libraries
    vtkRenderingOpenGL2
    vtkRenderingFreeType
    
    vtkInteractionStyle
    vtkInteractionWidgets
  )
endif()
if(8.2.0 VERSION_LESS 6.0.0)
  set(ITKVtkGlue_VTK_INCLUDE_DIRS C:/Dev/VTK/Bin/include/vtk-8.2)
  set(ITKVtkGlue_VTK_LIBRARIES vtksys;vtkCommonCore;vtkCommonMath;vtkCommonMisc;vtkCommonSystem;vtkCommonTransforms;vtkCommonDataModel;vtkCommonColor;vtkCommonExecutionModel;vtkCommonComputationalGeometry;vtkFiltersCore;vtkFiltersGeneral;vtkImagingCore;vtkImagingFourier;vtkFiltersStatistics;vtkFiltersExtraction;vtkInfovisCore;vtkFiltersGeometry;vtkFiltersSources;vtkRenderingCore;vtkzlib;vtkfreetype;vtkRenderingFreeType;vtkRenderingContext2D;vtkChartsCore;vtkDICOMParser;vtkdoubleconversion;vtklz4;vtklzma;vtkIOCore;vtkIOLegacy;vtkexpat;vtkIOXMLParser;vtkDomainsChemistry;vtkglew;vtkRenderingOpenGL2;vtkDomainsChemistryOpenGL2;vtkIOXML;vtkParallelCore;vtkFiltersAMR;vtkFiltersFlowPaths;vtkFiltersGeneric;vtkImagingSources;vtkFiltersHybrid;vtkFiltersHyperTree;vtkImagingGeneral;vtkFiltersImaging;vtkFiltersModeling;vtkFiltersParallel;vtkFiltersParallelImaging;vtkFiltersPoints;vtkFiltersProgrammable;vtkFiltersSMP;vtkFiltersSelection;vtkFiltersTexture;vtkFiltersTopology;verdict;vtkFiltersVerdict;vtkInteractionStyle;vtkGUISupportQt;vtksqlite;vtkIOSQL;vtkGUISupportQtSQL;vtkmetaio;vtkjpeg;vtkpng;vtktiff;vtkIOImage;vtkImagingHybrid;vtkInfovisLayout;vtkImagingColor;vtkRenderingAnnotation;vtkRenderingVolume;vtkInteractionWidgets;vtkViewsCore;vtklibproj;vtkGeovisCore;vtkhdf5_src;vtkhdf5_hl_src;vtkIOAMR;vtkIOAsynchronous;vtkpugixml;vtkIOCityGML;vtkIOEnSight;vtknetcdf;vtkexodusII;vtkIOExodus;vtkgl2ps;vtkRenderingGL2PSOpenGL2;vtkIOExport;vtkIOExportOpenGL2;vtklibharu;vtkIOExportPDF;vtkIOGeometry;vtkIOImport;vtklibxml2;vtkIOInfovis;vtkIOLSDyna;vtkIOMINC;vtkogg;vtktheora;vtkIOMovie;vtkIONetCDF;vtkIOPLY;vtkjsoncpp;vtkIOParallel;vtkIOParallelXML;vtkIOSegY;vtkIOTecplotTable;vtkIOVeraOut;vtkIOVideo;vtkImagingMath;vtkImagingMorphological;vtkImagingStatistics;vtkImagingStencil;vtkInteractionImage;vtkRenderingContextOpenGL2;vtkRenderingImage;vtkRenderingLOD;vtkRenderingLabel;vtkRenderingQt;vtkRenderingVolumeOpenGL2;vtkViewsContext2D;vtkViewsInfovis;vtkViewsQt)
else()
  vtk_module_config(ITKVtkGlue_VTK
    ${_required_vtk_libraries}
    )
  set(ITKVtkGlue_VTK_LIBRARIES ${_required_vtk_libraries})
  set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS ${ITKVtkGlue_VTK_DEFINITIONS})
endif()

