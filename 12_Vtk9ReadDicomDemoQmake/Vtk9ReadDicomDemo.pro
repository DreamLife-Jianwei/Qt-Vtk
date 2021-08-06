QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += ./Vtk9/include/vtk-9.0



LIBS += -L./Vtk9/lib/ -lvtkChartsCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonColor-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonComputationalGeometry-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonDataModel-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonExecutionModel-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonMath-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonMisc-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonSystem-9.0
LIBS += -L./Vtk9/lib/ -lvtkCommonTransforms-9.0
LIBS += -L./Vtk9/lib/ -lvtkDICOM-9.0
LIBS += -L./Vtk9/lib/ -lvtkDICOMParser-9.0
LIBS += -L./Vtk9/lib/ -lvtkDomainsChemistry-9.0
LIBS += -L./Vtk9/lib/ -lvtkDomainsChemistryOpenGL2-9.0
LIBS += -L./Vtk9/lib/ -lvtkdoubleconversion-9.0
LIBS += -L./Vtk9/lib/ -lvtkexodusII-9.0
LIBS += -L./Vtk9/lib/ -lvtkexpat-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersAMR-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersExtraction-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersFlowPaths-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersGeneral-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersGeneric-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersGeometry-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersHybrid-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersHyperTree-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersImaging-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersModeling-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersParallel-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersParallelImaging-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersPoints-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersProgrammable-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersSelection-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersSMP-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersSources-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersStatistics-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersTexture-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersTopology-9.0
LIBS += -L./Vtk9/lib/ -lvtkFiltersVerdict-9.0
LIBS += -L./Vtk9/lib/ -lvtkfreetype-9.0
LIBS += -L./Vtk9/lib/ -lvtkGeovisCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkgl2ps-9.0
LIBS += -L./Vtk9/lib/ -lvtkglew-9.0
LIBS += -L./Vtk9/lib/ -lvtkGUISupportQt-9.0
LIBS += -L./Vtk9/lib/ -lvtkGUISupportQtSQL-9.0
LIBS += -L./Vtk9/lib/ -lvtkhdf5_hl-9.0
LIBS += -L./Vtk9/lib/ -lvtkhdf5-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingColor-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingFourier-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingGeneral-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingHybrid-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingMath-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingMorphological-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingSources-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingStatistics-9.0
LIBS += -L./Vtk9/lib/ -lvtkImagingStencil-9.0
LIBS += -L./Vtk9/lib/ -lvtkInfovisCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkInfovisLayout-9.0
LIBS += -L./Vtk9/lib/ -lvtkInteractionImage-9.0
LIBS += -L./Vtk9/lib/ -lvtkInteractionStyle-9.0
LIBS += -L./Vtk9/lib/ -lvtkInteractionWidgets-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOAMR-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOAsynchronous-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOCityGML-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOEnSight-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOExodus-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOExport-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOExportGL2PS-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOExportPDF-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOGeometry-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOImage-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOImport-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOInfovis-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOLegacy-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOLSDyna-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOMINC-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOMotionFX-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOMovie-9.0
LIBS += -L./Vtk9/lib/ -lvtkIONetCDF-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOOggTheora-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOParallel-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOParallelXML-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOPLY-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOSegY-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOSQL-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOTecplotTable-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOVeraOut-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOVideo-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOXML-9.0
LIBS += -L./Vtk9/lib/ -lvtkIOXMLParser-9.0
LIBS += -L./Vtk9/lib/ -lvtkjpeg-9.0
LIBS += -L./Vtk9/lib/ -lvtkjsoncpp-9.0
LIBS += -L./Vtk9/lib/ -lvtklibharu-9.0
LIBS += -L./Vtk9/lib/ -lvtklibproj-9.0
LIBS += -L./Vtk9/lib/ -lvtklibxml2-9.0
LIBS += -L./Vtk9/lib/ -lvtkloguru-9.0
LIBS += -L./Vtk9/lib/ -lvtklz4-9.0
LIBS += -L./Vtk9/lib/ -lvtklzma-9.0
LIBS += -L./Vtk9/lib/ -lvtkmetaio-9.0
LIBS += -L./Vtk9/lib/ -lvtknetcdf-9.0
LIBS += -L./Vtk9/lib/ -lvtkogg-9.0
LIBS += -L./Vtk9/lib/ -lvtkParallelCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkParallelDIY-9.0
LIBS += -L./Vtk9/lib/ -lvtkpng-9.0
LIBS += -L./Vtk9/lib/ -lvtkpugixml-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingAnnotation-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingContext2D-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingContextOpenGL2-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingFreeType-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingGL2PSOpenGL2-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingImage-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingLabel-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingLOD-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingOpenGL2-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingQt-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingSceneGraph-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingUI-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingVolume-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingVolumeOpenGL2-9.0
LIBS += -L./Vtk9/lib/ -lvtkRenderingVtkJS-9.0
LIBS += -L./Vtk9/lib/ -lvtksqlite-9.0
LIBS += -L./Vtk9/lib/ -lvtksys-9.0
LIBS += -L./Vtk9/lib/ -lvtkTestingRendering-9.0
LIBS += -L./Vtk9/lib/ -lvtktheora-9.0
LIBS += -L./Vtk9/lib/ -lvtktiff-9.0
LIBS += -L./Vtk9/lib/ -lvtkverdict-9.0
LIBS += -L./Vtk9/lib/ -lvtkViewsContext2D-9.0
LIBS += -L./Vtk9/lib/ -lvtkViewsCore-9.0
LIBS += -L./Vtk9/lib/ -lvtkViewsInfovis-9.0
LIBS += -L./Vtk9/lib/ -lvtkViewsQt-9.0
LIBS += -L./Vtk9/lib/ -lvtkWrappingTools-9.0
LIBS += -L./Vtk9/lib/ -lvtkzlib-9.0


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
