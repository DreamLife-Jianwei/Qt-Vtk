/*=========================================================================

  Program:   ParaView
  Module:    vtk_lzma.h.in

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_lzma_h
#define vtk_lzma_h

#define LZMA_BUILT_AS_DYNAMIC_LIB 1
#if !LZMA_BUILT_AS_DYNAMIC_LIB
#define LZMA_API_STATIC
#endif

/* #undef VTK_USE_SYSTEM_LZMA */
#ifdef VTK_USE_SYSTEM_LZMA
# include <lzma.h>
#else
# include <vtklzma/src/liblzma/api/lzma.h>
#endif

#endif
