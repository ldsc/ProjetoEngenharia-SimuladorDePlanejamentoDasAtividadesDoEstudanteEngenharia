/********************************************************************************
** Form generated from reading UI file 'simulacaoplanejamentosem.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULACAOPLANEJAMENTOSEM_H
#define UI_SIMULACAOPLANEJAMENTOSEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulacaoPlanejamentoSEM
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimulacaoPlanejamentoSEM)
    {
        if (SimulacaoPlanejamentoSEM->objectName().isEmpty())
            SimulacaoPlanejamentoSEM->setObjectName("SimulacaoPlanejamentoSEM");
        SimulacaoPlanejamentoSEM->resize(1172, 600);
        SimulacaoPlanejamentoSEM->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        centralwidget = new QWidget(SimulacaoPlanejamentoSEM);
        centralwidget->setObjectName("centralwidget");
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(300, 20, 791, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(40);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setStyleSheet(QString::fromUtf8("color:white"));
        SimulacaoPlanejamentoSEM->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimulacaoPlanejamentoSEM);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1172, 22));
        SimulacaoPlanejamentoSEM->setMenuBar(menubar);
        statusbar = new QStatusBar(SimulacaoPlanejamentoSEM);
        statusbar->setObjectName("statusbar");
        SimulacaoPlanejamentoSEM->setStatusBar(statusbar);

        retranslateUi(SimulacaoPlanejamentoSEM);

        QMetaObject::connectSlotsByName(SimulacaoPlanejamentoSEM);
    } // setupUi

    void retranslateUi(QMainWindow *SimulacaoPlanejamentoSEM)
    {
        SimulacaoPlanejamentoSEM->setWindowTitle(QCoreApplication::translate("SimulacaoPlanejamentoSEM", "MainWindow", nullptr));
        labelTitulo->setText(QCoreApplication::translate("SimulacaoPlanejamentoSEM", "Planejamentos Semestrais", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulacaoPlanejamentoSEM: public Ui_SimulacaoPlanejamentoSEM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULACAOPLANEJAMENTOSEM_H
