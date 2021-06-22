
#ifndef VTKGEOVISCORE_EXPORT_H
#define VTKGEOVISCORE_EXPORT_H

#ifdef VTKGEOVISCORE_STATIC_DEFINE
#  define VTKGEOVISCORE_EXPORT
#  define VTKGEOVISCORE_NO_EXPORT
#else
#  ifndef VTKGEOVISCORE_EXPORT
#    ifdef vtkGeovisCore_EXPORTS
        /* We are building this library */
#      define VTKGEOVISCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKGEOVISCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKGEOVISCORE_NO_EXPORT
#    define VTKGEOVISCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKGEOVISCORE_DEPRECATED
#  define VTKGEOVISCORE_DEPRECATED __declspec(deprecated)
#  define VTKGEOVISCORE_DEPRECATED_EXPORT VTKGEOVISCORE_EXPORT __declspec(deprecated)
#  define VTKGEOVISCORE_DEPRECATED_NO_EXPORT VTKGEOVISCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKGEOVISCORE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkInteractionStyleModule.h"
#include "vtkInteractionWidgetsModule.h"
#include "vtkRenderingCoreModule.h"
#include "vtkViewsCoreModule.h"

#endif
