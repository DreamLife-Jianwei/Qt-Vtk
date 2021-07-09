
#ifndef VTKIOCITYGML_EXPORT_H
#define VTKIOCITYGML_EXPORT_H

#ifdef VTKIOCITYGML_STATIC_DEFINE
#  define VTKIOCITYGML_EXPORT
#  define VTKIOCITYGML_NO_EXPORT
#else
#  ifndef VTKIOCITYGML_EXPORT
#    ifdef vtkIOCityGML_EXPORTS
        /* We are building this library */
#      define VTKIOCITYGML_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOCITYGML_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOCITYGML_NO_EXPORT
#    define VTKIOCITYGML_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOCITYGML_DEPRECATED
#  define VTKIOCITYGML_DEPRECATED __declspec(deprecated)
#  define VTKIOCITYGML_DEPRECATED_EXPORT VTKIOCITYGML_EXPORT __declspec(deprecated)
#  define VTKIOCITYGML_DEPRECATED_NO_EXPORT VTKIOCITYGML_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOCITYGML_NO_DEPRECATED
#endif



#endif
