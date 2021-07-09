/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtk_sqlite.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef vtk_sqlite_h
#define vtk_sqlite_h

/* Use the sqlite library configured for VTK.  */
/* #undef VTK_USE_SYSTEM_SQLITE */

#ifdef VTK_USE_SYSTEM_SQLITE
# include <sqlite3.h>
#else
# include <vtksqlite/sqlite3.h>
#endif

#endif
