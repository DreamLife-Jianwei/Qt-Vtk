
#ifndef ITKSpatialObjects_EXPORT_H
#define ITKSpatialObjects_EXPORT_H

#ifdef ITK_STATIC
#  define ITKSpatialObjects_EXPORT
#  define ITKSpatialObjects_HIDDEN
#else
#  ifndef ITKSpatialObjects_EXPORT
#    ifdef ITKSpatialObjects_EXPORTS
        /* We are building this library */
#      define ITKSpatialObjects_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKSpatialObjects_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKSpatialObjects_HIDDEN
#    define ITKSpatialObjects_HIDDEN 
#  endif
#endif

#ifndef ITKSPATIALOBJECTS_DEPRECATED
#  define ITKSPATIALOBJECTS_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKSPATIALOBJECTS_DEPRECATED_EXPORT
#  define ITKSPATIALOBJECTS_DEPRECATED_EXPORT ITKSpatialObjects_EXPORT ITKSPATIALOBJECTS_DEPRECATED
#endif

#ifndef ITKSPATIALOBJECTS_DEPRECATED_NO_EXPORT
#  define ITKSPATIALOBJECTS_DEPRECATED_NO_EXPORT ITKSpatialObjects_HIDDEN ITKSPATIALOBJECTS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKSPATIALOBJECTS_NO_DEPRECATED
#    define ITKSPATIALOBJECTS_NO_DEPRECATED
#  endif
#endif

#endif /* ITKSpatialObjects_EXPORT_H */
