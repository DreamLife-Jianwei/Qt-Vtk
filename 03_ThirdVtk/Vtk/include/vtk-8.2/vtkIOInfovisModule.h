
#ifndef VTKIOINFOVIS_EXPORT_H
#define VTKIOINFOVIS_EXPORT_H

#ifdef VTKIOINFOVIS_STATIC_DEFINE
#  define VTKIOINFOVIS_EXPORT
#  define VTKIOINFOVIS_NO_EXPORT
#else
#  ifndef VTKIOINFOVIS_EXPORT
#    ifdef vtkIOInfovis_EXPORTS
        /* We are building this library */
#      define VTKIOINFOVIS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOINFOVIS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOINFOVIS_NO_EXPORT
#    define VTKIOINFOVIS_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOINFOVIS_DEPRECATED
#  define VTKIOINFOVIS_DEPRECATED __declspec(deprecated)
#  define VTKIOINFOVIS_DEPRECATED_EXPORT VTKIOINFOVIS_EXPORT __declspec(deprecated)
#  define VTKIOINFOVIS_DEPRECATED_NO_EXPORT VTKIOINFOVIS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOINFOVIS_NO_DEPRECATED
#endif



#endif
