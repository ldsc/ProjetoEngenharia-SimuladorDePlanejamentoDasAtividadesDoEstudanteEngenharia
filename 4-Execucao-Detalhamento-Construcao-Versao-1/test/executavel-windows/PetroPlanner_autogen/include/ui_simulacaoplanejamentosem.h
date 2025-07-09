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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulacaoPlanejamentoSEM
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QScrollArea *scrollArea;
    QWidget *scrollAreaSimulacao;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutMain;
    QPushButton *botaoSalvar;
    QPushButton *botaoAvancar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SimulacaoPlanejamentoSEM)
    {
        if (SimulacaoPlanejamentoSEM->objectName().isEmpty())
            SimulacaoPlanejamentoSEM->setObjectName("SimulacaoPlanejamentoSEM");
        SimulacaoPlanejamentoSEM->resize(1172, 1106);
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
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(170, 100, 939, 461));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: white;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaSimulacao = new QWidget();
        scrollAreaSimulacao->setObjectName("scrollAreaSimulacao");
        scrollAreaSimulacao->setGeometry(QRect(0, 0, 937, 459));
        verticalLayoutWidget = new QWidget(scrollAreaSimulacao);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 911, 431));
        verticalLayoutMain = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        verticalLayoutMain->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaSimulacao);
        botaoSalvar = new QPushButton(centralwidget);
        botaoSalvar->setObjectName("botaoSalvar");
        botaoSalvar->setGeometry(QRect(940, 610, 151, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(12);
        font1.setBold(true);
        botaoSalvar->setFont(font1);
        botaoSalvar->setToolTipDuration(-4);
        botaoSalvar->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        botaoAvancar = new QPushButton(centralwidget);
        botaoAvancar->setObjectName("botaoAvancar");
        botaoAvancar->setGeometry(QRect(700, 610, 201, 61));
        botaoAvancar->setFont(font1);
        botaoAvancar->setToolTipDuration(-4);
        botaoAvancar->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
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
        botaoSalvar->setText(QCoreApplication::translate("SimulacaoPlanejamentoSEM", "Salvar PNG", nullptr));
        botaoAvancar->setText(QCoreApplication::translate("SimulacaoPlanejamentoSEM", "Avan\303\247ar Semestre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulacaoPlanejamentoSEM: public Ui_SimulacaoPlanejamentoSEM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULACAOPLANEJAMENTOSEM_H
