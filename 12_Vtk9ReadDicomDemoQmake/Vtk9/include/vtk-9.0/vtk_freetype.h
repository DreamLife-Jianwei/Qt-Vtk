/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_freetype.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_freetype_h
#define vtk_freetype_h

/* Use the freetype library configured for VTK.  */
#define VTK_MODULE_USE_EXTERNAL_vtkfreetype 0

#define VTK_FREETYPE_SHARED 1
#if VTK_FREETYPE_SHARED && defined(_WIN32)
#define FT2_DLLIMPORT
#endif

#if VTK_MODULE_USE_EXTERNAL_vtkfreetype
# include <ft2build.h>
#else
# include <vtkfreetype/include/ft2build.h>
#endif

#endif // #ifndef vtk_freetype_h
