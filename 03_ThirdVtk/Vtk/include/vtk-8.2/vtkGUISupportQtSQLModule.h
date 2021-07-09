
#ifndef VTKGUISUPPORTQTSQL_EXPORT_H
#define VTKGUISUPPORTQTSQL_EXPORT_H

#ifdef VTKGUISUPPORTQTSQL_STATIC_DEFINE
#  define VTKGUISUPPORTQTSQL_EXPORT
#  define VTKGUISUPPORTQTSQL_NO_EXPORT
#else
#  ifndef VTKGUISUPPORTQTSQL_EXPORT
#    ifdef vtkGUISupportQtSQL_EXPORTS
        /* We are building this library */
#      define VTKGUISUPPORTQTSQL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKGUISUPPORTQTSQL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKGUISUPPORTQTSQL_NO_EXPORT
#    define VTKGUISUPPORTQTSQL_NO_EXPORT 
#  endif
#endif

#ifndef VTKGUISUPPORTQTSQL_DEPRECATED
#  define VTKGUISUPPORTQTSQL_DEPRECATED __declspec(deprecated)
#  define VTKGUISUPPORTQTSQL_DEPRECATED_EXPORT VTKGUISUPPORTQTSQL_EXPORT __declspec(deprecated)
#  define VTKGUISUPPORTQTSQL_DEPRECATED_NO_EXPORT VTKGUISUPPORTQTSQL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKGUISUPPORTQTSQL_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkIOSQLModule.h"

#endif
