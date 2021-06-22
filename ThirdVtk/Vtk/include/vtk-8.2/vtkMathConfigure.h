// -*- c++ -*-
/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMathConfigure.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*----------------------------------------------------------------------------
 Copyright (c) Sandia Corporation
 See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.
----------------------------------------------------------------------------*/

#ifndef vtkMathConfigure_h
#define vtkMathConfigure_h

#include <cmath>
#include <float.h> // for _isnan, _finite on Win32

#define VTK_HAS_ISNAN
#define VTK_HAS_STD_ISNAN
/* #undef VTK_HAS__ISNAN */
#define VTK_HAS_ISINF
#define VTK_HAS_STD_ISINF
#define VTK_HAS_ISFINITE
#define VTK_HAS_STD_ISFINITE
/* #undef VTK_HAS_FINITE */
/* #undef VTK_HAS__FINITE */

// Check for undetected macro versions of isnan(), isinf(), isfinite()
#if !defined(VTK_HAS_ISNAN) && defined(isnan)
# define VTK_HAS_ISNAN 1
#endif
#if !defined(VTK_HAS_ISINF) && defined(isinf)
# define VTK_HAS_ISINF 1
#endif
#if !defined(VTK_HAS_ISFINITE) && defined(isfinite)
# define VTK_HAS_ISFINITE 1
#endif
#if !defined(VTK_HAS_FINITE) && defined(finite)
# define VTK_HAS_FINITE 1
#endif

// Make macros from _isnan(), _finite() if they exist (there is no _isinf)
#if !defined(VTK_HAS_ISNAN) && (defined(VTK_HAS__ISNAN) || defined(_isnan))
# define isnan(x) _isnan(x)
# define VTK_HAS_ISNAN 1
#endif
#if !defined(VTK_HAS_FINITE) && (defined(VTK_HAS__FINITE) || defined(_finite))
# define finite(x) _finite(x)
# define VTK_HAS_FINITE 1
#endif

// The CUDA compiler(nvcc) is a secondary compiler that is used beside
// your host compiler. While your host compiler can support std::isnan and
// other functions, the CUDA compiler doesn't. Because the CUDA compiler is
// given both host and device code to parse it will then fail when it sees
// std::isnan because it is in the vtkMath header and not the
// implementation file. To get around this issue we check __CUDACC__ which
// is only set when we are compiling with the CUDA compiler
#ifdef __CUDACC__

#if defined(VTK_HAS_STD_ISINF)
#undef VTK_HAS_STD_ISINF
#endif

#if defined(VTK_HAS_STD_ISNAN)
#undef VTK_HAS_STD_ISNAN
#endif

#if defined(VTK_HAS_STD_ISFINITE)
#undef VTK_HAS_STD_ISFINITE
#endif

#endif

// We pretty much assume that all compilers are going to provide
// std::numeric_limits methods in the limits header.  On of the Borland
// dashboard compilers failed to link in the methods, so we have a special
// case here.  If we find more platforms that do not support it correctly,
// then we should probably implement a TRY_COMPILE in the CMakeLists.txt.
#if !(defined(__BORLANDC__) && (__BORLANDC__ < 0x660))
# define VTK_HAS_STD_NUMERIC_LIMITS
#endif

// If the isnan or isinf function does not exist, then our next attempt is to
// use comparisons to determine if the number is not finite.  Although these
// comparisons should be valid, some systems raise exceptions anyway (possibly
// because exceptions for really bad operations like division by 0 are on).
// This flag will instruct vtkMath not to make these comparisons.  (The next
// fallback is to do IEEE-754 bit comparisons.)
#if defined(__BORLANDC__) && (__BORLANDC__ < 0x660)
# define VTK_NON_FINITE_CAUSES_EXCEPTIONS
#endif

#endif //vtkMathConfigure_h
