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
// .NAME vtkTypeInt8Array - dynamic, self-adjusting array of vtkTypeInt8
// .SECTION Description
// vtkTypeInt8Array is an array of values of type vtkTypeInt8.  It
// provides methods for insertion and retrieval of values and will
// automatically resize itself to hold new data.
//
// This array should be preferred for data of type Int8 as this
// array will use the correct underlying datatype based on the desired number of bits
// and the current platform.  The superclass of this type will change depending on the
// machine and compiler in use so that the data contained always uses the proper type.

#ifndef vtkTypeInt8Array_h
#define vtkTypeInt8Array_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkType.h" // For native type selections.

#if VTK_TYPE_INT8 == VTK_CHAR
# include "vtkCharArray.h"
# define vtkTypeArrayBase vtkCharArray
#else
# include "vtkSignedCharArray.h"
# define vtkTypeArrayBase vtkSignedCharArray
#endif

class VTKCOMMONCORE_EXPORT vtkTypeInt8Array : public vtkTypeArrayBase
{
public:
  static vtkTypeInt8Array* New();
  vtkTypeMacro(vtkTypeInt8Array,vtkTypeArrayBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // Description:
  // A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
  static vtkTypeInt8Array* FastDownCast(vtkAbstractArray *source)
  {
    return static_cast<vtkTypeInt8Array*>(Superclass::FastDownCast(source));
  }

protected:
  vtkTypeInt8Array();
  ~vtkTypeInt8Array() override;

private:
  vtkTypeInt8Array(const vtkTypeInt8Array&) = delete;
  void operator=(const vtkTypeInt8Array&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkTypeInt8Array)

#undef vtkTypeArrayBase

#endif
// VTK-HeaderTest-Exclude: vtkTypedArray.h.in
