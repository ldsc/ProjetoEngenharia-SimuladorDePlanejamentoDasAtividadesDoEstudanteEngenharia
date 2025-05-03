/********************************************************************************
** Form generated from reading UI file 'acompanhamentodisciplina.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACOMPANHAMENTODISCIPLINA_H
#define UI_ACOMPANHAMENTODISCIPLINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AcompanhamentoDisciplina
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QPushButton *pushButton_DiscEmAnd;
    QLabel *label_NomeDisc;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AcompanhamentoDisciplina)
    {
        if (AcompanhamentoDisciplina->objectName().isEmpty())
            AcompanhamentoDisciplina->setObjectName("AcompanhamentoDisciplina");
        AcompanhamentoDisciplina->resize(635, 445);
        AcompanhamentoDisciplina->setStyleSheet(QString::fromUtf8("background-color: blue; "));
        centralwidget = new QWidget(AcompanhamentoDisciplina);
        centralwidget->setObjectName("centralwidget");
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(50, -10, 541, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(24);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setStyleSheet(QString::fromUtf8("color: white"));
        pushButton_DiscEmAnd = new QPushButton(centralwidget);
        pushButton_DiscEmAnd->setObjectName("pushButton_DiscEmAnd");
        pushButton_DiscEmAnd->setGeometry(QRect(40, 70, 291, 51));
        pushButton_DiscEmAnd->setStyleSheet(QString::fromUtf8("background-color: #82b4cf;  color: black ; border-radius: 15px; font-weight: bold;"));
        label_NomeDisc = new QLabel(centralwidget);
        label_NomeDisc->setObjectName("label_NomeDisc");
        label_NomeDisc->setGeometry(QRect(60, 90, 251, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setBold(true);
        label_NomeDisc->setFont(font1);
        label_NomeDisc->setStyleSheet(QString::fromUtf8("background: none;  qproperty-alignment: 'AlignHCenter';"));
        AcompanhamentoDisciplina->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AcompanhamentoDisciplina);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 635, 22));
        AcompanhamentoDisciplina->setMenuBar(menubar);
        statusbar = new QStatusBar(AcompanhamentoDisciplina);
        statusbar->setObjectName("statusbar");
        AcompanhamentoDisciplina->setStatusBar(statusbar);

        retranslateUi(AcompanhamentoDisciplina);

        QMetaObject::connectSlotsByName(AcompanhamentoDisciplina);
    } // setupUi

    void retranslateUi(QMainWindow *AcompanhamentoDisciplina)
    {
        AcompanhamentoDisciplina->setWindowTitle(QCoreApplication::translate("AcompanhamentoDisciplina", "MainWindow", nullptr));
        labelTitulo->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Acompanhamento da Disciplina", nullptr));
        pushButton_DiscEmAnd->setText(QString());
        label_NomeDisc->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AcompanhamentoDisciplina: public Ui_AcompanhamentoDisciplina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACOMPANHAMENTODISCIPLINA_H
