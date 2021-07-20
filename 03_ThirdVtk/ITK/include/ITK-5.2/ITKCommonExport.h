
#ifndef ITKCommon_EXPORT_H
#define ITKCommon_EXPORT_H

#ifdef ITK_STATIC
#  define ITKCommon_EXPORT
#  define ITKCommon_HIDDEN
#else
#  ifndef ITKCommon_EXPORT
#    ifdef ITKCommon_EXPORTS
        /* We are building this library */
#      define ITKCommon_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKCommon_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKCommon_HIDDEN
#    define ITKCommon_HIDDEN 
#  endif
#endif

#ifndef ITKCOMMON_DEPRECATED
#  define ITKCOMMON_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKCOMMON_DEPRECATED_EXPORT
#  define ITKCOMMON_DEPRECATED_EXPORT ITKCommon_EXPORT ITKCOMMON_DEPRECATED
#endif

#ifndef ITKCOMMON_DEPRECATED_NO_EXPORT
#  define ITKCOMMON_DEPRECATED_NO_EXPORT ITKCommon_HIDDEN ITKCOMMON_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKCOMMON_NO_DEPRECATED
#    define ITKCOMMON_NO_DEPRECATED
#  endif
#endif

#endif /* ITKCommon_EXPORT_H */
