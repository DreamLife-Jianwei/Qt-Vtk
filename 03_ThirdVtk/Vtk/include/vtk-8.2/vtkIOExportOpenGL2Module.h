
#ifndef VTKIOEXPORTOPENGL2_EXPORT_H
#define VTKIOEXPORTOPENGL2_EXPORT_H

#ifdef VTKIOEXPORTOPENGL2_STATIC_DEFINE
#  define VTKIOEXPORTOPENGL2_EXPORT
#  define VTKIOEXPORTOPENGL2_NO_EXPORT
#else
#  ifndef VTKIOEXPORTOPENGL2_EXPORT
#    ifdef vtkIOExportOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKIOEXPORTOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOEXPORTOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOEXPORTOPENGL2_NO_EXPORT
#    define VTKIOEXPORTOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOEXPORTOPENGL2_DEPRECATED
#  define VTKIOEXPORTOPENGL2_DEPRECATED __declspec(deprecated)
#  define VTKIOEXPORTOPENGL2_DEPRECATED_EXPORT VTKIOEXPORTOPENGL2_EXPORT __declspec(deprecated)
#  define VTKIOEXPORTOPENGL2_DEPRECATED_NO_EXPORT VTKIOEXPORTOPENGL2_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOEXPORTOPENGL2_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkIOExportModule.h"
#include "vtkIOExportModule.h"
#include "vtkRenderingGL2PSOpenGL2Module.h"

/* AutoInit implementations.  */
#if defined(vtkIOExportOpenGL2_INCLUDE)
# include vtkIOExportOpenGL2_INCLUDE
#endif
#if defined(vtkIOExportOpenGL2_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkIOExportOpenGL2)
#endif

#endif
