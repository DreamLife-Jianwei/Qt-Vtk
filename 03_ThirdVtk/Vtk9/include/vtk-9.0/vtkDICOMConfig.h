/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2019 David Gobbi
  All rights reserved.
  See Copyright.txt or http://www.cognitive-antics.net/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkDICOMConfig_h
#define vtkDICOMConfig_h

/* Configuration information. */
#define DICOM_BUILD_SHARED_LIBS
/* #undef DICOM_BUILD_TESTING */
/* #undef DICOM_USE_GDCM */
/* #undef DICOM_USE_DCMTK */
/* #undef DICOM_USE_SQLITE */
#define DICOM_USE_VTKZLIB

/* Version number. */
#define DICOM_MAJOR_VERSION 0
#define DICOM_MINOR_VERSION 8
#define DICOM_PATCH_VERSION 12
#define DICOM_SHORT_VERSION "0.8"
#define DICOM_VERSION "0.8.12"

/* Legacy (for backwards compatibility) */
#define DICOM_BUILD_VERSION DICOM_PATCH_VERSION

/* To support 'override' for C++11 compilers */
#define VTK_DICOM_OVERRIDE override
/* To support '=delete' for C++11 compilers */
#define VTK_DICOM_DELETE = delete

#endif
