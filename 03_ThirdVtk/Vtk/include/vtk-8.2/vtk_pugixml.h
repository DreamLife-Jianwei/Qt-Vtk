/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_pugixml.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_pugixml_h
#define vtk_pugixml_h

/* #undef VTK_USE_SYSTEM_PUGIXML */
#ifdef VTK_USE_SYSTEM_PUGIXML
# include <pugixml.hpp>
#else
# include <vtkpugixml/src/pugixml.hpp>
#endif

#endif
