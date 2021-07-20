
#ifndef ITKPDEDeformableRegistration_EXPORT_H
#define ITKPDEDeformableRegistration_EXPORT_H

#ifdef ITK_STATIC
#  define ITKPDEDeformableRegistration_EXPORT
#  define ITKPDEDeformableRegistration_HIDDEN
#else
#  ifndef ITKPDEDeformableRegistration_EXPORT
#    ifdef ITKPDEDeformableRegistration_EXPORTS
        /* We are building this library */
#      define ITKPDEDeformableRegistration_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKPDEDeformableRegistration_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKPDEDeformableRegistration_HIDDEN
#    define ITKPDEDeformableRegistration_HIDDEN 
#  endif
#endif

#ifndef ITKPDEDEFORMABLEREGISTRATION_DEPRECATED
#  define ITKPDEDEFORMABLEREGISTRATION_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKPDEDEFORMABLEREGISTRATION_DEPRECATED_EXPORT
#  define ITKPDEDEFORMABLEREGISTRATION_DEPRECATED_EXPORT ITKPDEDeformableRegistration_EXPORT ITKPDEDEFORMABLEREGISTRATION_DEPRECATED
#endif

#ifndef ITKPDEDEFORMABLEREGISTRATION_DEPRECATED_NO_EXPORT
#  define ITKPDEDEFORMABLEREGISTRATION_DEPRECATED_NO_EXPORT ITKPDEDeformableRegistration_HIDDEN ITKPDEDEFORMABLEREGISTRATION_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKPDEDEFORMABLEREGISTRATION_NO_DEPRECATED
#    define ITKPDEDEFORMABLEREGISTRATION_NO_DEPRECATED
#  endif
#endif

#endif /* ITKPDEDeformableRegistration_EXPORT_H */
