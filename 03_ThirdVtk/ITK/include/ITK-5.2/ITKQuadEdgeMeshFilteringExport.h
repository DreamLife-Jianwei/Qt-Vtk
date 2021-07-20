
#ifndef ITKQuadEdgeMeshFiltering_EXPORT_H
#define ITKQuadEdgeMeshFiltering_EXPORT_H

#ifdef ITK_STATIC
#  define ITKQuadEdgeMeshFiltering_EXPORT
#  define ITKQuadEdgeMeshFiltering_HIDDEN
#else
#  ifndef ITKQuadEdgeMeshFiltering_EXPORT
#    ifdef ITKQuadEdgeMeshFiltering_EXPORTS
        /* We are building this library */
#      define ITKQuadEdgeMeshFiltering_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKQuadEdgeMeshFiltering_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKQuadEdgeMeshFiltering_HIDDEN
#    define ITKQuadEdgeMeshFiltering_HIDDEN 
#  endif
#endif

#ifndef ITKQUADEDGEMESHFILTERING_DEPRECATED
#  define ITKQUADEDGEMESHFILTERING_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKQUADEDGEMESHFILTERING_DEPRECATED_EXPORT
#  define ITKQUADEDGEMESHFILTERING_DEPRECATED_EXPORT ITKQuadEdgeMeshFiltering_EXPORT ITKQUADEDGEMESHFILTERING_DEPRECATED
#endif

#ifndef ITKQUADEDGEMESHFILTERING_DEPRECATED_NO_EXPORT
#  define ITKQUADEDGEMESHFILTERING_DEPRECATED_NO_EXPORT ITKQuadEdgeMeshFiltering_HIDDEN ITKQUADEDGEMESHFILTERING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKQUADEDGEMESHFILTERING_NO_DEPRECATED
#    define ITKQUADEDGEMESHFILTERING_NO_DEPRECATED
#  endif
#endif

#endif /* ITKQuadEdgeMeshFiltering_EXPORT_H */
