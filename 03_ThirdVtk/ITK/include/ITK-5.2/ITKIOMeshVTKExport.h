
#ifndef ITKIOMeshVTK_EXPORT_H
#define ITKIOMeshVTK_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshVTK_EXPORT
#  define ITKIOMeshVTK_HIDDEN
#else
#  ifndef ITKIOMeshVTK_EXPORT
#    ifdef ITKIOMeshVTK_EXPORTS
        /* We are building this library */
#      define ITKIOMeshVTK_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshVTK_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshVTK_HIDDEN
#    define ITKIOMeshVTK_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHVTK_DEPRECATED
#  define ITKIOMESHVTK_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHVTK_DEPRECATED_EXPORT
#  define ITKIOMESHVTK_DEPRECATED_EXPORT ITKIOMeshVTK_EXPORT ITKIOMESHVTK_DEPRECATED
#endif

#ifndef ITKIOMESHVTK_DEPRECATED_NO_EXPORT
#  define ITKIOMESHVTK_DEPRECATED_NO_EXPORT ITKIOMeshVTK_HIDDEN ITKIOMESHVTK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHVTK_NO_DEPRECATED
#    define ITKIOMESHVTK_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshVTK_EXPORT_H */
