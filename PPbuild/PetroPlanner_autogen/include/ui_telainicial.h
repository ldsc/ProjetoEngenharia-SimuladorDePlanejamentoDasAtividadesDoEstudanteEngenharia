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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
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
    QLabel *labelTitulo;
    QGroupBox *groupBoxDiscAnd;
    QLabel *labelHorasEmCurso;
    QProgressBar *progressBarHoras;
    QLabel *labelHorasEmCurso2;
    QScrollArea *scrollAreaDiscAnd;
    QWidget *wi;
    QPushButton *botaoEditarDisc;
    QLabel *labelDiscAnd;
    QPushButton *botaoSimulacao;
    QPushButton *botaoQuadrodeHorarios;
    QGroupBox *groupBoxFaltas;
    QScrollArea *scrollAreaFaltas;
    QWidget *scrollAreaWidgetContentsFaltas;
    QWidget *widget;
    QLabel *labelDiscAnd_2;
    QPushButton *botaoRefresh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TelaInicial)
    {
        if (TelaInicial->objectName().isEmpty())
            TelaInicial->setObjectName("TelaInicial");
        TelaInicial->resize(1324, 766);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        TelaInicial->setFont(font);
        TelaInicial->setAutoFillBackground(false);
        TelaInicial->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        centralwidget = new QWidget(TelaInicial);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("w"));
        botaoVerGradeCompleta = new QPushButton(centralwidget);
        botaoVerGradeCompleta->setObjectName("botaoVerGradeCompleta");
        botaoVerGradeCompleta->setGeometry(QRect(220, 300, 251, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(12);
        font1.setBold(true);
        botaoVerGradeCompleta->setFont(font1);
        botaoVerGradeCompleta->setToolTipDuration(-4);
        botaoVerGradeCompleta->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        groupBoxInfoAluno = new QGroupBox(centralwidget);
        groupBoxInfoAluno->setObjectName("groupBoxInfoAluno");
        groupBoxInfoAluno->setGeometry(QRect(90, 140, 541, 141));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Book Antiqua")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        groupBoxInfoAluno->setFont(font2);
        groupBoxInfoAluno->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBoxInfoAluno->setStyleSheet(QString::fromUtf8("background-color: none; color: white; border: none;"));
        labelNome = new QLabel(groupBoxInfoAluno);
        labelNome->setObjectName("labelNome");
        labelNome->setGeometry(QRect(10, 20, 421, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Book Antiqua")});
        font3.setBold(false);
        labelNome->setFont(font3);
        labelNome->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        labelNome->setStyleSheet(QString::fromUtf8("color: white"));
        labelMatricula = new QLabel(groupBoxInfoAluno);
        labelMatricula->setObjectName("labelMatricula");
        labelMatricula->setGeometry(QRect(10, 40, 471, 16));
        labelMatricula->setFont(font3);
        labelCurso = new QLabel(groupBoxInfoAluno);
        labelCurso->setObjectName("labelCurso");
        labelCurso->setGeometry(QRect(10, 60, 471, 16));
        labelCurso->setFont(font3);
        labelPeriodo = new QLabel(groupBoxInfoAluno);
        labelPeriodo->setObjectName("labelPeriodo");
        labelPeriodo->setGeometry(QRect(10, 80, 451, 16));
        labelPeriodo->setFont(font3);
        labelCRA = new QLabel(groupBoxInfoAluno);
        labelCRA->setObjectName("labelCRA");
        labelCRA->setGeometry(QRect(10, 100, 571, 16));
        labelCRA->setFont(font3);
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(480, 20, 421, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font4.setPointSize(40);
        font4.setBold(true);
        labelTitulo->setFont(font4);
        labelTitulo->setStyleSheet(QString::fromUtf8("color:white"));
        groupBoxDiscAnd = new QGroupBox(centralwidget);
        groupBoxDiscAnd->setObjectName("groupBoxDiscAnd");
        groupBoxDiscAnd->setGeometry(QRect(690, 110, 601, 261));
        groupBoxDiscAnd->setFont(font2);
        groupBoxDiscAnd->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBoxDiscAnd->setStyleSheet(QString::fromUtf8("background-color: white; color: black; border: none; border-radius: 30px;"));
        labelHorasEmCurso = new QLabel(groupBoxDiscAnd);
        labelHorasEmCurso->setObjectName("labelHorasEmCurso");
        labelHorasEmCurso->setGeometry(QRect(20, 220, 121, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font5.setPointSize(10);
        font5.setBold(false);
        labelHorasEmCurso->setFont(font5);
        labelHorasEmCurso->setStyleSheet(QString::fromUtf8(""));
        progressBarHoras = new QProgressBar(groupBoxDiscAnd);
        progressBarHoras->setObjectName("progressBarHoras");
        progressBarHoras->setGeometry(QRect(150, 220, 118, 23));
        progressBarHoras->setStyleSheet(QString::fromUtf8("QProgressBar {    border: 2px solid blue;    border-radius: 8px;  text-align: center;} QProgressBar::chunk {background-color: #82b4cf; border-radius: 6px;}"));
        progressBarHoras->setMinimum(0);
        progressBarHoras->setValue(0);
        labelHorasEmCurso2 = new QLabel(groupBoxDiscAnd);
        labelHorasEmCurso2->setObjectName("labelHorasEmCurso2");
        labelHorasEmCurso2->setGeometry(QRect(280, 220, 181, 16));
        scrollAreaDiscAnd = new QScrollArea(groupBoxDiscAnd);
        scrollAreaDiscAnd->setObjectName("scrollAreaDiscAnd");
        scrollAreaDiscAnd->setGeometry(QRect(20, 20, 561, 191));
        scrollAreaDiscAnd->setWidgetResizable(true);
        wi = new QWidget();
        wi->setObjectName("wi");
        wi->setGeometry(QRect(0, 0, 561, 191));
        scrollAreaDiscAnd->setWidget(wi);
        botaoEditarDisc = new QPushButton(groupBoxDiscAnd);
        botaoEditarDisc->setObjectName("botaoEditarDisc");
        botaoEditarDisc->setGeometry(QRect(400, 220, 161, 31));
        botaoEditarDisc->setFont(font1);
        botaoEditarDisc->setToolTipDuration(-4);
        botaoEditarDisc->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        labelDiscAnd = new QLabel(centralwidget);
        labelDiscAnd->setObjectName("labelDiscAnd");
        labelDiscAnd->setGeometry(QRect(820, 80, 341, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font6.setPointSize(18);
        font6.setBold(true);
        labelDiscAnd->setFont(font6);
        labelDiscAnd->setStyleSheet(QString::fromUtf8("color: white"));
        botaoSimulacao = new QPushButton(centralwidget);
        botaoSimulacao->setObjectName("botaoSimulacao");
        botaoSimulacao->setGeometry(QRect(190, 560, 331, 81));
        botaoSimulacao->setFont(font1);
        botaoSimulacao->setToolTipDuration(-4);
        botaoSimulacao->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        botaoQuadrodeHorarios = new QPushButton(centralwidget);
        botaoQuadrodeHorarios->setObjectName("botaoQuadrodeHorarios");
        botaoQuadrodeHorarios->setGeometry(QRect(220, 430, 251, 81));
        botaoQuadrodeHorarios->setFont(font1);
        botaoQuadrodeHorarios->setToolTipDuration(-4);
        botaoQuadrodeHorarios->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        groupBoxFaltas = new QGroupBox(centralwidget);
        groupBoxFaltas->setObjectName("groupBoxFaltas");
        groupBoxFaltas->setGeometry(QRect(690, 420, 601, 221));
        groupBoxFaltas->setFont(font2);
        groupBoxFaltas->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBoxFaltas->setStyleSheet(QString::fromUtf8("background-color: white; color: black; border: none; border-radius: 30px;"));
        scrollAreaFaltas = new QScrollArea(groupBoxFaltas);
        scrollAreaFaltas->setObjectName("scrollAreaFaltas");
        scrollAreaFaltas->setGeometry(QRect(20, 19, 551, 181));
        scrollAreaFaltas->setWidgetResizable(true);
        scrollAreaWidgetContentsFaltas = new QWidget();
        scrollAreaWidgetContentsFaltas->setObjectName("scrollAreaWidgetContentsFaltas");
        scrollAreaWidgetContentsFaltas->setGeometry(QRect(0, 0, 551, 181));
        widget = new QWidget(scrollAreaWidgetContentsFaltas);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 551, 181));
        scrollAreaFaltas->setWidget(scrollAreaWidgetContentsFaltas);
        labelDiscAnd_2 = new QLabel(centralwidget);
        labelDiscAnd_2->setObjectName("labelDiscAnd_2");
        labelDiscAnd_2->setGeometry(QRect(810, 390, 351, 21));
        labelDiscAnd_2->setFont(font6);
        labelDiscAnd_2->setStyleSheet(QString::fromUtf8("color: white"));
        botaoRefresh = new QPushButton(centralwidget);
        botaoRefresh->setObjectName("botaoRefresh");
        botaoRefresh->setGeometry(QRect(1120, 650, 161, 31));
        botaoRefresh->setFont(font1);
        botaoRefresh->setToolTipDuration(-4);
        botaoRefresh->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        TelaInicial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TelaInicial);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1324, 22));
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
        labelTitulo->setText(QCoreApplication::translate("TelaInicial", "PetroPlanner", nullptr));
        groupBoxDiscAnd->setTitle(QString());
        labelHorasEmCurso->setText(QCoreApplication::translate("TelaInicial", "Horas em curso:", nullptr));
        labelHorasEmCurso2->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        botaoEditarDisc->setText(QCoreApplication::translate("TelaInicial", "Editar Disciplinas", nullptr));
        labelDiscAnd->setText(QCoreApplication::translate("TelaInicial", "Disciplinas em Andamento", nullptr));
        botaoSimulacao->setText(QCoreApplication::translate("TelaInicial", "Simular Planejamentos Semestrais", nullptr));
        botaoQuadrodeHorarios->setText(QCoreApplication::translate("TelaInicial", "Quadro de Hor\303\241rios", nullptr));
        groupBoxFaltas->setTitle(QString());
        labelDiscAnd_2->setText(QCoreApplication::translate("TelaInicial", "Acompanhamento de Faltas", nullptr));
        botaoRefresh->setText(QCoreApplication::translate("TelaInicial", "Atualizar Faltas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaInicial: public Ui_TelaInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAINICIAL_H
