#-----------------------------------------------------------------------------
#
# ITKConfig.cmake - ITK CMake configuration file for external projects.
#
# This file is configured by ITK and used by the UseITK.cmake module
# to load ITK's settings for an external project.
#
# ITK components can be specified when using the CMake function `find_package()`
# E.g. find_package(ITK COMPONENTS ITKCommon ITKIOImageBase ITKIONRRD ITKImageGradient)
#
# The components listed in this call must be ITK module names or factories
# (e.g. ITKImageIO, ITKTransformIO). Factories allow the user to load all the
# modules of a specific type (e.g. ImageIO, TransformIO) without having to
# specify them individually.
# See `itk_module_config()` documentation for more information about factory modules.


# Compute the installation prefix from this ITKConfig.cmake file location.
get_filename_component(ITK_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(ITK_INSTALL_PREFIX "${ITK_INSTALL_PREFIX}" PATH)
get_filename_component(ITK_INSTALL_PREFIX "${ITK_INSTALL_PREFIX}" PATH)
get_filename_component(ITK_INSTALL_PREFIX "${ITK_INSTALL_PREFIX}" PATH)
set(ITK_MODULES_DIR "${ITK_INSTALL_PREFIX}/lib/cmake/ITK-5.2/Modules")

# The C and C++ flags added by ITK to the cmake-configured flags.
set(ITK_REQUIRED_C_FLAGS "")
set(ITK_REQUIRED_CXX_FLAGS " /bigobj")
set(ITK_REQUIRED_LINK_FLAGS "")

# The ITK version number
set(ITK_VERSION_MAJOR "5")
set(ITK_VERSION_MINOR "2")
set(ITK_VERSION_PATCH "0")

# If ITK was built with version 4 compatibility features.
set(ITKV4_COMPATIBILITY "OFF")

# Remove all legacy code completely.
set(ITK_LEGACY_REMOVE "OFF")

# Silence all legacy code messages.
set(ITK_LEGACY_SILENT "OFF")

# Remove code that will become legacy in future releases completely.
set(ITK_FUTURE_LEGACY_REMOVE "OFF")

# ITK's CMake directory with modules ITK uses.
set(ITK_CMAKE_DIR "${ITK_INSTALL_PREFIX}/lib/cmake/ITK-5.2")

# The location of the UseITK.cmake file.
set(ITK_USE_FILE "${ITK_INSTALL_PREFIX}/lib/cmake/ITK-5.2/UseITK.cmake")

# Whether ITK was built with shared libraries.
set(ITK_BUILD_SHARED "ON")

# Export the library build type (SHARED or STATIC) for external builds
set(ITK_LIBRARY_BUILD_TYPE "SHARED")

# Whether ITK examples were built.
set(ITK_BUILD_EXAMPLES "ON")

# Whether ITK documentation was built.
set(ITK_BUILD_DOCUMENTATION "OFF")

# List of available ITK modules.
set(ITK_MODULES_ENABLED "ITKDoubleConversion;ITKEigen3;ITKKWIML;ITKKWSys;ITKVNL;ITKVNLInstantiation;ITKCommon;ITKFiniteDifference;ITKImageFilterBase;ITKCurvatureFlow;ITKImageAdaptors;ITKNetlib;ITKStatistics;ITKTransform;ITKImageFunction;ITKImageGrid;ITKAnisotropicSmoothing;ITKImageCompose;ITKMesh;ITKZLIB;ITKMetaIO;ITKSpatialObjects;ITKImageStatistics;ITKPath;ITKImageIntensity;ITKImageLabel;ITKLabelMap;ITKThresholding;ITKConnectedComponents;ITKMathematicalMorphology;ITKBinaryMathematicalMorphology;ITKNarrowBand;ITKDistanceMap;ITKQuadEdgeMesh;ITKFastMarching;ITKIOImageBase;ITKImageCompare;ITKSmoothing;ITKImageGradient;ITKImageSources;ITKImageFeature;ITKOptimizers;ITKSignedDistanceFunction;ITKLevelSets;ITKAntiAlias;ITKPolynomials;ITKBiasCorrection;ITKClassifiers;ITKColormap;ITKFFT;ITKConvolution;ITKDICOMParser;ITKDeconvolution;ITKDeformableMesh;ITKDenoising;ITKDiffusionTensorImage;ITKDisplacementField;ITKEigen;ITKExpat;ITKGDCM;ITKNIFTI;ITKGIFTI;ITKGPUCommon;ITKGPUFiniteDifference;ITKGPUAnisotropicSmoothing;ITKGPUImageFilterBase;ITKGPURegistrationCommon;ITKRegistrationCommon;ITKPDEDeformableRegistration;ITKGPUPDEDeformableRegistration;ITKGPUSmoothing;ITKGPUThresholding;ITKGoogleTest;ITKHDF5;ITKIOBMP;ITKIOBioRad;ITKIOBruker;ITKIOCSV;ITKIOGDCM;ITKIOIPL;ITKIOGE;ITKIOGIPL;ITKIOHDF5;ITKJPEG;ITKIOJPEG;ITKOpenJPEG;ITKIOJPEG2000;ITKTIFF;ITKIOTIFF;ITKIOLSM;ITKMINC;ITKIOMINC;ITKIOMRC;ITKVoronoi;ITKIOMeshBase;ITKIOMeshBYU;ITKIOMeshFreeSurfer;ITKIOMeshGifti;ITKIOMeshOBJ;ITKIOMeshOFF;ITKIOMeshVTK;ITKIOMesh;ITKIOMeta;ITKIONIFTI;ITKNrrdIO;ITKIONRRD;ITKPNG;ITKIOPNG;ITKIORAW;ITKIOSiemens;ITKIOXML;ITKIOSpatialObjects;ITKIOStimulate;ITKTransformFactory;ITKIOTransformBase;ITKIOTransformHDF5;ITKIOTransformInsightLegacy;ITKIOTransformMatlab;ITKIOVTK;ITKImageFrequency;ITKImageFusion;ITKImageNoise;ITKIntegratedTest;ITKKLMRegionGrowing;ITKLIBLBFGS;ITKLabelVoting;ITKLevelSetsv4;ITKMarkovRandomFieldsClassifiers;ITKOptimizersv4;ITKMetricsv4;ITKQuadEdgeMeshFiltering;ITKRegionGrowing;ITKRegistrationMethodsv4;ITKSpatialFunction;ITKSuperPixel;ITKTestKernel;ITKVTK;ITKVideoCore;ITKVideoFiltering;ITKVideoIO;ITKVtkGlue;ITKWatersheds")

# Import ITK targets.
set(ITK_CONFIG_TARGETS_FILE "${ITK_INSTALL_PREFIX}/lib/cmake/ITK-5.2/ITKTargets.cmake")
if(NOT ITK_TARGETS_IMPORTED)
  set(ITK_TARGETS_IMPORTED 1)
  include("${ITK_CONFIG_TARGETS_FILE}")
endif()

# Load module interface macros.
include("${ITK_INSTALL_PREFIX}/lib/cmake/ITK-5.2/ITKModuleAPI.cmake")
# Load requested modules and their dependencies into variables:
#  ITK_LIBRARIES       = Libraries to link
#  ITK_INCLUDE_DIRS    = Header file search path
#  ITK_LIBRARY_DIRS    = Library search path (for outside dependencies)
#  ITK_RUNTIME_LIBRARY_DIRS = Runtime linker search path
#  ITK_FACTORY_NAMES = List of <module>::<factory>::<format>
#  ITK_FACTORY_LIST  = List of factories set
#  ITK_<factory_name> = List of formats for each factory
itk_module_config(ITK ${ITK_MODULES_ENABLED})

# Compute set of requested modules.
if(ITK_FIND_COMPONENTS)
  set(ITK_MODULES_REQUESTED ${ITK_FIND_COMPONENTS})
  # Specific modules requested by find_package(ITK).
  itk_module_config(ITK ${ITK_MODULES_REQUESTED})
else()
  set(ITK_MODULES_REQUESTED ${ITK_MODULES_ENABLED})
endif()

# Add configuration with FFTW
set(ITK_USE_FFTWD "OFF")
set(ITK_USE_FFTWF "OFF")
set(ITK_USE_SYSTEM_FFTW "OFF")
set(ITK_FFTW_INCLUDE_PATH "${ITK_INSTALL_PREFIX}/include/ITK-5.2/Algorithms")
set(ITK_FFTW_LIBDIR "${ITK_INSTALL_PREFIX}/lib/ITK-5.2")

# Add FFTW include and library directories
if (ITK_USE_FFTWF OR ITK_USE_FFTWD)
  set(ITK_INCLUDE_DIRS ${ITK_INCLUDE_DIRS} "${ITK_FFTW_INCLUDE_PATH}")
  set(ITK_LIBRARY_DIRS ${ITK_LIBRARY_DIRS} "${ITK_FFTW_LIBDIR}")
endif()

# Add configuration with GPU
set(ITK_USE_GPU "ON")

# Wrapping
set(ITK_WRAPPING "OFF")
# ITK_WRAP_SWIGINTERFACE and ITK_WRAP_CASTXML are set
# to ITK_WRAPPING value.
# ITK_WRAP_DOC and ITK_WRAP_EXPLICIT are disabled by
# default.

if( NOT DEFINED ITK_WRAP_PYTHON)
  set(ITK_WRAP_PYTHON "OFF")
endif()
if( NOT DEFINED ITK_WRAP_JAVA)
  set(ITK_WRAP_JAVA "OFF")
endif()
if(NOT DEFINED ITK_WRAP_RUBY)
  set(ITK_WRAP_RUBY "OFF")
endif()
if( NOT DEFINED ITK_WRAP_PERL)
  set(ITK_WRAP_PERL "OFF")
endif()
if(NOT DEFINED ITK_WRAP_TCL)
  set(ITK_WRAP_TCL "OFF")
endif()

# Set up the rest of the variables that WrapITK was built with.
set(ITK_WRAP_unsigned_char OFF)
set(ITK_WRAP_unsigned_short OFF)
set(ITK_WRAP_unsigned_long OFF)
set(ITK_WRAP_unsigned_long_long OFF)
set(ITK_WRAP_signed_char OFF)
set(ITK_WRAP_signed_short OFF)
set(ITK_WRAP_signed_long OFF)
set(ITK_WRAP_signed_long_long OFF)
set(ITK_WRAP_float OFF)
set(ITK_WRAP_double OFF)
set(ITK_WRAP_vector_float OFF)
set(ITK_WRAP_vector_double OFF)
set(ITK_WRAP_covariant_vector_float OFF)
set(ITK_WRAP_covariant_vector_double OFF)
set(ITK_WRAP_rgb_unsigned_char OFF)
set(ITK_WRAP_rgb_unsigned_short OFF)
set(ITK_WRAP_rgba_unsigned_char OFF)
set(ITK_WRAP_rgba_unsigned_short OFF)
set(ITK_WRAP_complex_float OFF)
set(ITK_WRAP_complex_double OFF)
set(ITK_WRAP_IMAGE_DIMS "")
set(ITK_WRAP_VECTOR_COMPONENTS "")

set(ITK_WRAP_PYTHON_VERSION "")
