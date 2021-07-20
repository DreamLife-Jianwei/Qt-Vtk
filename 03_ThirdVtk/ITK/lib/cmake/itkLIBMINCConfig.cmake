# LIBMINC CMake configuration file


get_filename_component(LIBMINC_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)
get_filename_component(LIBMINC_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH )

set(HAVE_MINC2    1)
set(HAVE_EZMINC   OFF)
set(HAVE_MINC1    OFF)

set(LIBMINC_NIFTI_SUPPORT OFF)

#set(NETCDF_INCLUDE_DIR "")
#set(HDF5_INCLUDE_DIR   "")
#set(NIFTI_INCLUDE_DIR  "")

#set(NETCDF_LIBRARY     "")
#set(HDF5_LIBRARY       "hdf5_cpp-shared;hdf5-shared")
#set(ZLIB_LIBRARY       "itkzlib")
#set(ZLIB_LIBRARIES     "itkzlib")
#set(NIFTI_LIBRARIES    "")

set(LIBMINC_INCLUDE_DIRS "${LIBMINC_INSTALL_PREFIX}/include") # ${LIBMINC_INSTALL_PREFIX}/include
set(LIBMINC_LIBRARY_DIRS "${LIBMINC_INSTALL_PREFIX}/lib") # ${LIBMINC_INSTALL_PREFIX}/lib
set(LIBMINC_USE_FILE     "${LIBMINC_INSTALL_PREFIX}/lib/cmake/UseitkLIBMINC.cmake") # ${LIBMINC_INSTALL_PREFIX}/lib/UseLIBMINC.cmake

set(LIBMINC_LIBRARIES    "itkminc2;hdf5_cpp-shared;hdf5-shared;itkzlib")
set(VOLUME_IO_LIBRARIES  "itkminc2;hdf5_cpp-shared;hdf5-shared;itkzlib")
set(EZMINC_LIBRARIES     "minc_io;itkminc2;hdf5_cpp-shared;hdf5-shared;itkzlib")

set(LIBMINC_STATIC_LIBRARIES    "")
set(VOLUME_IO_STATIC_LIBRARIES  "")

set( LIBMINC_FOUND 1 )

# VF: disable for now  
#if( NOT LIBMINC_TARGETS_IMPORTED AND NOT LIBMINC_BINARY_DIR )
#  set( LIBMINC_TARGETS_IMPORTED 1 )
#  include( "${LIBMINC_CMAKE_DIR}/ITKTargets.cmake" )
#endif()  
