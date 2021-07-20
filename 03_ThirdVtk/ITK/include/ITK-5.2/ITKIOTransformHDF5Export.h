
#ifndef ITKIOTransformHDF5_EXPORT_H
#define ITKIOTransformHDF5_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOTransformHDF5_EXPORT
#  define ITKIOTransformHDF5_HIDDEN
#else
#  ifndef ITKIOTransformHDF5_EXPORT
#    ifdef ITKIOTransformHDF5_EXPORTS
        /* We are building this library */
#      define ITKIOTransformHDF5_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOTransformHDF5_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOTransformHDF5_HIDDEN
#    define ITKIOTransformHDF5_HIDDEN 
#  endif
#endif

#ifndef ITKIOTRANSFORMHDF5_DEPRECATED
#  define ITKIOTRANSFORMHDF5_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOTRANSFORMHDF5_DEPRECATED_EXPORT
#  define ITKIOTRANSFORMHDF5_DEPRECATED_EXPORT ITKIOTransformHDF5_EXPORT ITKIOTRANSFORMHDF5_DEPRECATED
#endif

#ifndef ITKIOTRANSFORMHDF5_DEPRECATED_NO_EXPORT
#  define ITKIOTRANSFORMHDF5_DEPRECATED_NO_EXPORT ITKIOTransformHDF5_HIDDEN ITKIOTRANSFORMHDF5_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOTRANSFORMHDF5_NO_DEPRECATED
#    define ITKIOTRANSFORMHDF5_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOTransformHDF5_EXPORT_H */
