/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkIOExportPDFObjectFactory.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef vtkIOExportPDFObjectFactory_h
#define vtkIOExportPDFObjectFactory_h

#include "vtkIOExportPDFModule.h" // For export macro
#include "vtkObjectFactory.h"

class VTKIOEXPORTPDF_EXPORT vtkIOExportPDFObjectFactory : public vtkObjectFactory
{
public:
  static vtkIOExportPDFObjectFactory * New();
  vtkTypeMacro(vtkIOExportPDFObjectFactory, vtkObjectFactory)

  const char * GetDescription() override { return "vtkIOExportPDF factory overrides."; }

  const char * GetVTKSourceVersion() override;

  void PrintSelf(ostream &os, vtkIndent indent) override;

protected:
  vtkIOExportPDFObjectFactory();

private:
  vtkIOExportPDFObjectFactory(const vtkIOExportPDFObjectFactory&) = delete;
  void operator=(const vtkIOExportPDFObjectFactory&) = delete;
};

#endif // vtkIOExportPDFObjectFactory_h
