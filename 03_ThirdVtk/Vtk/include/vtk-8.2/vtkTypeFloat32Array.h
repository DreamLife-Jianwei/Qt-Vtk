/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkTypedArray.h.in

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkTypeFloat32Array - dynamic, self-adjusting array of vtkTypeFloat32
// .SECTION Description
// vtkTypeFloat32Array is an array of values of type vtkTypeFloat32.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Float32 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeFloat32Array_h
#define vtkTypeFloat32Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_FLOAT32 == VTK_FLOAT
# include "vtkFloatArray.h"
# define vtkTypeArrayBase vtkFloatArray
#endif

class VTKCOMMONCORE_EXPORT vtkTypeFloat32Array : public vtkTypeArrayBase
{
public:
  static vtkTypeFloat32Array* New();
  vtkTypeMacro(vtkTypeFloat32Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeFloat32Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeFloat32Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeFloat32Array();
  ~vtkTypeFloat32Array() override;

private:
  vtkTypeFloat32Array(const vtkTypeFloat32Array&) = delete;
  void operator=(const vtkTypeFloat32Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeFloat32Array)

#undef vtkTypeArrayBase

#endif
// VTK-HeaderTest-Exclude: vtkTypedArray.h.in
