
#ifndef VTKIOPARALLELXML_EXPORT_H
#define VTKIOPARALLELXML_EXPORT_H

#ifdef VTKIOPARALLELXML_STATIC_DEFINE
#  define VTKIOPARALLELXML_EXPORT
#  define VTKIOPARALLELXML_NO_EXPORT
#else
#  ifndef VTKIOPARALLELXML_EXPORT
#    ifdef vtkIOParallelXML_EXPORTS
        /* We are building this library */
#      define VTKIOPARALLELXML_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOPARALLELXML_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOPARALLELXML_NO_EXPORT
#    define VTKIOPARALLELXML_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOPARALLELXML_DEPRECATED
#  define VTKIOPARALLELXML_DEPRECATED __declspec(deprecated)
#  define VTKIOPARALLELXML_DEPRECATED_EXPORT VTKIOPARALLELXML_EXPORT __declspec(deprecated)
#  define VTKIOPARALLELXML_DEPRECATED_NO_EXPORT VTKIOPARALLELXML_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOPARALLELXML_NO_DEPRECATED
#endif



#endif
