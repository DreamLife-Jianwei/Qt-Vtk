
#ifndef VTKIOSQL_EXPORT_H
#define VTKIOSQL_EXPORT_H

#ifdef VTKIOSQL_STATIC_DEFINE
#  define VTKIOSQL_EXPORT
#  define VTKIOSQL_NO_EXPORT
#else
#  ifndef VTKIOSQL_EXPORT
#    ifdef vtkIOSQL_EXPORTS
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
#  define VTKIOSQL_DEPRECATED_EXPORT VTKIOSQL_EXPORT __declspec(deprecated)
#  define VTKIOSQL_DEPRECATED_NO_EXPORT VTKIOSQL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOSQL_NO_DEPRECATED
#endif

/* AutoInit implementations.  */
#if defined(vtkIOSQL_INCLUDE)
# include vtkIOSQL_INCLUDE
#endif
#if defined(vtkIOSQL_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkIOSQL)
#endif

#endif
