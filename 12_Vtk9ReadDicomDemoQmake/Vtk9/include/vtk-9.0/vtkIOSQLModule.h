
#ifndef VTKIOSQL_EXPORT_H
#define VTKIOSQL_EXPORT_H

#ifdef VTKIOSQL_STATIC_DEFINE
#  define VTKIOSQL_EXPORT
#  define VTKIOSQL_NO_EXPORT
#else
#  ifndef VTKIOSQL_EXPORT
#    ifdef IOSQL_EXPORTS
        /* We are building this library */
#      define VTKIOSQL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOSQL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOSQL_NO_EXPORT
#    define VTKIOSQL_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOSQL_DEPRECATED
#  define VTKIOSQL_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOSQL_DEPRECATED_EXPORT
#  define VTKIOSQL_DEPRECATED_EXPORT VTKIOSQL_EXPORT VTKIOSQL_DEPRECATED
#endif

#ifndef VTKIOSQL_DEPRECATED_NO_EXPORT
#  define VTKIOSQL_DEPRECATED_NO_EXPORT VTKIOSQL_NO_EXPORT VTKIOSQL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOSQL_NO_DEPRECATED
#    define VTKIOSQL_NO_DEPRECATED
#  endif
#endif

/* AutoInit implementations. */
#ifdef vtkIOSQL_AUTOINIT_INCLUDE
#include vtkIOSQL_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOSQL_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOSQL)
#endif

#endif /* VTKIOSQL_EXPORT_H */
