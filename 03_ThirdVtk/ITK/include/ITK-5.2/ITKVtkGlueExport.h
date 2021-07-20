
#ifndef ITKVtkGlue_EXPORT_H
#define ITKVtkGlue_EXPORT_H

#ifdef ITK_STATIC
#  define ITKVtkGlue_EXPORT
#  define ITKVtkGlue_HIDDEN
#else
#  ifndef ITKVtkGlue_EXPORT
#    ifdef ITKVtkGlue_EXPORTS
        /* We are building this library */
#      define ITKVtkGlue_EXPORT 
#    else
        /* We are using this library */
#      define ITKVtkGlue_EXPORT 
#    endif
#  endif

#  ifndef ITKVtkGlue_HIDDEN
#    define ITKVtkGlue_HIDDEN 
#  endif
#endif

#ifndef ITKVTKGLUE_DEPRECATED
#  define ITKVTKGLUE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKVTKGLUE_DEPRECATED_EXPORT
#  define ITKVTKGLUE_DEPRECATED_EXPORT ITKVtkGlue_EXPORT ITKVTKGLUE_DEPRECATED
#endif

#ifndef ITKVTKGLUE_DEPRECATED_NO_EXPORT
#  define ITKVTKGLUE_DEPRECATED_NO_EXPORT ITKVtkGlue_HIDDEN ITKVTKGLUE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKVTKGLUE_NO_DEPRECATED
#    define ITKVTKGLUE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKVtkGlue_EXPORT_H */
