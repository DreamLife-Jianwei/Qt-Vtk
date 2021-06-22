/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_jsoncpp_fwd.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_jsoncpp_fwd_h
#define vtk_jsoncpp_fwd_h

/* Use the JsonCpp library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_JSONCPP */
#ifdef VTK_USE_SYSTEM_JSONCPP
# include <json/>
#else
# include <vtkjsoncpp/json/json-forwards.h>
#endif

#endif
