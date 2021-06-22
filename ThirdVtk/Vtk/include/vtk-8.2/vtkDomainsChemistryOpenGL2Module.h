
#ifndef VTKDOMAINSCHEMISTRYOPENGL2_EXPORT_H
#define VTKDOMAINSCHEMISTRYOPENGL2_EXPORT_H

#ifdef VTKDOMAINSCHEMISTRYOPENGL2_STATIC_DEFINE
#  define VTKDOMAINSCHEMISTRYOPENGL2_EXPORT
#  define VTKDOMAINSCHEMISTRYOPENGL2_NO_EXPORT
#else
#  ifndef VTKDOMAINSCHEMISTRYOPENGL2_EXPORT
#    ifdef vtkDomainsChemistryOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKDOMAINSCHEMISTRYOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKDOMAINSCHEMISTRYOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKDOMAINSCHEMISTRYOPENGL2_NO_EXPORT
#    define VTKDOMAINSCHEMISTRYOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKDOMAINSCHEMISTRYOPENGL2_DEPRECATED
#  define VTKDOMAINSCHEMISTRYOPENGL2_DEPRECATED __declspec(deprecated)
#  define VTKDOMAINSCHEMISTRYOPENGL2_DEPRECATED_EXPORT VTKDOMAINSCHEMISTRYOPENGL2_EXPORT __declspec(deprecated)
#  define VTKDOMAINSCHEMISTRYOPENGL2_DEPRECATED_NO_EXPORT VTKDOMAINSCHEMISTRYOPENGL2_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKDOMAINSCHEMISTRYOPENGL2_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkDomainsChemistryModule.h"
#include "vtkDomainsChemistryModule.h"
#include "vtkRenderingOpenGL2Module.h"

/* AutoInit implementations.  */
#if defined(vtkDomainsChemistryOpenGL2_INCLUDE)
# include vtkDomainsChemistryOpenGL2_INCLUDE
#endif
#if defined(vtkDomainsChemistryOpenGL2_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkDomainsChemistryOpenGL2)
#endif

#endif
