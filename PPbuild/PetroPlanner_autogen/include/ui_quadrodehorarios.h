/********************************************************************************
** Form generated from reading UI file 'quadrodehorarios.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUADRODEHORARIOS_H
#define UI_QUADRODEHORARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuadroDeHorarios
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QuadroDeHorarios)
    {
        if (QuadroDeHorarios->objectName().isEmpty())
            QuadroDeHorarios->setObjectName("QuadroDeHorarios");
        QuadroDeHorarios->resize(1529, 797);
        QuadroDeHorarios->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        centralwidget = new QWidget(QuadroDeHorarios);
        centralwidget->setObjectName("centralwidget");
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(350, 0, 551, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(40);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setStyleSheet(QString::fromUtf8("color:white"));
        QuadroDeHorarios->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QuadroDeHorarios);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1529, 22));
        QuadroDeHorarios->setMenuBar(menubar);
        statusbar = new QStatusBar(QuadroDeHorarios);
        statusbar->setObjectName("statusbar");
        QuadroDeHorarios->setStatusBar(statusbar);

        retranslateUi(QuadroDeHorarios);

        QMetaObject::connectSlotsByName(QuadroDeHorarios);
    } // setupUi

    void retranslateUi(QMainWindow *QuadroDeHorarios)
    {
        QuadroDeHorarios->setWindowTitle(QCoreApplication::translate("QuadroDeHorarios", "MainWindow", nullptr));
        labelTitulo->setText(QCoreApplication::translate("QuadroDeHorarios", "Quadro de Hor\303\241rios", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuadroDeHorarios: public Ui_QuadroDeHorarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADRODEHORARIOS_H
