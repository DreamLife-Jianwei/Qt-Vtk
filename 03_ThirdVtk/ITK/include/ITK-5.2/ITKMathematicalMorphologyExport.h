
#ifndef ITKMathematicalMorphology_EXPORT_H
#define ITKMathematicalMorphology_EXPORT_H

#ifdef ITK_STATIC
#  define ITKMathematicalMorphology_EXPORT
#  define ITKMathematicalMorphology_HIDDEN
#else
#  ifndef ITKMathematicalMorphology_EXPORT
#    ifdef ITKMathematicalMorphology_EXPORTS
        /* We are building this library */
#      define ITKMathematicalMorphology_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKMathematicalMorphology_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKMathematicalMorphology_HIDDEN
#    define ITKMathematicalMorphology_HIDDEN 
#  endif
#endif

#ifndef ITKMATHEMATICALMORPHOLOGY_DEPRECATED
#  define ITKMATHEMATICALMORPHOLOGY_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKMATHEMATICALMORPHOLOGY_DEPRECATED_EXPORT
#  define ITKMATHEMATICALMORPHOLOGY_DEPRECATED_EXPORT ITKMathematicalMorphology_EXPORT ITKMATHEMATICALMORPHOLOGY_DEPRECATED
#endif

#ifndef ITKMATHEMATICALMORPHOLOGY_DEPRECATED_NO_EXPORT
#  define ITKMATHEMATICALMORPHOLOGY_DEPRECATED_NO_EXPORT ITKMathematicalMorphology_HIDDEN ITKMATHEMATICALMORPHOLOGY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKMATHEMATICALMORPHOLOGY_NO_DEPRECATED
#    define ITKMATHEMATICALMORPHOLOGY_NO_DEPRECATED
#  endif
#endif

#endif /* ITKMathematicalMorphology_EXPORT_H */
