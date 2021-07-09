/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_utf8.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_utf8_h
#define vtk_utf8_h

/* Use the utf8 library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_UTF8 */
#ifdef VTK_USE_SYSTEM_UTF8
# include <utf8.h>
#else
# include <vtkutf8/utf8.h>
#endif

#endif
