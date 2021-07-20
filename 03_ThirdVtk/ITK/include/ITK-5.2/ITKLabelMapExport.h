
#ifndef ITKLabelMap_EXPORT_H
#define ITKLabelMap_EXPORT_H

#ifdef ITK_STATIC
#  define ITKLabelMap_EXPORT
#  define ITKLabelMap_HIDDEN
#else
#  ifndef ITKLabelMap_EXPORT
#    ifdef ITKLabelMap_EXPORTS
        /* We are building this library */
#      define ITKLabelMap_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKLabelMap_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKLabelMap_HIDDEN
#    define ITKLabelMap_HIDDEN 
#  endif
#endif

#ifndef ITKLABELMAP_DEPRECATED
#  define ITKLABELMAP_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKLABELMAP_DEPRECATED_EXPORT
#  define ITKLABELMAP_DEPRECATED_EXPORT ITKLabelMap_EXPORT ITKLABELMAP_DEPRECATED
#endif

#ifndef ITKLABELMAP_DEPRECATED_NO_EXPORT
#  define ITKLABELMAP_DEPRECATED_NO_EXPORT ITKLabelMap_HIDDEN ITKLABELMAP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKLABELMAP_NO_DEPRECATED
#    define ITKLABELMAP_NO_DEPRECATED
#  endif
#endif

#endif /* ITKLabelMap_EXPORT_H */
