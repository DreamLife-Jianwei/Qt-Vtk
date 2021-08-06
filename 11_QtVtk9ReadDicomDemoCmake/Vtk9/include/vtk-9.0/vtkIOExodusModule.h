
#ifndef VTKIOEXODUS_EXPORT_H
#define VTKIOEXODUS_EXPORT_H

#ifdef VTKIOEXODUS_STATIC_DEFINE
#  define VTKIOEXODUS_EXPORT
#  define VTKIOEXODUS_NO_EXPORT
#else
#  ifndef VTKIOEXODUS_EXPORT
#    ifdef IOExodus_EXPORTS
        /* We are building this library */
#      define VTKIOEXODUS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOEXODUS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOEXODUS_NO_EXPORT
#    define VTKIOEXODUS_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOEXODUS_DEPRECATED
#  define VTKIOEXODUS_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOEXODUS_DEPRECATED_EXPORT
#  define VTKIOEXODUS_DEPRECATED_EXPORT VTKIOEXODUS_EXPORT VTKIOEXODUS_DEPRECATED
#endif

#ifndef VTKIOEXODUS_DEPRECATED_NO_EXPORT
#  define VTKIOEXODUS_DEPRECATED_NO_EXPORT VTKIOEXODUS_NO_EXPORT VTKIOEXODUS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOEXODUS_NO_DEPRECATED
#    define VTKIOEXODUS_NO_DEPRECATED
#  endif
#endif

/* AutoInit implementations. */
#ifdef vtkIOExodus_AUTOINIT_INCLUDE
#include vtkIOExodus_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOExodus_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOExodus)
#endif

#endif /* VTKIOEXODUS_EXPORT_H */
