
#ifndef ITKColormap_EXPORT_H
#define ITKColormap_EXPORT_H

#ifdef ITK_STATIC
#  define ITKColormap_EXPORT
#  define ITKColormap_HIDDEN
#else
#  ifndef ITKColormap_EXPORT
#    ifdef ITKColormap_EXPORTS
        /* We are building this library */
#      define ITKColormap_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKColormap_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKColormap_HIDDEN
#    define ITKColormap_HIDDEN 
#  endif
#endif

#ifndef ITKCOLORMAP_DEPRECATED
#  define ITKCOLORMAP_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKCOLORMAP_DEPRECATED_EXPORT
#  define ITKCOLORMAP_DEPRECATED_EXPORT ITKColormap_EXPORT ITKCOLORMAP_DEPRECATED
#endif

#ifndef ITKCOLORMAP_DEPRECATED_NO_EXPORT
#  define ITKCOLORMAP_DEPRECATED_NO_EXPORT ITKColormap_HIDDEN ITKCOLORMAP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKCOLORMAP_NO_DEPRECATED
#    define ITKCOLORMAP_NO_DEPRECATED
#  endif
#endif

#endif /* ITKColormap_EXPORT_H */
