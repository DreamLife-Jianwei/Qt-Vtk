/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkVersionMacros.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtkVersionMacros_h
#define vtkVersionMacros_h

/* In development versions the minor component is odd and the build
   component encodes a date in CCYYMMDD format.  In release versions
   (or preparation of one) the minor component is even and the build
   component is a small integer patch level.  */
#define VTK_MAJOR_VERSION 8
#define VTK_MINOR_VERSION 2
#define VTK_BUILD_VERSION 0
#define VTK_VERSION "8.2.0"

#endif
