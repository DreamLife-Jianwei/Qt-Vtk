
#ifndef ITKIOStimulate_EXPORT_H
#define ITKIOStimulate_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOStimulate_EXPORT
#  define ITKIOStimulate_HIDDEN
#else
#  ifndef ITKIOStimulate_EXPORT
#    ifdef ITKIOStimulate_EXPORTS
        /* We are building this library */
#      define ITKIOStimulate_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOStimulate_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOStimulate_HIDDEN
#    define ITKIOStimulate_HIDDEN 
#  endif
#endif

#ifndef ITKIOSTIMULATE_DEPRECATED
#  define ITKIOSTIMULATE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOSTIMULATE_DEPRECATED_EXPORT
#  define ITKIOSTIMULATE_DEPRECATED_EXPORT ITKIOStimulate_EXPORT ITKIOSTIMULATE_DEPRECATED
#endif

#ifndef ITKIOSTIMULATE_DEPRECATED_NO_EXPORT
#  define ITKIOSTIMULATE_DEPRECATED_NO_EXPORT ITKIOStimulate_HIDDEN ITKIOSTIMULATE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOSTIMULATE_NO_DEPRECATED
#    define ITKIOSTIMULATE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOStimulate_EXPORT_H */
