
#ifndef ITKImageFeature_EXPORT_H
#define ITKImageFeature_EXPORT_H

#ifdef ITK_STATIC
#  define ITKImageFeature_EXPORT
#  define ITKImageFeature_HIDDEN
#else
#  ifndef ITKImageFeature_EXPORT
#    ifdef ITKImageFeature_EXPORTS
        /* We are building this library */
#      define ITKImageFeature_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKImageFeature_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKImageFeature_HIDDEN
#    define ITKImageFeature_HIDDEN 
#  endif
#endif

#ifndef ITKIMAGEFEATURE_DEPRECATED
#  define ITKIMAGEFEATURE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIMAGEFEATURE_DEPRECATED_EXPORT
#  define ITKIMAGEFEATURE_DEPRECATED_EXPORT ITKImageFeature_EXPORT ITKIMAGEFEATURE_DEPRECATED
#endif

#ifndef ITKIMAGEFEATURE_DEPRECATED_NO_EXPORT
#  define ITKIMAGEFEATURE_DEPRECATED_NO_EXPORT ITKImageFeature_HIDDEN ITKIMAGEFEATURE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIMAGEFEATURE_NO_DEPRECATED
#    define ITKIMAGEFEATURE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKImageFeature_EXPORT_H */
