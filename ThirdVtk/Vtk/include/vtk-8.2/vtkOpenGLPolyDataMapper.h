/*=========================================================================

  Program:   Visualization Toolkit

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkOpenGLPolyDataMapper
 * @brief   PolyDataMapper using OpenGL to render.
 *
 * PolyDataMapper that uses a OpenGL to do the actual rendering.
*/

#ifndef vtkOpenGLPolyDataMapper_h
#define vtkOpenGLPolyDataMapper_h

#include "vtkNew.h" // For vtkNew
#include "vtkRenderingOpenGL2Module.h" // For export macro
#include "vtkNew.h" // for ivars
#include "vtkPolyDataMapper.h"
#include "vtkShader.h" // for methods
#include "vtkOpenGLHelper.h" // used for ivars
#include "vtkStateStorage.h" // used for ivars

#include <vector> //for ivars
#include <map> //for methods

class vtkCellArray;
class vtkGenericOpenGLResourceFreeCallback;
class vtkMatrix4x4;
class vtkMatrix3x3;
class vtkOpenGLRenderTimer;
class vtkOpenGLTexture;
class vtkOpenGLBufferObject;
class vtkOpenGLVertexBufferObject;
class vtkOpenGLVertexBufferObjectGroup;
class vtkPoints;
class vtkTexture;
class vtkTextureObject;
class vtkTransform;


class VTKRENDERINGOPENGL2_EXPORT vtkOpenGLPolyDataMapper : public vtkPolyDataMapper
{
public:
  static vtkOpenGLPolyDataMapper* New();
  vtkTypeMacro(vtkOpenGLPolyDataMapper, vtkPolyDataMapper)
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Implemented by sub classes. Actual rendering is done here.
   */
  void RenderPiece(vtkRenderer *ren, vtkActor *act) override;

  //@{
  /**
   * Implemented by sub classes. Actual rendering is done here.
   */
  virtual void RenderPieceStart(vtkRenderer *ren, vtkActor *act);
  virtual void RenderPieceDraw(vtkRenderer *ren, vtkActor *act);
  virtual void RenderPieceFinish(vtkRenderer *ren, vtkActor *act);
  //@}

  /**
   * Release any graphics resources that are being consumed by this mapper.
   * The parameter window could be used to determine which graphic
   * resources to release.
   */
  void ReleaseGraphicsResources(vtkWindow *) override;

  vtkGetMacro(PopulateSelectionSettings,int);
  void SetPopulateSelectionSettings(int v) { this->PopulateSelectionSettings = v; };

  /**
   * WARNING: INTERNAL METHOD - NOT INTENDED FOR GENERAL USE
   * DO NOT USE THIS METHOD OUTSIDE OF THE RENDERING PROCESS
   * Used by vtkHardwareSelector to determine if the prop supports hardware
   * selection.
   */
  bool GetSupportsSelection() override { return true; }

  /**
   * Returns if the mapper does not expect to have translucent geometry. This
   * may happen when using ScalarMode is set to not map scalars i.e. render the
   * scalar array directly as colors and the scalar array has opacity i.e. alpha
   * component. Note that even if this method returns true, an actor may treat
   * the geometry as translucent since a constant translucency is set on the
   * property, for example.
   * Overridden to use the actual data and ScalarMode to determine if we have
   * opaque geometry.
   */
  bool GetIsOpaque() override;

  // used by RenderPiece and functions it calls to reduce
  // calls to get the input and allow for rendering of
  // other polydata (not the input)
  vtkPolyData *CurrentInput;

  //@{
  /**
   * By default, this class uses the dataset's point and cell ids during
   * rendering. However, one can override those by specifying cell and point
   * data arrays to use instead. Currently, only vtkIdType array is supported.
   * Set to NULL string (default) to use the point ids instead.
   */
  vtkSetStringMacro(PointIdArrayName);
  vtkGetStringMacro(PointIdArrayName);
  vtkSetStringMacro(CellIdArrayName);
  vtkGetStringMacro(CellIdArrayName);
  //@}

  //@{
  /**
   * If this class should override the process id using a data-array,
   * set this variable to the name of the array to use. It must be a
   * point-array.
   */
  vtkSetStringMacro(ProcessIdArrayName);
  vtkGetStringMacro(ProcessIdArrayName);
  //@}

  //@{
  /**
   * Generally, this class can render the composite id when iterating
   * over composite datasets. However in some cases (as in AMR), the rendered
   * structure may not correspond to the input data, in which case we need
   * to provide a cell array that can be used to render in the composite id in
   * selection passes. Set to NULL (default) to not override the composite id
   * color set by vtkCompositePainter if any.
   * The array *MUST* be a cell array and of type vtkUnsignedIntArray.
   */
  vtkSetStringMacro(CompositeIdArrayName);
  vtkGetStringMacro(CompositeIdArrayName);
  //@}


  //@{
  /**
   * This function enables you to apply your own substitutions
   * to the shader creation process. The shader code in this class
   * is created by applying a bunch of string replacements to a
   * shader template. Using this function you can apply your
   * own string replacements to add features you desire.
   */
  void AddShaderReplacement(
    vtkShader::Type shaderType, // vertex, fragment, etc
    const std::string& originalValue,
    bool replaceFirst,  // do this replacement before the default
    const std::string& replacementValue,
    bool replaceAll);
  void ClearShaderReplacement(
    vtkShader::Type shaderType, // vertex, fragment, etc
    const std::string& originalValue,
    bool replaceFirst);
  void ClearAllShaderReplacements(vtkShader::Type shaderType);
  void ClearAllShaderReplacements();
  //@}

  //@{
  /**
   * Allow the program to set the shader codes used directly
   * instead of using the built in templates. Be aware, if
   * set, this template will be used for all cases,
   * primitive types, picking etc.
   */
  vtkSetStringMacro(VertexShaderCode);
  vtkGetStringMacro(VertexShaderCode);
  vtkSetStringMacro(FragmentShaderCode);
  vtkGetStringMacro(FragmentShaderCode);
  vtkSetStringMacro(GeometryShaderCode);
  vtkGetStringMacro(GeometryShaderCode);
  //@}

  // the following is all extra stuff to work around the
  // fact that gl_PrimitiveID does not work correctly on
  // Apple Macs with AMD graphics hardware (before macOS 10.11).
  // See <rdar://20747550>.
  static vtkPolyData *HandleAppleBug(
    vtkPolyData *poly,
    std::vector<float> &buffData);

  /**
   * Make a shallow copy of this mapper.
   */
  void ShallowCopy(vtkAbstractMapper *m) override;

  //@{
  /**
   * Override the normal test for the apple bug
   */
  void ForceHaveAppleBugOff()
  {
    this->HaveAppleBugForce = 1;
    this->Modified();
  }
  void ForceHaveAppleBugOn()
  {
    this->HaveAppleBugForce = 2;
    this->Modified();
  }
  //@}

  /**
   * Get the value of HaveAppleBug
   */
  bool GetHaveAppleBug() { return this->HaveAppleBug; }

  /// Return the mapper's vertex buffer objects.
  vtkGetObjectMacro(VBOs, vtkOpenGLVertexBufferObjectGroup);

  /**\brief A convenience method for enabling/disabling
    *   the VBO's shift+scale transform.
    */
  void SetVBOShiftScaleMethod(int m);

  enum PrimitiveTypes {
    PrimitiveStart = 0,
    PrimitivePoints = 0,
    PrimitiveLines,
    PrimitiveTris,
    PrimitiveTriStrips,
    PrimitiveTrisEdges,
    PrimitiveTriStripsEdges,
    PrimitiveVertices,
    PrimitiveEnd
  };

  void UpdateCellMaps(
    bool HaveAppleBug,
    vtkPolyData *poly,
    vtkCellArray **prims, int representation,
    vtkPoints *points);

  /**
   * Get access to the map of glprim to vtkcell ids
   */
  static void MakeCellCellMap(
    std::vector<vtkIdType> &cellCellMap,
    bool HaveAppleBug,
    vtkPolyData *poly,
    vtkCellArray **prims, int representation,
    vtkPoints *points);

  /**
   * Select a data array from the point/cell data
   * and map it to a generic vertex attribute.
   * vertexAttributeName is the name of the vertex attribute.
   * dataArrayName is the name of the data array.
   * fieldAssociation indicates when the data array is a point data array or
   * cell data array (vtkDataObject::FIELD_ASSOCIATION_POINTS or
   * (vtkDataObject::FIELD_ASSOCIATION_CELLS).
   * componentno indicates which component from the data array must be passed as
   * the attribute. If -1, then all components are passed.
   */
  void MapDataArrayToVertexAttribute(
    const char* vertexAttributeName,
    const char* dataArrayName,
    int fieldAssociation,
    int componentno = -1) override;

  // This method will Map the specified data array for use as
  // a texture coordinate for texture tname. The actual
  // attribute will be named tname_coord so as to not
  // conflict with the texture sampler definition which will
  // be tname.
  void MapDataArrayToMultiTextureAttribute(
    const char *tname,
    const char* dataArrayName, int fieldAssociation, int componentno = -1) override;

  /**
   * Remove a vertex attribute mapping.
   */
  void RemoveVertexAttributeMapping(const char* vertexAttributeName) override;

  /**
   * Remove all vertex attributes.
   */
  void RemoveAllVertexAttributeMappings() override;

  /**
   * allows a mapper to update a selections color buffers
   * Called from a prop which in turn is called from the selector
   */
  void ProcessSelectorPixelBuffers(vtkHardwareSelector *sel,
    std::vector<unsigned int> &pixeloffsets,
    vtkProp *prop) override;

protected:
  vtkOpenGLPolyDataMapper();
  ~vtkOpenGLPolyDataMapper() override;

  vtkGenericOpenGLResourceFreeCallback *ResourceCallback;

  void MapDataArray(
    const char* vertexAttributeName,
    const char* dataArrayName,
    const char *texturename,
    int fieldAssociation,
    int componentno);

  // what coordinate should be used for this texture
  std::string GetTextureCoordinateName(const char *tname);

  // the following is all extra stuff to work around the
  // fact that gl_PrimitiveID does not work correctly on
  // Apple Macs with AMD graphics hardware (before macOS 10.11).
  // See <rdar://20747550>.
  bool HaveAppleBug;
  int HaveAppleBugForce; // 0 = default 1 = 0ff 2 = on
  std::vector<float> AppleBugPrimIDs;
  vtkOpenGLBufferObject *AppleBugPrimIDBuffer;

  /**
   * helper function to get the appropriate coincident params
   */
  void GetCoincidentParameters(
    vtkRenderer *ren, vtkActor *actor, float &factor, float &offset);

  /**
   * Called in GetBounds(). When this method is called, the consider the input
   * to be updated depending on whether this->Static is set or not. This method
   * simply obtains the bounds from the data-object and returns it.
   */
  void ComputeBounds() override;

  /**
   * Make sure appropriate shaders are defined, compiled and bound.  This method
   * orchistrates the process, much of the work is done in other methods
   */
  virtual void UpdateShaders(
    vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Does the shader source need to be recomputed
   */
  virtual bool GetNeedToRebuildShaders(
    vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Build the shader source code, called by UpdateShader
   */
  virtual void BuildShaders(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);

  /**
   * Create the basic shaders before replacement
   */
  virtual void GetShaderTemplate(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);

  /**
   * Perform string replacements on the shader templates
   */
  virtual void ReplaceShaderValues(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);

  //@{
  /**
   * Perform string replacements on the shader templates, called from
   * ReplaceShaderValues
   */
  virtual void ReplaceShaderRenderPass(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act, bool prePass);
  virtual void ReplaceShaderColor(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderLight(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderTCoord(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderPicking(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderPrimID(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderNormal(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderClip(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderPositionVC(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderCoincidentOffset(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  virtual void ReplaceShaderDepth(
    std::map<vtkShader::Type, vtkShader *> shaders,
    vtkRenderer *ren, vtkActor *act);
  //@}

  /**
   * Set the shader parameters related to the mapper/input data, called by UpdateShader
   */
  virtual void SetMapperShaderParameters(vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Set the shader parameteres related to lighting, called by UpdateShader
   */
  virtual void SetLightingShaderParameters(vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Set the shader parameteres related to the Camera, called by UpdateShader
   */
  virtual void SetCameraShaderParameters(vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Set the shader parameteres related to the property, called by UpdateShader
   */
  virtual void SetPropertyShaderParameters(vtkOpenGLHelper &cellBO, vtkRenderer *ren, vtkActor *act);

  /**
   * Update the VBO/IBO to be current
   */
  virtual void UpdateBufferObjects(vtkRenderer *ren, vtkActor *act);

  /**
   * Does the VBO/IBO need to be rebuilt
   */
  virtual bool GetNeedToRebuildBufferObjects(vtkRenderer *ren, vtkActor *act);

  /**
   * Build the VBO/IBO, called by UpdateBufferObjects
   */
  virtual void BuildBufferObjects(vtkRenderer *ren, vtkActor *act);

  /**
   * Build the IBO, called by BuildBufferObjects
   */
  virtual void BuildIBO(vtkRenderer *ren, vtkActor *act, vtkPolyData *poly);

  // The VBO and its layout.
  vtkOpenGLVertexBufferObjectGroup *VBOs;

  // Structures for the various cell types we render.
  vtkOpenGLHelper Primitives[PrimitiveEnd];
  vtkOpenGLHelper *LastBoundBO;
  bool DrawingEdgesOrVertices;

  // do we have wide lines that require special handling
  virtual bool HaveWideLines(vtkRenderer *, vtkActor *);

  // do we have textures that require special handling
  virtual bool HaveTextures(vtkActor *actor);

  // how many textures do we have
  virtual unsigned int GetNumberOfTextures(vtkActor *actor);

  // populate a vector with the textures we have
  // the order is always
  //  ColorInternalTexture
  //  Actors texture
  //  Properties textures
  virtual std::vector<std::pair<vtkTexture *, std::string> > GetTextures(vtkActor *actor);

  // do we have textures coordinates that require special handling
  virtual bool HaveTCoords(vtkPolyData *poly);

  // values we use to determine if we need to rebuild shaders
  std::map<const vtkOpenGLHelper *, int> LastLightComplexity;
  std::map<const vtkOpenGLHelper *, int> LastLightCount;
  std::map<const vtkOpenGLHelper *, vtkTimeStamp> LightComplexityChanged;

  int LastSelectionState;
  vtkTimeStamp SelectionStateChanged;

  // Caches the vtkOpenGLRenderPass::RenderPasses() information.
  // Note: Do not dereference the pointers held by this object. There is no
  // guarantee that they are still valid!
  vtkNew<vtkInformation> LastRenderPassInfo;

  // Check the renderpasses in actor's property keys to see if they've changed
  // render stages:
  vtkMTimeType GetRenderPassStageMTime(vtkActor *actor);

  bool UsingScalarColoring;
  vtkTimeStamp VBOBuildTime; // When was the OpenGL VBO updated?
  vtkStateStorage VBOBuildState; // used for determining when to rebuild the VBO
  vtkStateStorage IBOBuildState; // used for determining whento rebuild the IBOs
  vtkStateStorage CellTextureBuildState;
  vtkStateStorage TempState; // can be used to avoid constant allocs/deallocs
  vtkOpenGLTexture* InternalColorTexture;

  int PopulateSelectionSettings;
  int PrimitiveIDOffset;

  vtkMatrix4x4* TempMatrix4;
  vtkMatrix3x3* TempMatrix3;
  vtkNew<vtkTransform> VBOInverseTransform;
  vtkNew<vtkMatrix4x4> VBOShiftScale;
  int ShiftScaleMethod; // for points

  // if set to true, tcoords will be passed to the
  // VBO even if the mapper knows of no texture maps
  // normally tcoords are only added to the VBO if the
  // mapper has identified a texture map as well.
  bool ForceTextureCoordinates;

  virtual void BuildCellTextures(
    vtkRenderer *ren,
    vtkActor *,
    vtkCellArray *prims[4],
    int representation);

  void AppendCellTextures(
    vtkRenderer *ren,
    vtkActor *,
    vtkCellArray *prims[4],
    int representation,
    std::vector<unsigned char> &colors,
    std::vector<float> &normals,
    vtkPolyData *pd);

  vtkTextureObject *CellScalarTexture;
  vtkOpenGLBufferObject *CellScalarBuffer;
  bool HaveCellScalars;
  vtkTextureObject *CellNormalTexture;
  vtkOpenGLBufferObject *CellNormalBuffer;
  bool HaveCellNormals;

  // additional picking indirection
  char* PointIdArrayName;
  char* CellIdArrayName;
  char* ProcessIdArrayName;
  char* CompositeIdArrayName;

  std::map<const vtkShader::ReplacementSpec, vtkShader::ReplacementValue>
    UserShaderReplacements;

  class ExtraAttributeValue
  {
    public:
      std::string DataArrayName;
      int FieldAssociation;
      int ComponentNumber;
      std::string TextureName;
  };
  std::map<std::string,ExtraAttributeValue> ExtraAttributes;

  char *VertexShaderCode;
  char *FragmentShaderCode;
  char *GeometryShaderCode;
  vtkOpenGLRenderTimer *TimerQuery;

  // are we currently drawing spheres/tubes
  bool DrawingSpheres(vtkOpenGLHelper &cellBO, vtkActor *actor);
  bool DrawingTubes(vtkOpenGLHelper &cellBO, vtkActor *actor);
  bool DrawingTubesOrSpheres(vtkOpenGLHelper &cellBO, vtkActor *actor);

  // get which opengl mode to use to draw the primitive
  int GetOpenGLMode(int representation, int primType);

  // get how big to make the points when doing point picking
  // typically 2 for points, 4 for lines, 6 for surface
  int GetPointPickingPrimitiveSize(int primType);

  // used to occasionally invoke timers
  unsigned int TimerQueryCounter;

  // stores the mapping from vtk cells to gl_PrimitiveId
  std::vector<vtkIdType> CellCellMap;
  std::vector<vtkIdType> PointCellMap;
  std::string CellMapsBuildString;

  // compute and set the maximum point and cell ID used in selection
  virtual void UpdateMaximumPointCellIds(vtkRenderer* ren, vtkActor *actor);

private:
  vtkOpenGLPolyDataMapper(const vtkOpenGLPolyDataMapper&) = delete;
  void operator=(const vtkOpenGLPolyDataMapper&) = delete;
};

#endif
