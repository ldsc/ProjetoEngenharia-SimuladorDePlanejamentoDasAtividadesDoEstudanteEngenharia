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
    QLabel *labelDisciplinasEmCurso;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TelaInicial)
    {
        if (TelaInicial->objectName().isEmpty())
            TelaInicial->setObjectName("TelaInicial");
        TelaInicial->resize(800, 600);
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
        botaoVerGradeCompleta->setGeometry(QRect(20, 220, 301, 111));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(12);
        font1.setBold(true);
        botaoVerGradeCompleta->setFont(font1);
        botaoVerGradeCompleta->setToolTipDuration(-4);
        botaoVerGradeCompleta->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        groupBoxInfoAluno = new QGroupBox(centralwidget);
        groupBoxInfoAluno->setObjectName("groupBoxInfoAluno");
        groupBoxInfoAluno->setGeometry(QRect(20, 40, 671, 141));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Book Antiqua")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        groupBoxInfoAluno->setFont(font2);
        groupBoxInfoAluno->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBoxInfoAluno->setStyleSheet(QString::fromUtf8("background-color: white; color: black; border: none;"));
        labelNome = new QLabel(groupBoxInfoAluno);
        labelNome->setObjectName("labelNome");
        labelNome->setGeometry(QRect(10, 20, 191, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Book Antiqua")});
        font3.setBold(false);
        labelNome->setFont(font3);
        labelNome->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        labelNome->setStyleSheet(QString::fromUtf8(""));
        labelMatricula = new QLabel(groupBoxInfoAluno);
        labelMatricula->setObjectName("labelMatricula");
        labelMatricula->setGeometry(QRect(10, 40, 191, 16));
        labelMatricula->setFont(font3);
        labelCurso = new QLabel(groupBoxInfoAluno);
        labelCurso->setObjectName("labelCurso");
        labelCurso->setGeometry(QRect(10, 60, 191, 16));
        labelCurso->setFont(font3);
        labelPeriodo = new QLabel(groupBoxInfoAluno);
        labelPeriodo->setObjectName("labelPeriodo");
        labelPeriodo->setGeometry(QRect(10, 80, 191, 16));
        labelPeriodo->setFont(font3);
        labelCRA = new QLabel(groupBoxInfoAluno);
        labelCRA->setObjectName("labelCRA");
        labelCRA->setGeometry(QRect(10, 100, 191, 16));
        labelCRA->setFont(font3);
        labelDisciplinasEmCurso = new QLabel(groupBoxInfoAluno);
        labelDisciplinasEmCurso->setObjectName("labelDisciplinasEmCurso");
        labelDisciplinasEmCurso->setGeometry(QRect(10, 120, 661, 16));
        labelDisciplinasEmCurso->setFont(font3);
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
        labelDisciplinasEmCurso->setText(QCoreApplication::translate("TelaInicial", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaInicial: public Ui_TelaInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAINICIAL_H
