
#ifndef VTKIOEXODUS_EXPORT_H
#define VTKIOEXODUS_EXPORT_H

#ifdef VTKIOEXODUS_STATIC_DEFINE
#  define VTKIOEXODUS_EXPORT
#  define VTKIOEXODUS_NO_EXPORT
#else
#  ifndef VTKIOEXODUS_EXPORT
#    ifdef vtkIOExodus_EXPORTS
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
#  define VTKIOEXODUS_DEPRECATED_EXPORT VTKIOEXODUS_EXPORT __declspec(deprecated)
#  define VTKIOEXODUS_DEPRECATED_NO_EXPORT VTKIOEXODUS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOEXODUS_NO_DEPRECATED
#endif

/* AutoInit implementations.  */
#if defined(vtkIOExodus_INCLUDE)
# include vtkIOExodus_INCLUDE
#endif
#if defined(vtkIOExodus_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkIOExodus)
#endif

#endif
