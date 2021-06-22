/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOExportOpenGL2ObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkIOExportOpenGL2ObjectFactory_h
#define vtkIOExportOpenGL2ObjectFactory_h

#include "vtkIOExportOpenGL2Module.h" // For export macro
#include "vtkObjectFactory.h"

class VTKIOEXPORTOPENGL2_EXPORT vtkIOExportOpenGL2ObjectFactory : public vtkObjectFactory
{
public:
  static vtkIOExportOpenGL2ObjectFactory * New();
  vtkTypeMacro(vtkIOExportOpenGL2ObjectFactory, vtkObjectFactory)

  const char * GetDescription() override { return "vtkIOExportOpenGL2 factory overrides."; }

  const char * GetVTKSourceVersion() override;

  void PrintSelf(ostream &os, vtkIndent indent) override;

protected:
  vtkIOExportOpenGL2ObjectFactory();

private:
  vtkIOExportOpenGL2ObjectFactory(const vtkIOExportOpenGL2ObjectFactory&) = delete;
  void operator=(const vtkIOExportOpenGL2ObjectFactory&) = delete;
};

#endif // vtkIOExportOpenGL2ObjectFactory_h
