
#ifndef VTKTHEORA_EXPORT_H
#define VTKTHEORA_EXPORT_H

#ifdef THEORA_STATIC_DEFINE
#  define VTKTHEORA_EXPORT
#  define THEORA_NO_EXPORT
#else
#  ifndef VTKTHEORA_EXPORT
#    ifdef theora_EXPORTS
        /* We are building this library */
#      define VTKTHEORA_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKTHEORA_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef THEORA_NO_EXPORT
#    define THEORA_NO_EXPORT 
#  endif
#endif

#ifndef THEORA_DEPRECATED
#  define THEORA_DEPRECATED __declspec(deprecated)
#endif

#ifndef THEORA_DEPRECATED_EXPORT
#  define THEORA_DEPRECATED_EXPORT VTKTHEORA_EXPORT THEORA_DEPRECATED
#endif

#ifndef THEORA_DEPRECATED_NO_EXPORT
#  define THEORA_DEPRECATED_NO_EXPORT THEORA_NO_EXPORT THEORA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef THEORA_NO_DEPRECATED
#    define THEORA_NO_DEPRECATED
#  endif
#endif

#endif /* VTKTHEORA_EXPORT_H */
