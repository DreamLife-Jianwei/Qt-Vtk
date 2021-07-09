#-------------------------------------------------
#
# Project created by QtCreator 2021-06-17T15:55:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstVtk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

INCLUDEPATH += C:\Dev\VTK\Bin\include\vtk-8.2

LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkChartsCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonColor-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonComputationalGeometry-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonDataModel-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonExecutionModel-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonMath-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonMisc-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonSystem-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkCommonTransforms-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkDICOMParser-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkDomainsChemistry-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkDomainsChemistryOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkdoubleconversion-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkexodusII-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkexpat-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersAMR-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersExtraction-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersFlowPaths-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersGeneral-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersGeneric-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersGeometry-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersHybrid-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersHyperTree-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersImaging-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersModeling-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersParallel-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersParallelImaging-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersPoints-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersProgrammable-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersSelection-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersSMP-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersSources-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersStatistics-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersTexture-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersTopology-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkFiltersVerdict-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkfreetype-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkGeovisCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkgl2ps-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkglew-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkGUISupportQt-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkGUISupportQtSQL-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkhdf5_hl-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkhdf5-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingColor-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingFourier-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingGeneral-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingHybrid-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingMath-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingMorphological-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingSources-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingStatistics-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkImagingStencil-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkInfovisCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkInfovisLayout-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkInteractionImage-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkInteractionStyle-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkInteractionWidgets-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOAMR-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOAsynchronous-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOCityGML-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOEnSight-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOExodus-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOExport-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOExportOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOExportPDF-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOGeometry-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOImage-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOImport-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOInfovis-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOLegacy-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOLSDyna-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOMINC-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOMovie-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIONetCDF-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOParallel-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOParallelXML-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOPLY-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOSegY-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOSQL-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOTecplotTable-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOVeraOut-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOVideo-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOXML-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkIOXMLParser-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkjpeg-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkjsoncpp-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtklibharu-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtklibxml2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkLocalExample-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtklz4-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtklzma-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkmetaio-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkNetCDF-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkogg-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkParallelCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkpng-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkproj-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkpugixml-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingAnnotation-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingContext2D-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingContextOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingFreeType-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingGL2PSOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingImage-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingLabel-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingLOD-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingQt-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingVolume-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkRenderingVolumeOpenGL2-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtksqlite-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtksys-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtktheora-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtktiff-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkverdict-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkViewsContext2D-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkViewsCore-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkViewsInfovis-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkViewsQt-8.2
LIBS += -LC:/Dev/VTK/Bin/lib/ -lvtkzlib-8.2
