#-------------------------------------------------
#
# Project created by QtCreator 2021-06-22T10:45:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_ICONS = ./Images/logo.ico
TARGET = ThirdVtk
TEMPLATE = app
CONFIG += C++11
QMAKE_CXXFLAGS += /utf-8
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
    ExampleOrg/cone2.cpp \
        mainwindow.cpp \
    ExampleOrg/ambientspheres.cpp \
    ExampleOrg/marrays.cpp \
    ExampleOrg/cone.cpp \
    ExampleOrg/cone3.cpp \
    ExampleOrg/cone4.cpp \
    ExampleOrg/cone5.cpp \
    ExampleOrg/cone6.cpp \
    ExampleOrg/createtree.cpp \
    ExampleOrg/cube.cpp


HEADERS  += mainwindow.h \
    ExampleOrg/ambientspheres.h \
    ExampleOrg/cone2.h \
    ExampleOrg/marrays.h \
    ExampleOrg/cone.h \
    ExampleOrg/cone3.h \
    ExampleOrg/cone4.h \
    ExampleOrg/cone5.h \
    ExampleOrg/cone6.h \
    ExampleOrg/createtree.h \
    ExampleOrg/cube.h


FORMS    += mainwindow.ui \
    ExampleOrg/ambientspheres.ui \
    ExampleOrg/cone2.ui \
    ExampleOrg/marrays.ui \
    ExampleOrg/cone.ui \
    ExampleOrg/cone3.ui \
    ExampleOrg/cone4.ui \
    ExampleOrg/cone5.ui \
    ExampleOrg/cone6.ui \
    ExampleOrg/createtree.ui \
    ExampleOrg/cube.ui


INCLUDEPATH += ./Vtk/include/vtk-8.2

LIBS += -L./Vtk/lib/ -lvtkChartsCore-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonColor-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonComputationalGeometry-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonCore-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonDataModel-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonExecutionModel-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonMath-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonMisc-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonSystem-8.2
LIBS += -L./Vtk/lib/ -lvtkCommonTransforms-8.2
LIBS += -L./Vtk/lib/ -lvtkDICOMParser-8.2
LIBS += -L./Vtk/lib/ -lvtkDomainsChemistry-8.2
LIBS += -L./Vtk/lib/ -lvtkDomainsChemistryOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtkdoubleconversion-8.2
LIBS += -L./Vtk/lib/ -lvtkexodusII-8.2
LIBS += -L./Vtk/lib/ -lvtkexpat-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersAMR-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersCore-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersExtraction-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersFlowPaths-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersGeneral-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersGeneric-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersGeometry-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersHybrid-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersHyperTree-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersImaging-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersModeling-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersParallel-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersParallelImaging-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersPoints-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersProgrammable-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersSelection-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersSMP-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersSources-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersStatistics-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersTexture-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersTopology-8.2
LIBS += -L./Vtk/lib/ -lvtkFiltersVerdict-8.2
LIBS += -L./Vtk/lib/ -lvtkfreetype-8.2
LIBS += -L./Vtk/lib/ -lvtkGeovisCore-8.2
LIBS += -L./Vtk/lib/ -lvtkgl2ps-8.2
LIBS += -L./Vtk/lib/ -lvtkglew-8.2
LIBS += -L./Vtk/lib/ -lvtkGUISupportQt-8.2
LIBS += -L./Vtk/lib/ -lvtkGUISupportQtSQL-8.2
LIBS += -L./Vtk/lib/ -lvtkhdf5_hl-8.2
LIBS += -L./Vtk/lib/ -lvtkhdf5-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingColor-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingCore-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingFourier-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingGeneral-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingHybrid-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingMath-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingMorphological-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingSources-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingStatistics-8.2
LIBS += -L./Vtk/lib/ -lvtkImagingStencil-8.2
LIBS += -L./Vtk/lib/ -lvtkInfovisCore-8.2
LIBS += -L./Vtk/lib/ -lvtkInfovisLayout-8.2
LIBS += -L./Vtk/lib/ -lvtkInteractionImage-8.2
LIBS += -L./Vtk/lib/ -lvtkInteractionStyle-8.2
LIBS += -L./Vtk/lib/ -lvtkInteractionWidgets-8.2
LIBS += -L./Vtk/lib/ -lvtkIOAMR-8.2
LIBS += -L./Vtk/lib/ -lvtkIOAsynchronous-8.2
LIBS += -L./Vtk/lib/ -lvtkIOCityGML-8.2
LIBS += -L./Vtk/lib/ -lvtkIOCore-8.2
LIBS += -L./Vtk/lib/ -lvtkIOEnSight-8.2
LIBS += -L./Vtk/lib/ -lvtkIOExodus-8.2
LIBS += -L./Vtk/lib/ -lvtkIOExport-8.2
LIBS += -L./Vtk/lib/ -lvtkIOExportOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtkIOExportPDF-8.2
LIBS += -L./Vtk/lib/ -lvtkIOGeometry-8.2
LIBS += -L./Vtk/lib/ -lvtkIOImage-8.2
LIBS += -L./Vtk/lib/ -lvtkIOImport-8.2
LIBS += -L./Vtk/lib/ -lvtkIOInfovis-8.2
LIBS += -L./Vtk/lib/ -lvtkIOLegacy-8.2
LIBS += -L./Vtk/lib/ -lvtkIOLSDyna-8.2
LIBS += -L./Vtk/lib/ -lvtkIOMINC-8.2
LIBS += -L./Vtk/lib/ -lvtkIOMovie-8.2
LIBS += -L./Vtk/lib/ -lvtkIONetCDF-8.2
LIBS += -L./Vtk/lib/ -lvtkIOParallel-8.2
LIBS += -L./Vtk/lib/ -lvtkIOParallelXML-8.2
LIBS += -L./Vtk/lib/ -lvtkIOPLY-8.2
LIBS += -L./Vtk/lib/ -lvtkIOSegY-8.2
LIBS += -L./Vtk/lib/ -lvtkIOSQL-8.2
LIBS += -L./Vtk/lib/ -lvtkIOTecplotTable-8.2
LIBS += -L./Vtk/lib/ -lvtkIOVeraOut-8.2
LIBS += -L./Vtk/lib/ -lvtkIOVideo-8.2
LIBS += -L./Vtk/lib/ -lvtkIOXML-8.2
LIBS += -L./Vtk/lib/ -lvtkIOXMLParser-8.2
LIBS += -L./Vtk/lib/ -lvtkjpeg-8.2
LIBS += -L./Vtk/lib/ -lvtkjsoncpp-8.2
LIBS += -L./Vtk/lib/ -lvtklibharu-8.2
LIBS += -L./Vtk/lib/ -lvtklibxml2-8.2
LIBS += -L./Vtk/lib/ -lvtkLocalExample-8.2
LIBS += -L./Vtk/lib/ -lvtklz4-8.2
LIBS += -L./Vtk/lib/ -lvtklzma-8.2
LIBS += -L./Vtk/lib/ -lvtkmetaio-8.2
LIBS += -L./Vtk/lib/ -lvtkNetCDF-8.2
LIBS += -L./Vtk/lib/ -lvtkogg-8.2
LIBS += -L./Vtk/lib/ -lvtkParallelCore-8.2
LIBS += -L./Vtk/lib/ -lvtkpng-8.2
LIBS += -L./Vtk/lib/ -lvtkproj-8.2
LIBS += -L./Vtk/lib/ -lvtkpugixml-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingAnnotation-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingContext2D-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingContextOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingCore-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingFreeType-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingGL2PSOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingImage-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingLabel-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingLOD-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingQt-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingVolume-8.2
LIBS += -L./Vtk/lib/ -lvtkRenderingVolumeOpenGL2-8.2
LIBS += -L./Vtk/lib/ -lvtksqlite-8.2
LIBS += -L./Vtk/lib/ -lvtksys-8.2
LIBS += -L./Vtk/lib/ -lvtktheora-8.2
LIBS += -L./Vtk/lib/ -lvtktiff-8.2
LIBS += -L./Vtk/lib/ -lvtkverdict-8.2
LIBS += -L./Vtk/lib/ -lvtkViewsContext2D-8.2
LIBS += -L./Vtk/lib/ -lvtkViewsCore-8.2
LIBS += -L./Vtk/lib/ -lvtkViewsInfovis-8.2
LIBS += -L./Vtk/lib/ -lvtkViewsQt-8.2
LIBS += -L./Vtk/lib/ -lvtkzlib-8.2
