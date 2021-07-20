
#ifndef ITKVTK_EXPORT_H
#define ITKVTK_EXPORT_H

#ifdef ITK_STATIC
#  define ITKVTK_EXPORT
#  define ITKVTK_HIDDEN
#else
#  ifndef ITKVTK_EXPORT
#    ifdef ITKVTK_EXPORTS
        /* We are building this library */
#      define ITKVTK_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKVTK_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKVTK_HIDDEN
#    define ITKVTK_HIDDEN 
#  endif
#endif

#ifndef ITKVTK_DEPRECATED
#  define ITKVTK_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKVTK_DEPRECATED_EXPORT
#  define ITKVTK_DEPRECATED_EXPORT ITKVTK_EXPORT ITKVTK_DEPRECATED
#endif

#ifndef ITKVTK_DEPRECATED_NO_EXPORT
#  define ITKVTK_DEPRECATED_NO_EXPORT ITKVTK_HIDDEN ITKVTK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKVTK_NO_DEPRECATED
#    define ITKVTK_NO_DEPRECATED
#  endif
#endif

#endif /* ITKVTK_EXPORT_H */
