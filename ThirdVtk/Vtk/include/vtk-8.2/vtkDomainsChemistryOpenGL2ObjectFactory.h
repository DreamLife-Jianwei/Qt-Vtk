/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkDomainsChemistryOpenGL2ObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkDomainsChemistryOpenGL2ObjectFactory_h
#define vtkDomainsChemistryOpenGL2ObjectFactory_h

#include "vtkDomainsChemistryOpenGL2Module.h" // For export macro
#include "vtkObjectFactory.h"

class VTKDOMAINSCHEMISTRYOPENGL2_EXPORT vtkDomainsChemistryOpenGL2ObjectFactory : public vtkObjectFactory
{
public:
  static vtkDomainsChemistryOpenGL2ObjectFactory * New();
  vtkTypeMacro(vtkDomainsChemistryOpenGL2ObjectFactory, vtkObjectFactory)

  const char * GetDescription() override { return "vtkDomainsChemistryOpenGL2 factory overrides."; }

  const char * GetVTKSourceVersion() override;

  void PrintSelf(ostream &os, vtkIndent indent) override;

protected:
  vtkDomainsChemistryOpenGL2ObjectFactory();

private:
  vtkDomainsChemistryOpenGL2ObjectFactory(const vtkDomainsChemistryOpenGL2ObjectFactory&) = delete;
  void operator=(const vtkDomainsChemistryOpenGL2ObjectFactory&) = delete;
};

#endif // vtkDomainsChemistryOpenGL2ObjectFactory_h
