
#ifndef ITKRegionGrowing_EXPORT_H
#define ITKRegionGrowing_EXPORT_H

#ifdef ITK_STATIC
#  define ITKRegionGrowing_EXPORT
#  define ITKRegionGrowing_HIDDEN
#else
#  ifndef ITKRegionGrowing_EXPORT
#    ifdef ITKRegionGrowing_EXPORTS
        /* We are building this library */
#      define ITKRegionGrowing_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKRegionGrowing_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKRegionGrowing_HIDDEN
#    define ITKRegionGrowing_HIDDEN 
#  endif
#endif

#ifndef ITKREGIONGROWING_DEPRECATED
#  define ITKREGIONGROWING_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKREGIONGROWING_DEPRECATED_EXPORT
#  define ITKREGIONGROWING_DEPRECATED_EXPORT ITKRegionGrowing_EXPORT ITKREGIONGROWING_DEPRECATED
#endif

#ifndef ITKREGIONGROWING_DEPRECATED_NO_EXPORT
#  define ITKREGIONGROWING_DEPRECATED_NO_EXPORT ITKRegionGrowing_HIDDEN ITKREGIONGROWING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKREGIONGROWING_NO_DEPRECATED
#    define ITKREGIONGROWING_NO_DEPRECATED
#  endif
#endif

#endif /* ITKRegionGrowing_EXPORT_H */
