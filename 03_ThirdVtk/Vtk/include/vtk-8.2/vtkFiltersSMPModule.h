
#ifndef VTKFILTERSSMP_EXPORT_H
#define VTKFILTERSSMP_EXPORT_H

#ifdef VTKFILTERSSMP_STATIC_DEFINE
#  define VTKFILTERSSMP_EXPORT
#  define VTKFILTERSSMP_NO_EXPORT
#else
#  ifndef VTKFILTERSSMP_EXPORT
#    ifdef vtkFiltersSMP_EXPORTS
        /* We are building this library */
#      define VTKFILTERSSMP_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSSMP_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSSMP_NO_EXPORT
#    define VTKFILTERSSMP_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSSMP_DEPRECATED
#  define VTKFILTERSSMP_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSSMP_DEPRECATED_EXPORT VTKFILTERSSMP_EXPORT __declspec(deprecated)
#  define VTKFILTERSSMP_DEPRECATED_NO_EXPORT VTKFILTERSSMP_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSSMP_NO_DEPRECATED
#endif



#endif
