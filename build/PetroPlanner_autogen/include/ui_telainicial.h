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
    QPushButton *botaoVerGradeCompleta_2;
    QGroupBox *groupBoxDiscAnd;
    QLabel *labelHorasEmCurso;
    QProgressBar *progressBarCreditos;
    QLabel *labelCreditosEmCurso;
    QScrollArea *scrollAreaDiscAnd;
    QWidget *wi;
    QLabel *labelDiscAnd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TelaInicial)
    {
        if (TelaInicial->objectName().isEmpty())
            TelaInicial->setObjectName("TelaInicial");
        TelaInicial->resize(1308, 728);
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
        botaoVerGradeCompleta->setGeometry(QRect(50, 290, 251, 81));
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
        labelCRA->setGeometry(QRect(10, 100, 481, 16));
        labelCRA->setFont(font3);
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(480, 30, 421, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font4.setPointSize(40);
        font4.setBold(true);
        labelTitulo->setFont(font4);
        labelTitulo->setStyleSheet(QString::fromUtf8("color:white"));
        botaoVerGradeCompleta_2 = new QPushButton(centralwidget);
        botaoVerGradeCompleta_2->setObjectName("botaoVerGradeCompleta_2");
        botaoVerGradeCompleta_2->setGeometry(QRect(330, 290, 251, 81));
        botaoVerGradeCompleta_2->setFont(font1);
        botaoVerGradeCompleta_2->setToolTipDuration(-4);
        botaoVerGradeCompleta_2->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        groupBoxDiscAnd = new QGroupBox(centralwidget);
        groupBoxDiscAnd->setObjectName("groupBoxDiscAnd");
        groupBoxDiscAnd->setGeometry(QRect(690, 120, 601, 261));
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
        progressBarCreditos = new QProgressBar(groupBoxDiscAnd);
        progressBarCreditos->setObjectName("progressBarCreditos");
        progressBarCreditos->setGeometry(QRect(150, 220, 118, 23));
        progressBarCreditos->setStyleSheet(QString::fromUtf8("QProgressBar {    border: 2px solid blue;    border-radius: 8px;  text-align: center;} QProgressBar::chunk {background-color: #82b4cf; border-radius: 6px;}"));
        progressBarCreditos->setMinimum(6);
        progressBarCreditos->setValue(80);
        labelCreditosEmCurso = new QLabel(groupBoxDiscAnd);
        labelCreditosEmCurso->setObjectName("labelCreditosEmCurso");
        labelCreditosEmCurso->setGeometry(QRect(280, 220, 181, 16));
        scrollAreaDiscAnd = new QScrollArea(groupBoxDiscAnd);
        scrollAreaDiscAnd->setObjectName("scrollAreaDiscAnd");
        scrollAreaDiscAnd->setGeometry(QRect(20, 20, 561, 191));
        scrollAreaDiscAnd->setWidgetResizable(true);
        wi = new QWidget();
        wi->setObjectName("wi");
        wi->setGeometry(QRect(0, 0, 561, 191));
        scrollAreaDiscAnd->setWidget(wi);
        labelDiscAnd = new QLabel(centralwidget);
        labelDiscAnd->setObjectName("labelDiscAnd");
        labelDiscAnd->setGeometry(QRect(780, 90, 341, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font6.setPointSize(18);
        font6.setBold(true);
        labelDiscAnd->setFont(font6);
        labelDiscAnd->setStyleSheet(QString::fromUtf8("color: white"));
        TelaInicial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TelaInicial);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1308, 22));
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
        botaoVerGradeCompleta->setText(QCoreApplication::translate("TelaInicial", "Ver Grade Completa antigo", nullptr));
        groupBoxInfoAluno->setTitle(QCoreApplication::translate("TelaInicial", "Dados Gerais", nullptr));
        labelNome->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelMatricula->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelCurso->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelPeriodo->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelCRA->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelTitulo->setText(QCoreApplication::translate("TelaInicial", "PetroPlanner", nullptr));
        botaoVerGradeCompleta_2->setText(QCoreApplication::translate("TelaInicial", "Ver Grade Completa", nullptr));
        groupBoxDiscAnd->setTitle(QString());
        labelHorasEmCurso->setText(QCoreApplication::translate("TelaInicial", "Cr\303\251ditos em curso:", nullptr));
        labelCreditosEmCurso->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
        labelDiscAnd->setText(QCoreApplication::translate("TelaInicial", "Disciplinas em Andamento", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaInicial: public Ui_TelaInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAINICIAL_H
