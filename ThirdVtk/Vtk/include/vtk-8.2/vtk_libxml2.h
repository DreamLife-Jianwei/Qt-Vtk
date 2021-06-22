/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_libxml2.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_libxml2_h
#define vtk_libxml2_h

/* Use the libxml2 library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_LIBXML2 */
#ifdef VTK_USE_SYSTEM_LIBXML2
# define VTKLIBXML2_HEADER_DIR libxml
#else
# define VTKLIBXML2_HEADER_DIR vtklibxml2/libxml
# include "vtkConfigure.h"
# ifndef VTK_BUILD_SHARED_LIBS
#  ifndef LIBXML_STATIC
#   define LIBXML_STATIC
#  endif
# endif
#endif

/* Macro to help include a header file from the libxml2 configured for
   VTK.  Since libxml2 has many public header files we cannot just
   include them all here.  Instead user code can include this header
   first and then use the macro to construct the name of the desired
   header:

   #include "vtk_libxml2.h"
   #include VTKLIBXML2_HEADER(xmlstring.h)
*/
#define VTKLIBXML2_HEADER(x)  VTKLIBXML2_HEADER0(VTKLIBXML2_HEADER_DIR/x)
#define VTKLIBXML2_HEADER0(x) VTKLIBXML2_HEADER1(x)
#define VTKLIBXML2_HEADER1(x) <x>

/* Include the top-level header here.  */
#include VTKLIBXML2_HEADER(xmlversion.h)

#endif
