
#ifndef VTKFILTERSTOPOLOGY_EXPORT_H
#define VTKFILTERSTOPOLOGY_EXPORT_H

#ifdef VTKFILTERSTOPOLOGY_STATIC_DEFINE
#  define VTKFILTERSTOPOLOGY_EXPORT
#  define VTKFILTERSTOPOLOGY_NO_EXPORT
#else
#  ifndef VTKFILTERSTOPOLOGY_EXPORT
#    ifdef vtkFiltersTopology_EXPORTS
        /* We are building this library */
#      define VTKFILTERSTOPOLOGY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSTOPOLOGY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSTOPOLOGY_NO_EXPORT
#    define VTKFILTERSTOPOLOGY_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSTOPOLOGY_DEPRECATED
#  define VTKFILTERSTOPOLOGY_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSTOPOLOGY_DEPRECATED_EXPORT VTKFILTERSTOPOLOGY_EXPORT __declspec(deprecated)
#  define VTKFILTERSTOPOLOGY_DEPRECATED_NO_EXPORT VTKFILTERSTOPOLOGY_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSTOPOLOGY_NO_DEPRECATED
#endif



#endif
