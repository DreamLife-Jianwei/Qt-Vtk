
#ifndef ITKIOTransformBase_EXPORT_H
#define ITKIOTransformBase_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOTransformBase_EXPORT
#  define ITKIOTransformBase_HIDDEN
#else
#  ifndef ITKIOTransformBase_EXPORT
#    ifdef ITKIOTransformBase_EXPORTS
        /* We are building this library */
#      define ITKIOTransformBase_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOTransformBase_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOTransformBase_HIDDEN
#    define ITKIOTransformBase_HIDDEN 
#  endif
#endif

#ifndef ITKIOTRANSFORMBASE_DEPRECATED
#  define ITKIOTRANSFORMBASE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOTRANSFORMBASE_DEPRECATED_EXPORT
#  define ITKIOTRANSFORMBASE_DEPRECATED_EXPORT ITKIOTransformBase_EXPORT ITKIOTRANSFORMBASE_DEPRECATED
#endif

#ifndef ITKIOTRANSFORMBASE_DEPRECATED_NO_EXPORT
#  define ITKIOTRANSFORMBASE_DEPRECATED_NO_EXPORT ITKIOTransformBase_HIDDEN ITKIOTRANSFORMBASE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOTRANSFORMBASE_NO_DEPRECATED
#    define ITKIOTRANSFORMBASE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOTransformBase_EXPORT_H */
