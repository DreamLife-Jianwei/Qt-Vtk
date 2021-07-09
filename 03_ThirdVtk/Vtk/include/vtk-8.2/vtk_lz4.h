/*=========================================================================

  Program:   ParaView
  Module:    vtk_lz4.h.in

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_lz4_h
#define vtk_lz4_h

/* #undef VTK_USE_SYSTEM_LZ4 */
#ifdef VTK_USE_SYSTEM_LZ4
# include <lz4.h>
#else
# include <vtklz4/lib/lz4.h>
#endif

#endif
