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
// .NAME vtkTypeUInt32Array - dynamic, self-adjusting array of vtkTypeUInt32
// .SECTION Description
// vtkTypeUInt32Array is an array of values of type vtkTypeUInt32.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt32 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeUInt32Array_h
#define vtkTypeUInt32Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_UINT32 == VTK_UNSIGNED_INT
# include "vtkUnsignedIntArray.h"
# define vtkTypeArrayBase vtkUnsignedIntArray
#endif

class VTKCOMMONCORE_EXPORT vtkTypeUInt32Array : public vtkTypeArrayBase
{
public:
  static vtkTypeUInt32Array* New();
  vtkTypeMacro(vtkTypeUInt32Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeUInt32Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeUInt32Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeUInt32Array();
  ~vtkTypeUInt32Array() override;

private:
  vtkTypeUInt32Array(const vtkTypeUInt32Array&) = delete;
  void operator=(const vtkTypeUInt32Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeUInt32Array)

#undef vtkTypeArrayBase

#endif
// VTK-HeaderTest-Exclude: vtkTypedArray.h.in
