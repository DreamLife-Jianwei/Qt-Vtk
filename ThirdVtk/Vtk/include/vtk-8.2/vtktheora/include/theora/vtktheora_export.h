
#ifndef VTKTHEORA_EXPORT_H
#define VTKTHEORA_EXPORT_H

#ifdef VTKTHEORA_STATIC_DEFINE
#  define VTKTHEORA_EXPORT
#  define VTKTHEORA_NO_EXPORT
#else
#  ifndef VTKTHEORA_EXPORT
#    ifdef vtktheora_EXPORTS
        /* We are building this library */
#      define VTKTHEORA_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKTHEORA_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKTHEORA_NO_EXPORT
#    define VTKTHEORA_NO_EXPORT 
#  endif
#endif

#ifndef VTKTHEORA_DEPRECATED
#  define VTKTHEORA_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKTHEORA_DEPRECATED_EXPORT
#  define VTKTHEORA_DEPRECATED_EXPORT VTKTHEORA_EXPORT VTKTHEORA_DEPRECATED
#endif

#ifndef VTKTHEORA_DEPRECATED_NO_EXPORT
#  define VTKTHEORA_DEPRECATED_NO_EXPORT VTKTHEORA_NO_EXPORT VTKTHEORA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKTHEORA_NO_DEPRECATED
#    define VTKTHEORA_NO_DEPRECATED
#  endif
#endif

#endif
