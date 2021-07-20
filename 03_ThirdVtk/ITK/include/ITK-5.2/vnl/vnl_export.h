
#ifndef VNL_EXPORT_H
#define VNL_EXPORT_H

#ifdef VNL_STATIC_DEFINE
#  define VNL_EXPORT
#  define VNL_NO_EXPORT
#else
#  ifndef VNL_EXPORT
#    ifdef itkvnl_EXPORTS
        /* We are building this library */
#      define VNL_EXPORT 
#    else
        /* We are using this library */
#      define VNL_EXPORT 
#    endif
#  endif

#  ifndef VNL_NO_EXPORT
#    define VNL_NO_EXPORT 
#  endif
#endif

#ifndef VNL_DEPRECATED
#  define VNL_DEPRECATED __declspec(deprecated)
#endif

#ifndef VNL_DEPRECATED_EXPORT
#  define VNL_DEPRECATED_EXPORT VNL_EXPORT VNL_DEPRECATED
#endif

#ifndef VNL_DEPRECATED_NO_EXPORT
#  define VNL_DEPRECATED_NO_EXPORT VNL_NO_EXPORT VNL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VNL_NO_DEPRECATED
#    define VNL_NO_DEPRECATED
#  endif
#endif

#endif /* VNL_EXPORT_H */
