
#ifndef ITKIOTransformInsightLegacy_EXPORT_H
#define ITKIOTransformInsightLegacy_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOTransformInsightLegacy_EXPORT
#  define ITKIOTransformInsightLegacy_HIDDEN
#else
#  ifndef ITKIOTransformInsightLegacy_EXPORT
#    ifdef ITKIOTransformInsightLegacy_EXPORTS
        /* We are building this library */
#      define ITKIOTransformInsightLegacy_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOTransformInsightLegacy_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOTransformInsightLegacy_HIDDEN
#    define ITKIOTransformInsightLegacy_HIDDEN 
#  endif
#endif

#ifndef ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED
#  define ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED_EXPORT
#  define ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED_EXPORT ITKIOTransformInsightLegacy_EXPORT ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED
#endif

#ifndef ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED_NO_EXPORT
#  define ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED_NO_EXPORT ITKIOTransformInsightLegacy_HIDDEN ITKIOTRANSFORMINSIGHTLEGACY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOTRANSFORMINSIGHTLEGACY_NO_DEPRECATED
#    define ITKIOTRANSFORMINSIGHTLEGACY_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOTransformInsightLegacy_EXPORT_H */
