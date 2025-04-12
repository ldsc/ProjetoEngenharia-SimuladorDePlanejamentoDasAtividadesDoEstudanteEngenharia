/********************************************************************************
** Form generated from reading UI file 'telainicial.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAINICIAL_H
#define UI_TELAINICIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaInicial
{
public:
    QWidget *centralwidget;
    QPushButton *botaoVerGradeCompleta;
    QGroupBox *groupBoxInfoAluno;
    QLabel *labelNome;
    QLabel *labelMatricula;
    QLabel *labelCurso;
    QLabel *labelPeriodo;
    QLabel *labelCRA;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TelaInicial)
    {
        if (TelaInicial->objectName().isEmpty())
            TelaInicial->setObjectName("TelaInicial");
        TelaInicial->resize(800, 600);
        centralwidget = new QWidget(TelaInicial);
        centralwidget->setObjectName("centralwidget");
        botaoVerGradeCompleta = new QPushButton(centralwidget);
        botaoVerGradeCompleta->setObjectName("botaoVerGradeCompleta");
        botaoVerGradeCompleta->setGeometry(QRect(30, 190, 121, 31));
        groupBoxInfoAluno = new QGroupBox(centralwidget);
        groupBoxInfoAluno->setObjectName("groupBoxInfoAluno");
        groupBoxInfoAluno->setGeometry(QRect(20, 40, 211, 121));
        labelNome = new QLabel(groupBoxInfoAluno);
        labelNome->setObjectName("labelNome");
        labelNome->setGeometry(QRect(10, 20, 191, 16));
        labelMatricula = new QLabel(groupBoxInfoAluno);
        labelMatricula->setObjectName("labelMatricula");
        labelMatricula->setGeometry(QRect(10, 40, 191, 16));
        labelCurso = new QLabel(groupBoxInfoAluno);
        labelCurso->setObjectName("labelCurso");
        labelCurso->setGeometry(QRect(10, 60, 191, 16));
        labelPeriodo = new QLabel(groupBoxInfoAluno);
        labelPeriodo->setObjectName("labelPeriodo");
        labelPeriodo->setGeometry(QRect(10, 80, 191, 16));
        labelCRA = new QLabel(groupBoxInfoAluno);
        labelCRA->setObjectName("labelCRA");
        labelCRA->setGeometry(QRect(10, 100, 191, 16));
        TelaInicial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TelaInicial);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        TelaInicial->setMenuBar(menubar);
        statusbar = new QStatusBar(TelaInicial);
        statusbar->setObjectName("statusbar");
        TelaInicial->setStatusBar(statusbar);

        retranslateUi(TelaInicial);

        QMetaObject::connectSlotsByName(TelaInicial);
    } // setupUi

    void retranslateUi(QMainWindow *TelaInicial)
    {
        TelaInicial->setWindowTitle(QCoreApplication::translate("TelaInicial", "TelaInicial", nullptr));
        botaoVerGradeCompleta->setText(QCoreApplication::translate("TelaInicial", "Ver Grade Completa", nullptr));
        groupBoxInfoAluno->setTitle(QCoreApplication::translate("TelaInicial", "Dados Gerais", nullptr));
        labelNome->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelMatricula->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelCurso->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelPeriodo->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelCRA->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaInicial: public Ui_TelaInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAINICIAL_H
