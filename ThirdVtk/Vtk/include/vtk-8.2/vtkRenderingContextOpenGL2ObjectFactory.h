/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRenderingContextOpenGL2ObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkRenderingContextOpenGL2ObjectFactory_h
#define vtkRenderingContextOpenGL2ObjectFactory_h

#include "vtkRenderingContextOpenGL2Module.h" // For export macro
#include "vtkObjectFactory.h"

class VTKRENDERINGCONTEXTOPENGL2_EXPORT vtkRenderingContextOpenGL2ObjectFactory : public vtkObjectFactory
{
public:
  static vtkRenderingContextOpenGL2ObjectFactory * New();
  vtkTypeMacro(vtkRenderingContextOpenGL2ObjectFactory, vtkObjectFactory)

  const char * GetDescription() override { return "vtkRenderingContextOpenGL2 factory overrides."; }

  const char * GetVTKSourceVersion() override;

  void PrintSelf(ostream &os, vtkIndent indent) override;

protected:
  vtkRenderingContextOpenGL2ObjectFactory();

private:
  vtkRenderingContextOpenGL2ObjectFactory(const vtkRenderingContextOpenGL2ObjectFactory&) = delete;
  void operator=(const vtkRenderingContextOpenGL2ObjectFactory&) = delete;
};

#endif // vtkRenderingContextOpenGL2ObjectFactory_h
