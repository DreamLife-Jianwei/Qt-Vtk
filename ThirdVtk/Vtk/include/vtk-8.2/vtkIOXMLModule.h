
#ifndef VTKIOXML_EXPORT_H
#define VTKIOXML_EXPORT_H

#ifdef VTKIOXML_STATIC_DEFINE
#  define VTKIOXML_EXPORT
#  define VTKIOXML_NO_EXPORT
#else
#  ifndef VTKIOXML_EXPORT
#    ifdef vtkIOXML_EXPORTS
        /* We are building this library */
#      define VTKIOXML_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOXML_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOXML_NO_EXPORT
#    define VTKIOXML_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOXML_DEPRECATED
#  define VTKIOXML_DEPRECATED __declspec(deprecated)
#  define VTKIOXML_DEPRECATED_EXPORT VTKIOXML_EXPORT __declspec(deprecated)
#  define VTKIOXML_DEPRECATED_NO_EXPORT VTKIOXML_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOXML_NO_DEPRECATED
#endif



#endif
