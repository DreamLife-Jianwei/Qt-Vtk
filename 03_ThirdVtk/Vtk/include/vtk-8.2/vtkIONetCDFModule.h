
#ifndef VTKIONETCDF_EXPORT_H
#define VTKIONETCDF_EXPORT_H

#ifdef VTKIONETCDF_STATIC_DEFINE
#  define VTKIONETCDF_EXPORT
#  define VTKIONETCDF_NO_EXPORT
#else
#  ifndef VTKIONETCDF_EXPORT
#    ifdef vtkIONetCDF_EXPORTS
        /* We are building this library */
#      define VTKIONETCDF_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIONETCDF_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIONETCDF_NO_EXPORT
#    define VTKIONETCDF_NO_EXPORT 
#  endif
#endif

#ifndef VTKIONETCDF_DEPRECATED
#  define VTKIONETCDF_DEPRECATED __declspec(deprecated)
#  define VTKIONETCDF_DEPRECATED_EXPORT VTKIONETCDF_EXPORT __declspec(deprecated)
#  define VTKIONETCDF_DEPRECATED_NO_EXPORT VTKIONETCDF_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIONETCDF_NO_DEPRECATED
#endif



#endif
