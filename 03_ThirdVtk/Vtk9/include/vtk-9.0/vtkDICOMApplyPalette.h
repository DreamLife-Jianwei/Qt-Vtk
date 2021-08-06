/*=========================================================================

  Program: DICOM for VTK

  Copyright (c) 2012-2019 David Gobbi
  All rights reserved.
  See Copyright.txt or http://dgobbi.github.io/bsd3.txt for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * \class vtkDICOMApplyPalette
 * \brief Apply palette to PALETTE COLOR images
 *
 * If an image contains a palette LUT, then this filter will apply that
 * LUT to the image and produce an RGB image.  Images without a palette
 * LUT will pass through unchanged.  If the image uses a supplemental
 * palette that only applies to a specific range of pixel values, then
 * pixel values outside of that range will be mapped to greyscale via
 * the WindowWidth and WindowCenter specified in the image.
 *
 * \warning If this filter is used, then AutoRescaleOff() should be set on
 * the reader to ensure that the reader does not rescale the data.
 */

#ifndef vtkDICOMApplyPalette_h
#define vtkDICOMApplyPalette_h

#include "vtkDICOMAlgorithm.h"
#include "vtkDICOMModule.h" // For export macro

class vtkDICOMMetaData;
class vtkDICOMPerFilePalette;

//----------------------------------------------------------------------------
class VTKDICOM_EXPORT vtkDICOMApplyPalette : public vtkDICOMAlgorithm
{
public:
  static vtkDICOMApplyPalette *New();
  vtkTypeMacro(vtkDICOMApplyPalette, vtkDICOMAlgorithm);

  //! Print information about this object.
  void PrintSelf(ostream& os, vtkIndent indent) VTK_DICOM_OVERRIDE;

protected:
  vtkDICOMApplyPalette();
  ~vtkDICOMApplyPalette() VTK_DICOM_OVERRIDE;

  int RequestInformation(
    vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) VTK_DICOM_OVERRIDE;

  int RequestData(
    vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) VTK_DICOM_OVERRIDE;

  void ThreadedRequestData(
    vtkInformation *request, vtkInformationVector **inputVector,
    vtkInformationVector *outputVector, vtkImageData ***inData,
    vtkImageData **outData, int ext[6], int id) VTK_DICOM_OVERRIDE;

  //! Container for the lookup tables used.
  vtkDICOMPerFilePalette *Palette;

  //! True if palette is supplemental.
  bool IsSupplemental;

private:
#ifdef VTK_DICOM_DELETE
  vtkDICOMApplyPalette(const vtkDICOMApplyPalette&) VTK_DICOM_DELETE;
  void operator=(const vtkDICOMApplyPalette&) VTK_DICOM_DELETE;
#else
  vtkDICOMApplyPalette(const vtkDICOMApplyPalette&) = delete;
  void operator=(const vtkDICOMApplyPalette&) = delete;
#endif
};

#endif // vtkDICOMApplyPalette_h
