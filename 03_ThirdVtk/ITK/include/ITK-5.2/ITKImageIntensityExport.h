
#ifndef ITKImageIntensity_EXPORT_H
#define ITKImageIntensity_EXPORT_H

#ifdef ITK_STATIC
#  define ITKImageIntensity_EXPORT
#  define ITKImageIntensity_HIDDEN
#else
#  ifndef ITKImageIntensity_EXPORT
#    ifdef ITKImageIntensity_EXPORTS
        /* We are building this library */
#      define ITKImageIntensity_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKImageIntensity_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKImageIntensity_HIDDEN
#    define ITKImageIntensity_HIDDEN 
#  endif
#endif

#ifndef ITKIMAGEINTENSITY_DEPRECATED
#  define ITKIMAGEINTENSITY_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIMAGEINTENSITY_DEPRECATED_EXPORT
#  define ITKIMAGEINTENSITY_DEPRECATED_EXPORT ITKImageIntensity_EXPORT ITKIMAGEINTENSITY_DEPRECATED
#endif

#ifndef ITKIMAGEINTENSITY_DEPRECATED_NO_EXPORT
#  define ITKIMAGEINTENSITY_DEPRECATED_NO_EXPORT ITKImageIntensity_HIDDEN ITKIMAGEINTENSITY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIMAGEINTENSITY_NO_DEPRECATED
#    define ITKIMAGEINTENSITY_NO_DEPRECATED
#  endif
#endif

#endif /* ITKImageIntensity_EXPORT_H */
