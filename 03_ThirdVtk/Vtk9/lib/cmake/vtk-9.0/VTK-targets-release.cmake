#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VTK::vtksys" for configuration "Release"
set_property(TARGET VTK::vtksys APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtksys PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtksys-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtksys-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtksys )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtksys "${_IMPORT_PREFIX}/lib/vtksys-9.0.lib" "${_IMPORT_PREFIX}/bin/vtksys-9.0.dll" )

# Import target "VTK::loguru" for configuration "Release"
set_property(TARGET VTK::loguru APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::loguru PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkloguru-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkloguru-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::loguru )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::loguru "${_IMPORT_PREFIX}/lib/vtkloguru-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkloguru-9.0.dll" )

# Import target "VTK::CommonCore" for configuration "Release"
set_property(TARGET VTK::CommonCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::loguru"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonCore "${_IMPORT_PREFIX}/lib/vtkCommonCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonCore-9.0.dll" )

# Import target "VTK::CommonMath" for configuration "Release"
set_property(TARGET VTK::CommonMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonMath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonMath-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonMath-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonMath "${_IMPORT_PREFIX}/lib/vtkCommonMath-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMath-9.0.dll" )

# Import target "VTK::CommonTransforms" for configuration "Release"
set_property(TARGET VTK::CommonTransforms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonTransforms PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonTransforms )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonTransforms "${_IMPORT_PREFIX}/lib/vtkCommonTransforms-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonTransforms-9.0.dll" )

# Import target "VTK::CommonMisc" for configuration "Release"
set_property(TARGET VTK::CommonMisc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonMisc PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonMisc-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonMisc-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonMisc )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonMisc "${_IMPORT_PREFIX}/lib/vtkCommonMisc-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonMisc-9.0.dll" )

# Import target "VTK::CommonSystem" for configuration "Release"
set_property(TARGET VTK::CommonSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonSystem PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonSystem-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonSystem-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonSystem "${_IMPORT_PREFIX}/lib/vtkCommonSystem-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonSystem-9.0.dll" )

# Import target "VTK::CommonDataModel" for configuration "Release"
set_property(TARGET VTK::CommonDataModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonDataModel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonDataModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonDataModel "${_IMPORT_PREFIX}/lib/vtkCommonDataModel-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonDataModel-9.0.dll" )

# Import target "VTK::CommonExecutionModel" for configuration "Release"
set_property(TARGET VTK::CommonExecutionModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonExecutionModel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonExecutionModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonExecutionModel "${_IMPORT_PREFIX}/lib/vtkCommonExecutionModel-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonExecutionModel-9.0.dll" )

# Import target "VTK::ImagingCore" for configuration "Release"
set_property(TARGET VTK::ImagingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonTransforms"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingCore "${_IMPORT_PREFIX}/lib/vtkImagingCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingCore-9.0.dll" )

# Import target "VTK::DICOMParser" for configuration "Release"
set_property(TARGET VTK::DICOMParser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DICOMParser PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDICOMParser-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDICOMParser-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DICOMParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DICOMParser "${_IMPORT_PREFIX}/lib/vtkDICOMParser-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkDICOMParser-9.0.dll" )

# Import target "VTK::jpeg" for configuration "Release"
set_property(TARGET VTK::jpeg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::jpeg PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkjpeg-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkjpeg-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::jpeg )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::jpeg "${_IMPORT_PREFIX}/lib/vtkjpeg-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkjpeg-9.0.dll" )

# Import target "VTK::zlib" for configuration "Release"
set_property(TARGET VTK::zlib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::zlib PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkzlib-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkzlib-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::zlib )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::zlib "${_IMPORT_PREFIX}/lib/vtkzlib-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkzlib-9.0.dll" )

# Import target "VTK::metaio" for configuration "Release"
set_property(TARGET VTK::metaio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::metaio PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkmetaio-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkmetaio-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::metaio )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::metaio "${_IMPORT_PREFIX}/lib/vtkmetaio-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkmetaio-9.0.dll" )

# Import target "VTK::png" for configuration "Release"
set_property(TARGET VTK::png APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::png PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkpng-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkpng-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::png )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::png "${_IMPORT_PREFIX}/lib/vtkpng-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkpng-9.0.dll" )

# Import target "VTK::pugixml" for configuration "Release"
set_property(TARGET VTK::pugixml APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::pugixml PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkpugixml-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkpugixml-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::pugixml )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::pugixml "${_IMPORT_PREFIX}/lib/vtkpugixml-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkpugixml-9.0.dll" )

# Import target "VTK::tiff" for configuration "Release"
set_property(TARGET VTK::tiff APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::tiff PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtktiff-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::jpeg;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtktiff-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::tiff )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::tiff "${_IMPORT_PREFIX}/lib/vtktiff-9.0.lib" "${_IMPORT_PREFIX}/bin/vtktiff-9.0.dll" )

# Import target "VTK::IOImage" for configuration "Release"
set_property(TARGET VTK::IOImage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOImage PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOImage-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::DICOMParser;VTK::jpeg;VTK::metaio;VTK::png;VTK::pugixml;VTK::tiff;VTK::vtksys;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOImage-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOImage "${_IMPORT_PREFIX}/lib/vtkIOImage-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOImage-9.0.dll" )

# Import target "VTK::doubleconversion" for configuration "Release"
set_property(TARGET VTK::doubleconversion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::doubleconversion PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::doubleconversion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::doubleconversion "${_IMPORT_PREFIX}/lib/vtkdoubleconversion-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkdoubleconversion-9.0.dll" )

# Import target "VTK::lz4" for configuration "Release"
set_property(TARGET VTK::lz4 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::lz4 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklz4-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklz4-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::lz4 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::lz4 "${_IMPORT_PREFIX}/lib/vtklz4-9.0.lib" "${_IMPORT_PREFIX}/bin/vtklz4-9.0.dll" )

# Import target "VTK::lzma" for configuration "Release"
set_property(TARGET VTK::lzma APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::lzma PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklzma-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklzma-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::lzma )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::lzma "${_IMPORT_PREFIX}/lib/vtklzma-9.0.lib" "${_IMPORT_PREFIX}/bin/vtklzma-9.0.dll" )

# Import target "VTK::IOCore" for configuration "Release"
set_property(TARGET VTK::IOCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::doubleconversion;VTK::lz4;VTK::lzma;VTK::vtksys;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOCore "${_IMPORT_PREFIX}/lib/vtkIOCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOCore-9.0.dll" )

# Import target "VTK::DICOM" for configuration "Release"
set_property(TARGET VTK::DICOM APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DICOM PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDICOM-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::ImagingCore;VTK::IOCore;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDICOM-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DICOM )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DICOM "${_IMPORT_PREFIX}/lib/vtkDICOM-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkDICOM-9.0.dll" )

# Import target "VTK::WrappingTools" for configuration "Release"
set_property(TARGET VTK::WrappingTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrappingTools PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkWrappingTools-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrappingTools-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrappingTools )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrappingTools "${_IMPORT_PREFIX}/lib/vtkWrappingTools-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkWrappingTools-9.0.dll" )

# Import target "VTK::WrapHierarchy" for configuration "Release"
set_property(TARGET VTK::WrapHierarchy APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapHierarchy PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapHierarchy-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapHierarchy )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapHierarchy "${_IMPORT_PREFIX}/bin/vtkWrapHierarchy-9.0.exe" )

# Import target "VTK::WrapPython" for configuration "Release"
set_property(TARGET VTK::WrapPython APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapPython PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapPython-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapPython )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapPython "${_IMPORT_PREFIX}/bin/vtkWrapPython-9.0.exe" )

# Import target "VTK::WrapPythonInit" for configuration "Release"
set_property(TARGET VTK::WrapPythonInit APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapPythonInit PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapPythonInit-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapPythonInit )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapPythonInit "${_IMPORT_PREFIX}/bin/vtkWrapPythonInit-9.0.exe" )

# Import target "VTK::ParseJava" for configuration "Release"
set_property(TARGET VTK::ParseJava APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParseJava PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParseJava-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParseJava )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParseJava "${_IMPORT_PREFIX}/bin/vtkParseJava-9.0.exe" )

# Import target "VTK::WrapJava" for configuration "Release"
set_property(TARGET VTK::WrapJava APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::WrapJava PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkWrapJava-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::WrapJava )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::WrapJava "${_IMPORT_PREFIX}/bin/vtkWrapJava-9.0.exe" )

# Import target "VTK::FiltersCore" for configuration "Release"
set_property(TARGET VTK::FiltersCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersCore "${_IMPORT_PREFIX}/lib/vtkFiltersCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersCore-9.0.dll" )

# Import target "VTK::CommonColor" for configuration "Release"
set_property(TARGET VTK::CommonColor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonColor PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonColor-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonColor-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonColor "${_IMPORT_PREFIX}/lib/vtkCommonColor-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonColor-9.0.dll" )

# Import target "VTK::CommonComputationalGeometry" for configuration "Release"
set_property(TARGET VTK::CommonComputationalGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::CommonComputationalGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::CommonComputationalGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::CommonComputationalGeometry "${_IMPORT_PREFIX}/lib/vtkCommonComputationalGeometry-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkCommonComputationalGeometry-9.0.dll" )

# Import target "VTK::FiltersGeneral" for configuration "Release"
set_property(TARGET VTK::FiltersGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersGeneral PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersGeneral "${_IMPORT_PREFIX}/lib/vtkFiltersGeneral-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeneral-9.0.dll" )

# Import target "VTK::FiltersGeometry" for configuration "Release"
set_property(TARGET VTK::FiltersGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersGeometry "${_IMPORT_PREFIX}/lib/vtkFiltersGeometry-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeometry-9.0.dll" )

# Import target "VTK::FiltersSources" for configuration "Release"
set_property(TARGET VTK::FiltersSources APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersSources PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersSources-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonCore;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersSources-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersSources "${_IMPORT_PREFIX}/lib/vtkFiltersSources-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSources-9.0.dll" )

# Import target "VTK::RenderingCore" for configuration "Release"
set_property(TARGET VTK::RenderingCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonColor;VTK::CommonComputationalGeometry;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::FiltersSources;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingCore "${_IMPORT_PREFIX}/lib/vtkRenderingCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingCore-9.0.dll" )

# Import target "VTK::RenderingUI" for configuration "Release"
set_property(TARGET VTK::RenderingUI APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingUI PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingUI-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingUI-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingUI )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingUI "${_IMPORT_PREFIX}/lib/vtkRenderingUI-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingUI-9.0.dll" )

# Import target "VTK::glew" for configuration "Release"
set_property(TARGET VTK::glew APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::glew PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkglew-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkglew-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::glew )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::glew "${_IMPORT_PREFIX}/lib/vtkglew-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkglew-9.0.dll" )

# Import target "VTK::vtkTestOpenGLVersion" for configuration "Release"
set_property(TARGET VTK::vtkTestOpenGLVersion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkTestOpenGLVersion PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkTestOpenGLVersion-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkTestOpenGLVersion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkTestOpenGLVersion "${_IMPORT_PREFIX}/bin/vtkTestOpenGLVersion-9.0.exe" )

# Import target "VTK::RenderingOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonExecutionModel;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingOpenGL2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingOpenGL2-9.0.dll" )

# Import target "VTK::vtkProbeOpenGLVersion" for configuration "Release"
set_property(TARGET VTK::vtkProbeOpenGLVersion APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkProbeOpenGLVersion PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkProbeOpenGLVersion-9.0.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkProbeOpenGLVersion )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkProbeOpenGLVersion "${_IMPORT_PREFIX}/bin/vtkProbeOpenGLVersion-9.0.exe" )

# Import target "VTK::ImagingSources" for configuration "Release"
set_property(TARGET VTK::ImagingSources APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingSources PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingSources-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingSources-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingSources )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingSources "${_IMPORT_PREFIX}/lib/vtkImagingSources-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingSources-9.0.dll" )

# Import target "VTK::FiltersHybrid" for configuration "Release"
set_property(TARGET VTK::FiltersHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersHybrid PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonMisc;VTK::FiltersCore;VTK::FiltersGeneral;VTK::ImagingCore;VTK::ImagingSources;VTK::RenderingCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersHybrid "${_IMPORT_PREFIX}/lib/vtkFiltersHybrid-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersHybrid-9.0.dll" )

# Import target "VTK::FiltersModeling" for configuration "Release"
set_property(TARGET VTK::FiltersModeling APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersModeling PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersModeling )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersModeling "${_IMPORT_PREFIX}/lib/vtkFiltersModeling-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersModeling-9.0.dll" )

# Import target "VTK::ImagingColor" for configuration "Release"
set_property(TARGET VTK::ImagingColor APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingColor PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingColor-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingColor-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingColor )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingColor "${_IMPORT_PREFIX}/lib/vtkImagingColor-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingColor-9.0.dll" )

# Import target "VTK::ImagingGeneral" for configuration "Release"
set_property(TARGET VTK::ImagingGeneral APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingGeneral PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingGeneral )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingGeneral "${_IMPORT_PREFIX}/lib/vtkImagingGeneral-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingGeneral-9.0.dll" )

# Import target "VTK::ImagingHybrid" for configuration "Release"
set_property(TARGET VTK::ImagingHybrid APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingHybrid PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::IOImage;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingHybrid )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingHybrid "${_IMPORT_PREFIX}/lib/vtkImagingHybrid-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingHybrid-9.0.dll" )

# Import target "VTK::ImagingFourier" for configuration "Release"
set_property(TARGET VTK::ImagingFourier APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingFourier PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingFourier-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingFourier-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingFourier )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingFourier "${_IMPORT_PREFIX}/lib/vtkImagingFourier-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingFourier-9.0.dll" )

# Import target "VTK::FiltersStatistics" for configuration "Release"
set_property(TARGET VTK::FiltersStatistics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersStatistics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::ImagingFourier"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersStatistics )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersStatistics "${_IMPORT_PREFIX}/lib/vtkFiltersStatistics-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersStatistics-9.0.dll" )

# Import target "VTK::IOLegacy" for configuration "Release"
set_property(TARGET VTK::IOLegacy APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOLegacy PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOLegacy-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOLegacy-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOLegacy )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOLegacy "${_IMPORT_PREFIX}/lib/vtkIOLegacy-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOLegacy-9.0.dll" )

# Import target "VTK::ParallelCore" for configuration "Release"
set_property(TARGET VTK::ParallelCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParallelCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkParallelCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonSystem;VTK::IOLegacy;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParallelCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParallelCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParallelCore "${_IMPORT_PREFIX}/lib/vtkParallelCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkParallelCore-9.0.dll" )

# Import target "VTK::expat" for configuration "Release"
set_property(TARGET VTK::expat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::expat PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkexpat-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkexpat-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::expat )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::expat "${_IMPORT_PREFIX}/lib/vtkexpat-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkexpat-9.0.dll" )

# Import target "VTK::IOXMLParser" for configuration "Release"
set_property(TARGET VTK::IOXMLParser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOXMLParser PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::IOCore;VTK::expat;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOXMLParser )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOXMLParser "${_IMPORT_PREFIX}/lib/vtkIOXMLParser-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOXMLParser-9.0.dll" )

# Import target "VTK::IOXML" for configuration "Release"
set_property(TARGET VTK::IOXML APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOXML PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOXML-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::CommonSystem;VTK::IOCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOXML-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOXML )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOXML "${_IMPORT_PREFIX}/lib/vtkIOXML-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOXML-9.0.dll" )

# Import target "VTK::ParallelDIY" for configuration "Release"
set_property(TARGET VTK::ParallelDIY APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ParallelDIY PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkParallelDIY-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersGeneral;VTK::IOXML"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkParallelDIY-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ParallelDIY )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ParallelDIY "${_IMPORT_PREFIX}/lib/vtkParallelDIY-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkParallelDIY-9.0.dll" )

# Import target "VTK::FiltersExtraction" for configuration "Release"
set_property(TARGET VTK::FiltersExtraction APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersExtraction PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersCore;VTK::FiltersStatistics;VTK::ParallelDIY"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersExtraction )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersExtraction "${_IMPORT_PREFIX}/lib/vtkFiltersExtraction-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersExtraction-9.0.dll" )

# Import target "VTK::InteractionStyle" for configuration "Release"
set_property(TARGET VTK::InteractionStyle APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InteractionStyle PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonMath;VTK::CommonTransforms;VTK::FiltersExtraction;VTK::FiltersSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InteractionStyle )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InteractionStyle "${_IMPORT_PREFIX}/lib/vtkInteractionStyle-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionStyle-9.0.dll" )

# Import target "VTK::freetype" for configuration "Release"
set_property(TARGET VTK::freetype APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::freetype PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkfreetype-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkfreetype-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::freetype )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::freetype "${_IMPORT_PREFIX}/lib/vtkfreetype-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkfreetype-9.0.dll" )

# Import target "VTK::RenderingFreeType" for configuration "Release"
set_property(TARGET VTK::RenderingFreeType APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingFreeType PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingFreeType )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingFreeType "${_IMPORT_PREFIX}/lib/vtkRenderingFreeType-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingFreeType-9.0.dll" )

# Import target "VTK::RenderingAnnotation" for configuration "Release"
set_property(TARGET VTK::RenderingAnnotation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingAnnotation PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::ImagingColor;VTK::RenderingFreeType"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingAnnotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingAnnotation "${_IMPORT_PREFIX}/lib/vtkRenderingAnnotation-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingAnnotation-9.0.dll" )

# Import target "VTK::RenderingVolume" for configuration "Release"
set_property(TARGET VTK::RenderingVolume APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVolume PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVolume )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVolume "${_IMPORT_PREFIX}/lib/vtkRenderingVolume-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolume-9.0.dll" )

# Import target "VTK::InteractionWidgets" for configuration "Release"
set_property(TARGET VTK::InteractionWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InteractionWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonDataModel;VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersHybrid;VTK::FiltersModeling;VTK::ImagingColor;VTK::ImagingCore;VTK::ImagingGeneral;VTK::ImagingHybrid;VTK::InteractionStyle;VTK::RenderingAnnotation;VTK::RenderingFreeType;VTK::RenderingVolume"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InteractionWidgets )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InteractionWidgets "${_IMPORT_PREFIX}/lib/vtkInteractionWidgets-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionWidgets-9.0.dll" )

# Import target "VTK::GUISupportQt" for configuration "Release"
set_property(TARGET VTK::GUISupportQt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::GUISupportQt PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersExtraction;VTK::InteractionStyle"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::GUISupportQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::GUISupportQt "${_IMPORT_PREFIX}/lib/vtkGUISupportQt-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkGUISupportQt-9.0.dll" )

# Import target "VTK::ViewsCore" for configuration "Release"
set_property(TARGET VTK::ViewsCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ViewsCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkViewsCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::FiltersGeneral;VTK::RenderingCore;VTK::RenderingUI"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkViewsCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ViewsCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ViewsCore "${_IMPORT_PREFIX}/lib/vtkViewsCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkViewsCore-9.0.dll" )

# Import target "VTK::RenderingContext2D" for configuration "Release"
set_property(TARGET VTK::RenderingContext2D APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingContext2D PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::RenderingFreeType"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingContext2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingContext2D "${_IMPORT_PREFIX}/lib/vtkRenderingContext2D-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingContext2D-9.0.dll" )

# Import target "VTK::InfovisCore" for configuration "Release"
set_property(TARGET VTK::InfovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InfovisCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInfovisCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersExtraction;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInfovisCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InfovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InfovisCore "${_IMPORT_PREFIX}/lib/vtkInfovisCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisCore-9.0.dll" )

# Import target "VTK::ChartsCore" for configuration "Release"
set_property(TARGET VTK::ChartsCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ChartsCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkChartsCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonColor;VTK::CommonExecutionModel;VTK::CommonTransforms;VTK::InfovisCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkChartsCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ChartsCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ChartsCore "${_IMPORT_PREFIX}/lib/vtkChartsCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkChartsCore-9.0.dll" )

# Import target "VTK::FiltersImaging" for configuration "Release"
set_property(TARGET VTK::FiltersImaging APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersImaging PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersImaging-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonSystem;VTK::ImagingGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersImaging-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersImaging )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersImaging "${_IMPORT_PREFIX}/lib/vtkFiltersImaging-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersImaging-9.0.dll" )

# Import target "VTK::InfovisLayout" for configuration "Release"
set_property(TARGET VTK::InfovisLayout APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InfovisLayout PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersModeling;VTK::FiltersSources;VTK::ImagingHybrid;VTK::InfovisCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InfovisLayout )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InfovisLayout "${_IMPORT_PREFIX}/lib/vtkInfovisLayout-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkInfovisLayout-9.0.dll" )

# Import target "VTK::RenderingLabel" for configuration "Release"
set_property(TARGET VTK::RenderingLabel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingLabel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingLabel-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingLabel-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingLabel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingLabel "${_IMPORT_PREFIX}/lib/vtkRenderingLabel-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingLabel-9.0.dll" )

# Import target "VTK::ViewsInfovis" for configuration "Release"
set_property(TARGET VTK::ViewsInfovis APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ViewsInfovis PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkViewsInfovis-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::ChartsCore;VTK::CommonColor;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersExtraction;VTK::FiltersGeneral;VTK::FiltersGeometry;VTK::FiltersImaging;VTK::FiltersModeling;VTK::FiltersSources;VTK::FiltersStatistics;VTK::ImagingGeneral;VTK::InfovisCore;VTK::InfovisLayout;VTK::InteractionWidgets;VTK::RenderingAnnotation;VTK::RenderingCore;VTK::RenderingLabel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkViewsInfovis-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ViewsInfovis )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ViewsInfovis "${_IMPORT_PREFIX}/lib/vtkViewsInfovis-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkViewsInfovis-9.0.dll" )

# Import target "VTK::ViewsQt" for configuration "Release"
set_property(TARGET VTK::ViewsQt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ViewsQt PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkViewsQt-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::FiltersExtraction;VTK::FiltersGeneral;VTK::InfovisCore;Qt5::Widgets"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkViewsQt-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ViewsQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ViewsQt "${_IMPORT_PREFIX}/lib/vtkViewsQt-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkViewsQt-9.0.dll" )

# Import target "VTK::ViewsContext2D" for configuration "Release"
set_property(TARGET VTK::ViewsContext2D APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ViewsContext2D PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkViewsContext2D-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::RenderingContext2D"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkViewsContext2D-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ViewsContext2D )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ViewsContext2D "${_IMPORT_PREFIX}/lib/vtkViewsContext2D-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkViewsContext2D-9.0.dll" )

# Import target "VTK::TestingRendering" for configuration "Release"
set_property(TARGET VTK::TestingRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::TestingRendering PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkTestingRendering-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonSystem;VTK::IOImage;VTK::ImagingCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkTestingRendering-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::TestingRendering )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::TestingRendering "${_IMPORT_PREFIX}/lib/vtkTestingRendering-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkTestingRendering-9.0.dll" )

# Import target "VTK::FiltersTexture" for configuration "Release"
set_property(TARGET VTK::FiltersTexture APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersTexture PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonTransforms;VTK::FiltersGeneral"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersTexture )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersTexture "${_IMPORT_PREFIX}/lib/vtkFiltersTexture-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersTexture-9.0.dll" )

# Import target "VTK::RenderingQt" for configuration "Release"
set_property(TARGET VTK::RenderingQt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingQt PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingQt-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonSystem;VTK::FiltersSources;VTK::FiltersTexture;VTK::GUISupportQt"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingQt-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingQt "${_IMPORT_PREFIX}/lib/vtkRenderingQt-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingQt-9.0.dll" )

# Import target "VTK::ImagingMath" for configuration "Release"
set_property(TARGET VTK::ImagingMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingMath PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingMath-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingMath-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingMath "${_IMPORT_PREFIX}/lib/vtkImagingMath-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingMath-9.0.dll" )

# Import target "VTK::RenderingVolumeOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingVolumeOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVolumeOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::glew;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVolumeOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVolumeOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingVolumeOpenGL2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVolumeOpenGL2-9.0.dll" )

# Import target "VTK::RenderingLOD" for configuration "Release"
set_property(TARGET VTK::RenderingLOD APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingLOD PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingLOD-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::CommonSystem;VTK::FiltersCore;VTK::FiltersModeling"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingLOD-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingLOD )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingLOD "${_IMPORT_PREFIX}/lib/vtkRenderingLOD-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingLOD-9.0.dll" )

# Import target "VTK::RenderingImage" for configuration "Release"
set_property(TARGET VTK::RenderingImage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingImage PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingImage-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonMath;VTK::CommonTransforms;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingImage-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingImage "${_IMPORT_PREFIX}/lib/vtkRenderingImage-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingImage-9.0.dll" )

# Import target "VTK::RenderingContextOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingContextOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingContextOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingContextOpenGL2-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonTransforms;VTK::ImagingCore;VTK::glew"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingContextOpenGL2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingContextOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingContextOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingContextOpenGL2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingContextOpenGL2-9.0.dll" )

# Import target "VTK::vtkhdf5_src" for configuration "Release"
set_property(TARGET VTK::vtkhdf5_src APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkhdf5_src PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkhdf5-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkhdf5-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkhdf5_src )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkhdf5_src "${_IMPORT_PREFIX}/lib/vtkhdf5-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkhdf5-9.0.dll" )

# Import target "VTK::vtkhdf5_hl_src" for configuration "Release"
set_property(TARGET VTK::vtkhdf5_hl_src APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::vtkhdf5_hl_src PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkhdf5_hl-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtkhdf5_src"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkhdf5_hl-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::vtkhdf5_hl_src )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::vtkhdf5_hl_src "${_IMPORT_PREFIX}/lib/vtkhdf5_hl-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkhdf5_hl-9.0.dll" )

# Import target "VTK::IOVeraOut" for configuration "Release"
set_property(TARGET VTK::IOVeraOut APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOVeraOut PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOVeraOut-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOVeraOut-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOVeraOut )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOVeraOut "${_IMPORT_PREFIX}/lib/vtkIOVeraOut-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOVeraOut-9.0.dll" )

# Import target "VTK::IOTecplotTable" for configuration "Release"
set_property(TARGET VTK::IOTecplotTable APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOTecplotTable PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOTecplotTable-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::IOCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOTecplotTable-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOTecplotTable )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOTecplotTable "${_IMPORT_PREFIX}/lib/vtkIOTecplotTable-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOTecplotTable-9.0.dll" )

# Import target "VTK::IOSegY" for configuration "Release"
set_property(TARGET VTK::IOSegY APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOSegY PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOSegY-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOSegY-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOSegY )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOSegY "${_IMPORT_PREFIX}/lib/vtkIOSegY-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOSegY-9.0.dll" )

# Import target "VTK::IOParallelXML" for configuration "Release"
set_property(TARGET VTK::IOParallelXML APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOParallelXML PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOParallelXML-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMisc;VTK::ParallelCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOParallelXML-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOParallelXML )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOParallelXML "${_IMPORT_PREFIX}/lib/vtkIOParallelXML-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOParallelXML-9.0.dll" )

# Import target "VTK::jsoncpp" for configuration "Release"
set_property(TARGET VTK::jsoncpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::jsoncpp PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkjsoncpp-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkjsoncpp-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::jsoncpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::jsoncpp "${_IMPORT_PREFIX}/lib/vtkjsoncpp-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkjsoncpp-9.0.dll" )

# Import target "VTK::IOGeometry" for configuration "Release"
set_property(TARGET VTK::IOGeometry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOGeometry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOGeometry-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersGeneral;VTK::FiltersHybrid;VTK::ImagingCore;VTK::IOImage;VTK::RenderingCore;VTK::jsoncpp;VTK::vtksys;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOGeometry-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOGeometry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOGeometry "${_IMPORT_PREFIX}/lib/vtkIOGeometry-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOGeometry-9.0.dll" )

# Import target "VTK::FiltersParallel" for configuration "Release"
set_property(TARGET VTK::FiltersParallel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersParallel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersParallel-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonSystem;VTK::CommonTransforms;VTK::IOLegacy;VTK::ParallelCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersParallel-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersParallel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersParallel "${_IMPORT_PREFIX}/lib/vtkFiltersParallel-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallel-9.0.dll" )

# Import target "VTK::IOParallel" for configuration "Release"
set_property(TARGET VTK::IOParallel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOParallel PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOParallel-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMisc;VTK::CommonSystem;VTK::FiltersCore;VTK::FiltersExtraction;VTK::FiltersParallel;VTK::ParallelCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOParallel-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOParallel )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOParallel "${_IMPORT_PREFIX}/lib/vtkIOParallel-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOParallel-9.0.dll" )

# Import target "VTK::IOPLY" for configuration "Release"
set_property(TARGET VTK::IOPLY APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOPLY PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOPLY-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOPLY-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOPLY )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOPLY "${_IMPORT_PREFIX}/lib/vtkIOPLY-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOPLY-9.0.dll" )

# Import target "VTK::IOMovie" for configuration "Release"
set_property(TARGET VTK::IOMovie APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOMovie PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOMovie-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonMisc;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOMovie-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOMovie )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOMovie "${_IMPORT_PREFIX}/lib/vtkIOMovie-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOMovie-9.0.dll" )

# Import target "VTK::ogg" for configuration "Release"
set_property(TARGET VTK::ogg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ogg PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkogg-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkogg-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ogg )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ogg "${_IMPORT_PREFIX}/lib/vtkogg-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkogg-9.0.dll" )

# Import target "VTK::theora" for configuration "Release"
set_property(TARGET VTK::theora APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::theora PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtktheora-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtktheora-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::theora )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::theora "${_IMPORT_PREFIX}/lib/vtktheora-9.0.lib" "${_IMPORT_PREFIX}/bin/vtktheora-9.0.dll" )

# Import target "VTK::IOOggTheora" for configuration "Release"
set_property(TARGET VTK::IOOggTheora APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOOggTheora PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOOggTheora-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonMisc;VTK::CommonSystem;VTK::theora"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOOggTheora-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOOggTheora )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOOggTheora "${_IMPORT_PREFIX}/lib/vtkIOOggTheora-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOOggTheora-9.0.dll" )

# Import target "VTK::netcdf" for configuration "Release"
set_property(TARGET VTK::netcdf APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::netcdf PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtknetcdf-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtknetcdf-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::netcdf )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::netcdf "${_IMPORT_PREFIX}/lib/vtknetcdf-9.0.lib" "${_IMPORT_PREFIX}/bin/vtknetcdf-9.0.dll" )

# Import target "VTK::IONetCDF" for configuration "Release"
set_property(TARGET VTK::IONetCDF APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IONetCDF PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIONetCDF-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::netcdf;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIONetCDF-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IONetCDF )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IONetCDF "${_IMPORT_PREFIX}/lib/vtkIONetCDF-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIONetCDF-9.0.dll" )

# Import target "VTK::IOMotionFX" for configuration "Release"
set_property(TARGET VTK::IOMotionFX APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOMotionFX PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOMotionFX-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::IOGeometry;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOMotionFX-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOMotionFX )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOMotionFX "${_IMPORT_PREFIX}/lib/vtkIOMotionFX-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOMotionFX-9.0.dll" )

# Import target "VTK::IOMINC" for configuration "Release"
set_property(TARGET VTK::IOMINC APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOMINC PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOMINC-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonTransforms;VTK::FiltersHybrid;VTK::RenderingCore;VTK::netcdf;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOMINC-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOMINC )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOMINC "${_IMPORT_PREFIX}/lib/vtkIOMINC-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOMINC-9.0.dll" )

# Import target "VTK::IOLSDyna" for configuration "Release"
set_property(TARGET VTK::IOLSDyna APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOLSDyna PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOLSDyna-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOLSDyna-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOLSDyna )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOLSDyna "${_IMPORT_PREFIX}/lib/vtkIOLSDyna-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOLSDyna-9.0.dll" )

# Import target "VTK::libxml2" for configuration "Release"
set_property(TARGET VTK::libxml2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::libxml2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklibxml2-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklibxml2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::libxml2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::libxml2 "${_IMPORT_PREFIX}/lib/vtklibxml2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtklibxml2-9.0.dll" )

# Import target "VTK::IOInfovis" for configuration "Release"
set_property(TARGET VTK::IOInfovis APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOInfovis PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOInfovis-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMisc;VTK::IOCore;VTK::IOXMLParser;VTK::InfovisCore;VTK::libxml2;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOInfovis-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOInfovis )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOInfovis "${_IMPORT_PREFIX}/lib/vtkIOInfovis-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOInfovis-9.0.dll" )

# Import target "VTK::IOImport" for configuration "Release"
set_property(TARGET VTK::IOImport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOImport PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOImport-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersSources;VTK::ImagingCore;VTK::IOGeometry;VTK::IOImage;VTK::jsoncpp"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOImport-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOImport )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOImport "${_IMPORT_PREFIX}/lib/vtkIOImport-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOImport-9.0.dll" )

# Import target "VTK::IOVideo" for configuration "Release"
set_property(TARGET VTK::IOVideo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOVideo PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOVideo-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonSystem;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOVideo-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOVideo )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOVideo "${_IMPORT_PREFIX}/lib/vtkIOVideo-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOVideo-9.0.dll" )

# Import target "VTK::RenderingSceneGraph" for configuration "Release"
set_property(TARGET VTK::RenderingSceneGraph APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingSceneGraph PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingSceneGraph-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::RenderingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingSceneGraph-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingSceneGraph )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingSceneGraph "${_IMPORT_PREFIX}/lib/vtkRenderingSceneGraph-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingSceneGraph-9.0.dll" )

# Import target "VTK::RenderingVtkJS" for configuration "Release"
set_property(TARGET VTK::RenderingVtkJS APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingVtkJS PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingVtkJS-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::RenderingCore;VTK::RenderingOpenGL2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingVtkJS-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingVtkJS )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingVtkJS "${_IMPORT_PREFIX}/lib/vtkRenderingVtkJS-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingVtkJS-9.0.dll" )

# Import target "VTK::libharu" for configuration "Release"
set_property(TARGET VTK::libharu APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::libharu PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklibharu-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::png;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklibharu-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::libharu )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::libharu "${_IMPORT_PREFIX}/lib/vtklibharu-9.0.lib" "${_IMPORT_PREFIX}/bin/vtklibharu-9.0.dll" )

# Import target "VTK::IOExport" for configuration "Release"
set_property(TARGET VTK::IOExport APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOExport PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOExport-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonTransforms;VTK::FiltersGeometry;VTK::ImagingCore;VTK::jsoncpp;VTK::libharu"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOExport-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOExport )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOExport "${_IMPORT_PREFIX}/lib/vtkIOExport-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOExport-9.0.dll" )

# Import target "VTK::IOExportPDF" for configuration "Release"
set_property(TARGET VTK::IOExportPDF APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOExportPDF PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOExportPDF-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::ImagingCore;VTK::libharu"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOExportPDF-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOExportPDF )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOExportPDF "${_IMPORT_PREFIX}/lib/vtkIOExportPDF-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOExportPDF-9.0.dll" )

# Import target "VTK::gl2ps" for configuration "Release"
set_property(TARGET VTK::gl2ps APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::gl2ps PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkgl2ps-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::png;VTK::zlib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkgl2ps-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::gl2ps )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::gl2ps "${_IMPORT_PREFIX}/lib/vtkgl2ps-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkgl2ps-9.0.dll" )

# Import target "VTK::RenderingGL2PSOpenGL2" for configuration "Release"
set_property(TARGET VTK::RenderingGL2PSOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::RenderingGL2PSOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkRenderingGL2PSOpenGL2-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonMath;VTK::RenderingCore;VTK::gl2ps"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkRenderingGL2PSOpenGL2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::RenderingGL2PSOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::RenderingGL2PSOpenGL2 "${_IMPORT_PREFIX}/lib/vtkRenderingGL2PSOpenGL2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkRenderingGL2PSOpenGL2-9.0.dll" )

# Import target "VTK::IOExportGL2PS" for configuration "Release"
set_property(TARGET VTK::IOExportGL2PS APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOExportGL2PS PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOExportGL2PS-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingCore;VTK::RenderingCore;VTK::gl2ps"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOExportGL2PS-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOExportGL2PS )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOExportGL2PS "${_IMPORT_PREFIX}/lib/vtkIOExportGL2PS-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOExportGL2PS-9.0.dll" )

# Import target "VTK::exodusII" for configuration "Release"
set_property(TARGET VTK::exodusII APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::exodusII PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkexodusII-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkexodusII-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::exodusII )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::exodusII "${_IMPORT_PREFIX}/lib/vtkexodusII-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkexodusII-9.0.dll" )

# Import target "VTK::IOExodus" for configuration "Release"
set_property(TARGET VTK::IOExodus APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOExodus PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOExodus-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOExodus-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOExodus )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOExodus "${_IMPORT_PREFIX}/lib/vtkIOExodus-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOExodus-9.0.dll" )

# Import target "VTK::IOEnSight" for configuration "Release"
set_property(TARGET VTK::IOEnSight APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOEnSight PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOEnSight-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOEnSight-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOEnSight )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOEnSight "${_IMPORT_PREFIX}/lib/vtkIOEnSight-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOEnSight-9.0.dll" )

# Import target "VTK::IOCityGML" for configuration "Release"
set_property(TARGET VTK::IOCityGML APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOCityGML PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOCityGML-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::FiltersGeneral;VTK::FiltersModeling;VTK::pugixml;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOCityGML-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOCityGML )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOCityGML "${_IMPORT_PREFIX}/lib/vtkIOCityGML-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOCityGML-9.0.dll" )

# Import target "VTK::IOAsynchronous" for configuration "Release"
set_property(TARGET VTK::IOAsynchronous APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOAsynchronous PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOAsynchronous-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonMath;VTK::CommonMisc;VTK::CommonSystem;VTK::ParallelCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOAsynchronous-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOAsynchronous )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOAsynchronous "${_IMPORT_PREFIX}/lib/vtkIOAsynchronous-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOAsynchronous-9.0.dll" )

# Import target "VTK::FiltersAMR" for configuration "Release"
set_property(TARGET VTK::FiltersAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersAMR PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonMath;VTK::CommonSystem;VTK::FiltersCore;VTK::IOXML;VTK::ParallelCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersAMR "${_IMPORT_PREFIX}/lib/vtkFiltersAMR-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersAMR-9.0.dll" )

# Import target "VTK::IOAMR" for configuration "Release"
set_property(TARGET VTK::IOAMR APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOAMR PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOAMR-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonSystem;VTK::FiltersAMR;VTK::ParallelCore;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOAMR-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOAMR )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOAMR "${_IMPORT_PREFIX}/lib/vtkIOAMR-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOAMR-9.0.dll" )

# Import target "VTK::InteractionImage" for configuration "Release"
set_property(TARGET VTK::InteractionImage APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::InteractionImage PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkInteractionImage-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::ImagingColor;VTK::ImagingCore;VTK::InteractionStyle;VTK::InteractionWidgets"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkInteractionImage-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::InteractionImage )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::InteractionImage "${_IMPORT_PREFIX}/lib/vtkInteractionImage-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkInteractionImage-9.0.dll" )

# Import target "VTK::ImagingStencil" for configuration "Release"
set_property(TARGET VTK::ImagingStencil APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingStencil PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingStencil-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonComputationalGeometry;VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingStencil-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingStencil )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingStencil "${_IMPORT_PREFIX}/lib/vtkImagingStencil-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingStencil-9.0.dll" )

# Import target "VTK::ImagingStatistics" for configuration "Release"
set_property(TARGET VTK::ImagingStatistics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingStatistics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingStatistics-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::ImagingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingStatistics-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingStatistics )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingStatistics "${_IMPORT_PREFIX}/lib/vtkImagingStatistics-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingStatistics-9.0.dll" )

# Import target "VTK::ImagingMorphological" for configuration "Release"
set_property(TARGET VTK::ImagingMorphological APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::ImagingMorphological PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkImagingMorphological-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::ImagingSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkImagingMorphological-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::ImagingMorphological )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::ImagingMorphological "${_IMPORT_PREFIX}/lib/vtkImagingMorphological-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkImagingMorphological-9.0.dll" )

# Import target "VTK::sqlite" for configuration "Release"
set_property(TARGET VTK::sqlite APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::sqlite PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtksqlite-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtksqlite-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::sqlite )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::sqlite "${_IMPORT_PREFIX}/lib/vtksqlite-9.0.lib" "${_IMPORT_PREFIX}/bin/vtksqlite-9.0.dll" )

# Import target "VTK::IOSQL" for configuration "Release"
set_property(TARGET VTK::IOSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::IOSQL PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkIOSQL-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::sqlite;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkIOSQL-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::IOSQL )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::IOSQL "${_IMPORT_PREFIX}/lib/vtkIOSQL-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkIOSQL-9.0.dll" )

# Import target "VTK::GUISupportQtSQL" for configuration "Release"
set_property(TARGET VTK::GUISupportQtSQL APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::GUISupportQtSQL PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkGUISupportQtSQL-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkGUISupportQtSQL-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::GUISupportQtSQL )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::GUISupportQtSQL "${_IMPORT_PREFIX}/lib/vtkGUISupportQtSQL-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkGUISupportQtSQL-9.0.dll" )

# Import target "VTK::libproj" for configuration "Release"
set_property(TARGET VTK::libproj APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::libproj PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtklibproj-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtklibproj-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::libproj )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::libproj "${_IMPORT_PREFIX}/lib/vtklibproj-9.0.lib" "${_IMPORT_PREFIX}/bin/vtklibproj-9.0.dll" )

# Import target "VTK::GeovisCore" for configuration "Release"
set_property(TARGET VTK::GeovisCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::GeovisCore PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkGeovisCore-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonSystem;VTK::FiltersCore;VTK::FiltersGeneral;VTK::IOImage;VTK::IOXML;VTK::ImagingCore;VTK::ImagingSources;VTK::InfovisLayout"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkGeovisCore-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::GeovisCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::GeovisCore "${_IMPORT_PREFIX}/lib/vtkGeovisCore-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkGeovisCore-9.0.dll" )

# Import target "VTK::FiltersTopology" for configuration "Release"
set_property(TARGET VTK::FiltersTopology APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersTopology PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersTopology-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersTopology-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersTopology )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersTopology "${_IMPORT_PREFIX}/lib/vtkFiltersTopology-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersTopology-9.0.dll" )

# Import target "VTK::FiltersSelection" for configuration "Release"
set_property(TARGET VTK::FiltersSelection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersSelection PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersSelection-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersSelection-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersSelection )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersSelection "${_IMPORT_PREFIX}/lib/vtkFiltersSelection-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSelection-9.0.dll" )

# Import target "VTK::FiltersSMP" for configuration "Release"
set_property(TARGET VTK::FiltersSMP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersSMP PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersSMP-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonMath;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersSMP-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersSMP )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersSMP "${_IMPORT_PREFIX}/lib/vtkFiltersSMP-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersSMP-9.0.dll" )

# Import target "VTK::FiltersProgrammable" for configuration "Release"
set_property(TARGET VTK::FiltersProgrammable APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersProgrammable PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersProgrammable-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonTransforms"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersProgrammable-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersProgrammable )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersProgrammable "${_IMPORT_PREFIX}/lib/vtkFiltersProgrammable-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersProgrammable-9.0.dll" )

# Import target "VTK::FiltersPoints" for configuration "Release"
set_property(TARGET VTK::FiltersPoints APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersPoints PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersPoints-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersPoints-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersPoints )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersPoints "${_IMPORT_PREFIX}/lib/vtkFiltersPoints-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersPoints-9.0.dll" )

# Import target "VTK::verdict" for configuration "Release"
set_property(TARGET VTK::verdict APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::verdict PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkverdict-9.0.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkverdict-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::verdict )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::verdict "${_IMPORT_PREFIX}/lib/vtkverdict-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkverdict-9.0.dll" )

# Import target "VTK::FiltersVerdict" for configuration "Release"
set_property(TARGET VTK::FiltersVerdict APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersVerdict PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersVerdict-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersVerdict-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersVerdict )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersVerdict "${_IMPORT_PREFIX}/lib/vtkFiltersVerdict-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersVerdict-9.0.dll" )

# Import target "VTK::FiltersParallelImaging" for configuration "Release"
set_property(TARGET VTK::FiltersParallelImaging APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersParallelImaging PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersParallelImaging-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonSystem;VTK::FiltersExtraction;VTK::FiltersStatistics;VTK::ImagingGeneral;VTK::ParallelCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersParallelImaging-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersParallelImaging )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersParallelImaging "${_IMPORT_PREFIX}/lib/vtkFiltersParallelImaging-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersParallelImaging-9.0.dll" )

# Import target "VTK::FiltersHyperTree" for configuration "Release"
set_property(TARGET VTK::FiltersHyperTree APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersHyperTree PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersHyperTree-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonSystem"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersHyperTree-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersHyperTree )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersHyperTree "${_IMPORT_PREFIX}/lib/vtkFiltersHyperTree-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersHyperTree-9.0.dll" )

# Import target "VTK::FiltersGeneric" for configuration "Release"
set_property(TARGET VTK::FiltersGeneric APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersGeneric PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersGeneric-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonCore;VTK::CommonDataModel;VTK::CommonMisc;VTK::CommonSystem;VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersSources"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersGeneric-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersGeneric )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersGeneric "${_IMPORT_PREFIX}/lib/vtkFiltersGeneric-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersGeneric-9.0.dll" )

# Import target "VTK::FiltersFlowPaths" for configuration "Release"
set_property(TARGET VTK::FiltersFlowPaths APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::FiltersFlowPaths PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::FiltersCore;VTK::FiltersGeometry;VTK::FiltersSources;VTK::IOCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::FiltersFlowPaths )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::FiltersFlowPaths "${_IMPORT_PREFIX}/lib/vtkFiltersFlowPaths-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkFiltersFlowPaths-9.0.dll" )

# Import target "VTK::DomainsChemistry" for configuration "Release"
set_property(TARGET VTK::DomainsChemistry APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DomainsChemistry PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonTransforms;VTK::FiltersCore;VTK::FiltersGeneral;VTK::FiltersSources;VTK::vtksys"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DomainsChemistry )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DomainsChemistry "${_IMPORT_PREFIX}/lib/vtkDomainsChemistry-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsChemistry-9.0.dll" )

# Import target "VTK::DomainsChemistryOpenGL2" for configuration "Release"
set_property(TARGET VTK::DomainsChemistryOpenGL2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(VTK::DomainsChemistryOpenGL2 PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/vtkDomainsChemistryOpenGL2-9.0.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "VTK::CommonDataModel;VTK::CommonExecutionModel;VTK::CommonMath;VTK::glew;VTK::RenderingCore"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/vtkDomainsChemistryOpenGL2-9.0.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS VTK::DomainsChemistryOpenGL2 )
list(APPEND _IMPORT_CHECK_FILES_FOR_VTK::DomainsChemistryOpenGL2 "${_IMPORT_PREFIX}/lib/vtkDomainsChemistryOpenGL2-9.0.lib" "${_IMPORT_PREFIX}/bin/vtkDomainsChemistryOpenGL2-9.0.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
