
#ifndef ITKMesh_EXPORT_H
#define ITKMesh_EXPORT_H

#ifdef ITK_STATIC
#  define ITKMesh_EXPORT
#  define ITKMesh_HIDDEN
#else
#  ifndef ITKMesh_EXPORT
#    ifdef ITKMesh_EXPORTS
        /* We are building this library */
#      define ITKMesh_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKMesh_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKMesh_HIDDEN
#    define ITKMesh_HIDDEN 
#  endif
#endif

#ifndef ITKMESH_DEPRECATED
#  define ITKMESH_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKMESH_DEPRECATED_EXPORT
#  define ITKMESH_DEPRECATED_EXPORT ITKMesh_EXPORT ITKMESH_DEPRECATED
#endif

#ifndef ITKMESH_DEPRECATED_NO_EXPORT
#  define ITKMESH_DEPRECATED_NO_EXPORT ITKMesh_HIDDEN ITKMESH_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKMESH_NO_DEPRECATED
#    define ITKMESH_NO_DEPRECATED
#  endif
#endif

#endif /* ITKMesh_EXPORT_H */
