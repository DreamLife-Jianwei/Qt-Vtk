/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_doubleconversion.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_doubleconversion_h
#define vtk_doubleconversion_h

/* #undef VTK_USE_SYSTEM_DOUBLECONVERSION */

#ifndef VTK_USE_SYSTEM_DOUBLECONVERSION
#define VTK_DOUBLECONVERSION_QUOTE_HEADER_NAME(str) #str
#  define VTK_DOUBLECONVERSION_HEADER(header) VTK_DOUBLECONVERSION_QUOTE_HEADER_NAME(vtkdoubleconversion/double-conversion/header)
#else
#  define VTK_DOUBLECONVERSION_HEADER(header) #header
#endif

#endif
