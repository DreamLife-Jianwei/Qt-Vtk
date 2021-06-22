
#ifndef VTKCOMMONMISC_EXPORT_H
#define VTKCOMMONMISC_EXPORT_H

#ifdef VTKCOMMONMISC_STATIC_DEFINE
#  define VTKCOMMONMISC_EXPORT
#  define VTKCOMMONMISC_NO_EXPORT
#else
#  ifndef VTKCOMMONMISC_EXPORT
#    ifdef vtkCommonMisc_EXPORTS
        /* We are building this library */
#      define VTKCOMMONMISC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONMISC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONMISC_NO_EXPORT
#    define VTKCOMMONMISC_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONMISC_DEPRECATED
#  define VTKCOMMONMISC_DEPRECATED __declspec(deprecated)
#  define VTKCOMMONMISC_DEPRECATED_EXPORT VTKCOMMONMISC_EXPORT __declspec(deprecated)
#  define VTKCOMMONMISC_DEPRECATED_NO_EXPORT VTKCOMMONMISC_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKCOMMONMISC_NO_DEPRECATED
#endif



#endif
