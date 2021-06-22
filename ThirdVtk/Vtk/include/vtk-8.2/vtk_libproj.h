/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_libproj.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_libproj_h
#define vtk_libproj_h

/* Use the libproj library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_LIBPROJ */
#ifdef VTK_USE_SYSTEM_LIBPROJ
# include <projects.h>
# include <proj_api.h>
# include <geodesic.h>
#else
# include <vtklibproj/src/projects.h>
# include <vtklibproj/src/proj_api.h>
# include <vtklibproj/src/geodesic.h>
#endif

#endif
