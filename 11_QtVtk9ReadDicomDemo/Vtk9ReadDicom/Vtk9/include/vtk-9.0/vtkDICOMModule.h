
#ifndef VTKDICOM_EXPORT_H
#define VTKDICOM_EXPORT_H

#ifdef VTKDICOM_STATIC_DEFINE
#  define VTKDICOM_EXPORT
#  define VTKDICOM_NO_EXPORT
#else
#  ifndef VTKDICOM_EXPORT
#    ifdef DICOM_EXPORTS
        /* We are building this library */
#      define VTKDICOM_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKDICOM_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKDICOM_NO_EXPORT
#    define VTKDICOM_NO_EXPORT 
#  endif
#endif

#ifndef VTKDICOM_DEPRECATED
#  define VTKDICOM_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKDICOM_DEPRECATED_EXPORT
#  define VTKDICOM_DEPRECATED_EXPORT VTKDICOM_EXPORT VTKDICOM_DEPRECATED
#endif

#ifndef VTKDICOM_DEPRECATED_NO_EXPORT
#  define VTKDICOM_DEPRECATED_NO_EXPORT VTKDICOM_NO_EXPORT VTKDICOM_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKDICOM_NO_DEPRECATED
#    define VTKDICOM_NO_DEPRECATED
#  endif
#endif

#endif /* VTKDICOM_EXPORT_H */
