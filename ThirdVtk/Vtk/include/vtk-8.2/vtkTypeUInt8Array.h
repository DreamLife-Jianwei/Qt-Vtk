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
// .NAME vtkTypeUInt8Array - dynamic, self-adjusting array of vtkTypeUInt8
// .SECTION Description
// vtkTypeUInt8Array is an array of values of type vtkTypeUInt8.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt8 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeUInt8Array_h
#define vtkTypeUInt8Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_UINT8 == VTK_UNSIGNED_CHAR
# include "vtkUnsignedCharArray.h"
# define vtkTypeArrayBase vtkUnsignedCharArray
#endif

class VTKCOMMONCORE_EXPORT vtkTypeUInt8Array : public vtkTypeArrayBase
{
public:
  static vtkTypeUInt8Array* New();
  vtkTypeMacro(vtkTypeUInt8Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeUInt8Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeUInt8Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeUInt8Array();
  ~vtkTypeUInt8Array() override;

private:
  vtkTypeUInt8Array(const vtkTypeUInt8Array&) = delete;
  void operator=(const vtkTypeUInt8Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeUInt8Array)

#undef vtkTypeArrayBase

#endif
// VTK-HeaderTest-Exclude: vtkTypedArray.h.in
