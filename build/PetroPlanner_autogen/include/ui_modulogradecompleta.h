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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuloGradeCompleta
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTabWidget *tabsGrade;
    QWidget *tab_gradeGeral;
    QWidget *widget_gradeGeral;
    QWidget *tab_GradeProgresso;
    QWidget *widget_gradeProgresso;
    QMenuBar *menubar;
    QMenu *menuGrade_Curricular;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ModuloGradeCompleta)
    {
        if (ModuloGradeCompleta->objectName().isEmpty())
            ModuloGradeCompleta->setObjectName("ModuloGradeCompleta");
        ModuloGradeCompleta->resize(1483, 811);
        ModuloGradeCompleta->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        centralwidget = new QWidget(ModuloGradeCompleta);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 0, 501, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(40);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white"));
        tabsGrade = new QTabWidget(centralwidget);
        tabsGrade->setObjectName("tabsGrade");
        tabsGrade->setGeometry(QRect(60, 60, 1281, 561));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setBold(true);
        tabsGrade->setFont(font1);
        tabsGrade->setStyleSheet(QString::fromUtf8("background: white; color: black"));
        tab_gradeGeral = new QWidget();
        tab_gradeGeral->setObjectName("tab_gradeGeral");
        widget_gradeGeral = new QWidget(tab_gradeGeral);
        widget_gradeGeral->setObjectName("widget_gradeGeral");
        widget_gradeGeral->setGeometry(QRect(19, 30, 1231, 501));
        tabsGrade->addTab(tab_gradeGeral, QString());
        tab_GradeProgresso = new QWidget();
        tab_GradeProgresso->setObjectName("tab_GradeProgresso");
        tab_GradeProgresso->setFont(font1);
        widget_gradeProgresso = new QWidget(tab_GradeProgresso);
        widget_gradeProgresso->setObjectName("widget_gradeProgresso");
        widget_gradeProgresso->setGeometry(QRect(20, 20, 1241, 501));
        tabsGrade->addTab(tab_GradeProgresso, QString());
        ModuloGradeCompleta->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ModuloGradeCompleta);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1483, 22));
        menuGrade_Curricular = new QMenu(menubar);
        menuGrade_Curricular->setObjectName("menuGrade_Curricular");
        ModuloGradeCompleta->setMenuBar(menubar);
        statusbar = new QStatusBar(ModuloGradeCompleta);
        statusbar->setObjectName("statusbar");
        ModuloGradeCompleta->setStatusBar(statusbar);

        menubar->addAction(menuGrade_Curricular->menuAction());

        retranslateUi(ModuloGradeCompleta);

        tabsGrade->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ModuloGradeCompleta);
    } // setupUi

    void retranslateUi(QMainWindow *ModuloGradeCompleta)
    {
        ModuloGradeCompleta->setWindowTitle(QCoreApplication::translate("ModuloGradeCompleta", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ModuloGradeCompleta", "Grade Curricular", nullptr));
        tabsGrade->setTabText(tabsGrade->indexOf(tab_gradeGeral), QCoreApplication::translate("ModuloGradeCompleta", "Ver Grade", nullptr));
        tabsGrade->setTabText(tabsGrade->indexOf(tab_GradeProgresso), QCoreApplication::translate("ModuloGradeCompleta", "Ver Progresso", nullptr));
        menuGrade_Curricular->setTitle(QCoreApplication::translate("ModuloGradeCompleta", "Grade Curricular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuloGradeCompleta: public Ui_ModuloGradeCompleta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULOGRADECOMPLETA_H
