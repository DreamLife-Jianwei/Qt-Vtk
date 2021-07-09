
#ifndef VTKIOXMLPARSER_EXPORT_H
#define VTKIOXMLPARSER_EXPORT_H

#ifdef VTKIOXMLPARSER_STATIC_DEFINE
#  define VTKIOXMLPARSER_EXPORT
#  define VTKIOXMLPARSER_NO_EXPORT
#else
#  ifndef VTKIOXMLPARSER_EXPORT
#    ifdef vtkIOXMLParser_EXPORTS
        /* We are building this library */
#      define VTKIOXMLPARSER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOXMLPARSER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOXMLPARSER_NO_EXPORT
#    define VTKIOXMLPARSER_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOXMLPARSER_DEPRECATED
#  define VTKIOXMLPARSER_DEPRECATED __declspec(deprecated)
#  define VTKIOXMLPARSER_DEPRECATED_EXPORT VTKIOXMLPARSER_EXPORT __declspec(deprecated)
#  define VTKIOXMLPARSER_DEPRECATED_NO_EXPORT VTKIOXMLPARSER_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOXMLPARSER_NO_DEPRECATED
#endif



#endif
