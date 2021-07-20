
#ifndef ITKIOMeshOBJ_EXPORT_H
#define ITKIOMeshOBJ_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshOBJ_EXPORT
#  define ITKIOMeshOBJ_HIDDEN
#else
#  ifndef ITKIOMeshOBJ_EXPORT
#    ifdef ITKIOMeshOBJ_EXPORTS
        /* We are building this library */
#      define ITKIOMeshOBJ_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshOBJ_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshOBJ_HIDDEN
#    define ITKIOMeshOBJ_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHOBJ_DEPRECATED
#  define ITKIOMESHOBJ_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHOBJ_DEPRECATED_EXPORT
#  define ITKIOMESHOBJ_DEPRECATED_EXPORT ITKIOMeshOBJ_EXPORT ITKIOMESHOBJ_DEPRECATED
#endif

#ifndef ITKIOMESHOBJ_DEPRECATED_NO_EXPORT
#  define ITKIOMESHOBJ_DEPRECATED_NO_EXPORT ITKIOMeshOBJ_HIDDEN ITKIOMESHOBJ_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHOBJ_NO_DEPRECATED
#    define ITKIOMESHOBJ_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshOBJ_EXPORT_H */
