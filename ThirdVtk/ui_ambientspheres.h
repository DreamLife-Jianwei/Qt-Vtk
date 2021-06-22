/********************************************************************************
** Form generated from reading UI file 'ambientspheres.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMBIENTSPHERES_H
#define UI_AMBIENTSPHERES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qvtkopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_AmbientSpheres
{
public:
    QGridLayout *gridLayout;
    QVTKOpenGLWidget *widget;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *AmbientSpheres)
    {
        if (AmbientSpheres->objectName().isEmpty())
            AmbientSpheres->setObjectName(QStringLiteral("AmbientSpheres"));
        AmbientSpheres->resize(1366, 768);
        gridLayout = new QGridLayout(AmbientSpheres);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QVTKOpenGLWidget(AmbientSpheres);
        widget->setObjectName(QStringLiteral("widget"));
        calendarWidget = new QCalendarWidget(widget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(520, 310, 248, 197));

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(AmbientSpheres);

        QMetaObject::connectSlotsByName(AmbientSpheres);
    } // setupUi

    void retranslateUi(QWidget *AmbientSpheres)
    {
        AmbientSpheres->setWindowTitle(QApplication::translate("AmbientSpheres", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AmbientSpheres: public Ui_AmbientSpheres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMBIENTSPHERES_H
