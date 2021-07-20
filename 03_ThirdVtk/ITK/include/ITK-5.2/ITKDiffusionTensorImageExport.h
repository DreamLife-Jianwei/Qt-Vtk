
#ifndef ITKDiffusionTensorImage_EXPORT_H
#define ITKDiffusionTensorImage_EXPORT_H

#ifdef ITK_STATIC
#  define ITKDiffusionTensorImage_EXPORT
#  define ITKDiffusionTensorImage_HIDDEN
#else
#  ifndef ITKDiffusionTensorImage_EXPORT
#    ifdef ITKDiffusionTensorImage_EXPORTS
        /* We are building this library */
#      define ITKDiffusionTensorImage_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKDiffusionTensorImage_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKDiffusionTensorImage_HIDDEN
#    define ITKDiffusionTensorImage_HIDDEN 
#  endif
#endif

#ifndef ITKDIFFUSIONTENSORIMAGE_DEPRECATED
#  define ITKDIFFUSIONTENSORIMAGE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKDIFFUSIONTENSORIMAGE_DEPRECATED_EXPORT
#  define ITKDIFFUSIONTENSORIMAGE_DEPRECATED_EXPORT ITKDiffusionTensorImage_EXPORT ITKDIFFUSIONTENSORIMAGE_DEPRECATED
#endif

#ifndef ITKDIFFUSIONTENSORIMAGE_DEPRECATED_NO_EXPORT
#  define ITKDIFFUSIONTENSORIMAGE_DEPRECATED_NO_EXPORT ITKDiffusionTensorImage_HIDDEN ITKDIFFUSIONTENSORIMAGE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKDIFFUSIONTENSORIMAGE_NO_DEPRECATED
#    define ITKDIFFUSIONTENSORIMAGE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKDiffusionTensorImage_EXPORT_H */
