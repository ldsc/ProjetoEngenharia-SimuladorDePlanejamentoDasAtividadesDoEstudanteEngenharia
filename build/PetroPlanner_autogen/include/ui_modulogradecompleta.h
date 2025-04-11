/********************************************************************************
** Form generated from reading UI file 'modulogradecompleta.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULOGRADECOMPLETA_H
#define UI_MODULOGRADECOMPLETA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuloGradeCompleta
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ModuloGradeCompleta)
    {
        if (ModuloGradeCompleta->objectName().isEmpty())
            ModuloGradeCompleta->setObjectName("ModuloGradeCompleta");
        ModuloGradeCompleta->resize(800, 600);
        centralwidget = new QWidget(ModuloGradeCompleta);
        centralwidget->setObjectName("centralwidget");
        ModuloGradeCompleta->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ModuloGradeCompleta);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ModuloGradeCompleta->setMenuBar(menubar);
        statusbar = new QStatusBar(ModuloGradeCompleta);
        statusbar->setObjectName("statusbar");
        ModuloGradeCompleta->setStatusBar(statusbar);

        retranslateUi(ModuloGradeCompleta);

        QMetaObject::connectSlotsByName(ModuloGradeCompleta);
    } // setupUi

    void retranslateUi(QMainWindow *ModuloGradeCompleta)
    {
        ModuloGradeCompleta->setWindowTitle(QCoreApplication::translate("ModuloGradeCompleta", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuloGradeCompleta: public Ui_ModuloGradeCompleta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULOGRADECOMPLETA_H
