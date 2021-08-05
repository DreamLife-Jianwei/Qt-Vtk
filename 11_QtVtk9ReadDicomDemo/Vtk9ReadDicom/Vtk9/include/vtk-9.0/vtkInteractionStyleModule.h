
#ifndef VTKINTERACTIONSTYLE_EXPORT_H
#define VTKINTERACTIONSTYLE_EXPORT_H

#ifdef VTKINTERACTIONSTYLE_STATIC_DEFINE
#  define VTKINTERACTIONSTYLE_EXPORT
#  define VTKINTERACTIONSTYLE_NO_EXPORT
#else
#  ifndef VTKINTERACTIONSTYLE_EXPORT
#    ifdef InteractionStyle_EXPORTS
        /* We are building this library */
#      define VTKINTERACTIONSTYLE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKINTERACTIONSTYLE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKINTERACTIONSTYLE_NO_EXPORT
#    define VTKINTERACTIONSTYLE_NO_EXPORT 
#  endif
#endif

#ifndef VTKINTERACTIONSTYLE_DEPRECATED
#  define VTKINTERACTIONSTYLE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKINTERACTIONSTYLE_DEPRECATED_EXPORT
#  define VTKINTERACTIONSTYLE_DEPRECATED_EXPORT VTKINTERACTIONSTYLE_EXPORT VTKINTERACTIONSTYLE_DEPRECATED
#endif

#ifndef VTKINTERACTIONSTYLE_DEPRECATED_NO_EXPORT
#  define VTKINTERACTIONSTYLE_DEPRECATED_NO_EXPORT VTKINTERACTIONSTYLE_NO_EXPORT VTKINTERACTIONSTYLE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKINTERACTIONSTYLE_NO_DEPRECATED
#    define VTKINTERACTIONSTYLE_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkInteractionStyle_AUTOINIT_INCLUDE
#include vtkInteractionStyle_AUTOINIT_INCLUDE
#endif
#ifdef vtkInteractionStyle_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkInteractionStyle)
#endif

#endif /* VTKINTERACTIONSTYLE_EXPORT_H */
