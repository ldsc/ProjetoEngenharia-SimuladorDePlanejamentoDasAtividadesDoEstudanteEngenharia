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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuloGradeCompleta
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_grade;
    QPushButton *pushButton_ProgressoGrade;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuGrade_Curricular;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ModuloGradeCompleta)
    {
        if (ModuloGradeCompleta->objectName().isEmpty())
            ModuloGradeCompleta->setObjectName("ModuloGradeCompleta");
        ModuloGradeCompleta->resize(1483, 311);
        ModuloGradeCompleta->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        centralwidget = new QWidget(ModuloGradeCompleta);
        centralwidget->setObjectName("centralwidget");
        pushButton_grade = new QPushButton(centralwidget);
        pushButton_grade->setObjectName("pushButton_grade");
        pushButton_grade->setGeometry(QRect(570, 70, 101, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setBold(true);
        pushButton_grade->setFont(font);
        pushButton_grade->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        pushButton_ProgressoGrade = new QPushButton(centralwidget);
        pushButton_ProgressoGrade->setObjectName("pushButton_ProgressoGrade");
        pushButton_ProgressoGrade->setGeometry(QRect(740, 70, 101, 31));
        pushButton_ProgressoGrade->setFont(font);
        pushButton_ProgressoGrade->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 0, 501, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(40);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: white"));
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

        QMetaObject::connectSlotsByName(ModuloGradeCompleta);
    } // setupUi

    void retranslateUi(QMainWindow *ModuloGradeCompleta)
    {
        ModuloGradeCompleta->setWindowTitle(QCoreApplication::translate("ModuloGradeCompleta", "MainWindow", nullptr));
        pushButton_grade->setText(QCoreApplication::translate("ModuloGradeCompleta", "Ver Grade", nullptr));
        pushButton_ProgressoGrade->setText(QCoreApplication::translate("ModuloGradeCompleta", "Ver Progresso", nullptr));
        label->setText(QCoreApplication::translate("ModuloGradeCompleta", "Grade Curricular", nullptr));
        menuGrade_Curricular->setTitle(QCoreApplication::translate("ModuloGradeCompleta", "Grade Curricular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuloGradeCompleta: public Ui_ModuloGradeCompleta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULOGRADECOMPLETA_H
