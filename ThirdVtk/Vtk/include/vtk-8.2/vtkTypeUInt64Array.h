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
// .NAME vtkTypeUInt64Array - dynamic, self-adjusting array of vtkTypeUInt64
// .SECTION Description
// vtkTypeUInt64Array is an array of values of type vtkTypeUInt64.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type UInt64 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeUInt64Array_h
#define vtkTypeUInt64Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_UINT64 == VTK_UNSIGNED_LONG
# include "vtkUnsignedLongArray.h"
# define vtkTypeArrayBase vtkUnsignedLongArray
#elif VTK_TYPE_UINT64 == VTK_UNSIGNED_LONG_LONG
# include "vtkUnsignedLongLongArray.h"
# define vtkTypeArrayBase vtkUnsignedLongLongArray
#endif

class VTKCOMMONCORE_EXPORT vtkTypeUInt64Array : public vtkTypeArrayBase
{
public:
  static vtkTypeUInt64Array* New();
  vtkTypeMacro(vtkTypeUInt64Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeUInt64Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeUInt64Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeUInt64Array();
  ~vtkTypeUInt64Array() override;

private:
  vtkTypeUInt64Array(const vtkTypeUInt64Array&) = delete;
  void operator=(const vtkTypeUInt64Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeUInt64Array)

#undef vtkTypeArrayBase

#endif
// VTK-HeaderTest-Exclude: vtkTypedArray.h.in
