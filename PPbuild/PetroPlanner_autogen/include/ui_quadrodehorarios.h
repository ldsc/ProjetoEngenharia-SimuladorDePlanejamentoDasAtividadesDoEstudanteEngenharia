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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuadroDeHorarios
{
public:
    QWidget *centralwidget;
    QLabel *labelTitulo;
    QTableWidget *tableWidgetQuadroHor;
    QPushButton *botaoEditar;
    QPushButton *botaoSalvar;
    QPushButton *botaoExcluir;
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
        labelTitulo->setGeometry(QRect(350, -10, 551, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(40);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setStyleSheet(QString::fromUtf8("color:white"));
        tableWidgetQuadroHor = new QTableWidget(centralwidget);
        if (tableWidgetQuadroHor->columnCount() < 7)
            tableWidgetQuadroHor->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetQuadroHor->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidgetQuadroHor->rowCount() < 19)
            tableWidgetQuadroHor->setRowCount(19);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(15, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(16, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(17, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidgetQuadroHor->setVerticalHeaderItem(18, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidgetQuadroHor->setItem(2, 1, __qtablewidgetitem26);
        tableWidgetQuadroHor->setObjectName("tableWidgetQuadroHor");
        tableWidgetQuadroHor->setGeometry(QRect(250, 70, 771, 601));
        tableWidgetQuadroHor->setStyleSheet(QString::fromUtf8("background-color: white;"));
        botaoEditar = new QPushButton(centralwidget);
        botaoEditar->setObjectName("botaoEditar");
        botaoEditar->setGeometry(QRect(1050, 280, 131, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(12);
        font1.setBold(true);
        botaoEditar->setFont(font1);
        botaoEditar->setToolTipDuration(-4);
        botaoEditar->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        botaoSalvar = new QPushButton(centralwidget);
        botaoSalvar->setObjectName("botaoSalvar");
        botaoSalvar->setGeometry(QRect(1050, 440, 131, 61));
        botaoSalvar->setFont(font1);
        botaoSalvar->setToolTipDuration(-4);
        botaoSalvar->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 30px;"));
        botaoExcluir = new QPushButton(centralwidget);
        botaoExcluir->setObjectName("botaoExcluir");
        botaoExcluir->setGeometry(QRect(1050, 360, 131, 61));
        botaoExcluir->setFont(font1);
        botaoExcluir->setToolTipDuration(-4);
        botaoExcluir->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 30px;"));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidgetQuadroHor->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QuadroDeHorarios", "Seg", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetQuadroHor->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QuadroDeHorarios", "Ter", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetQuadroHor->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QuadroDeHorarios", "Qua", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetQuadroHor->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QuadroDeHorarios", "Qui", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetQuadroHor->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QuadroDeHorarios", "Sex", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetQuadroHor->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("QuadroDeHorarios", "Sab", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetQuadroHor->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("QuadroDeHorarios", "Dom", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetQuadroHor->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("QuadroDeHorarios", "5h \303\240s 6h", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetQuadroHor->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("QuadroDeHorarios", "6h \303\240s 7h", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetQuadroHor->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("QuadroDeHorarios", "7h \303\240s 8h", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetQuadroHor->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("QuadroDeHorarios", "8h \303\240s 9h", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetQuadroHor->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("QuadroDeHorarios", "9h \303\240s 10h", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetQuadroHor->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("QuadroDeHorarios", "10h \303\240s 11h", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetQuadroHor->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("QuadroDeHorarios", "11h \303\240s 12h", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetQuadroHor->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("QuadroDeHorarios", "12h \303\240s 13h", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetQuadroHor->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("QuadroDeHorarios", "13h \303\240s 14h", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetQuadroHor->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("QuadroDeHorarios", "14h \303\240s 15h", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetQuadroHor->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("QuadroDeHorarios", "15h \303\240s 16h", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetQuadroHor->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("QuadroDeHorarios", "16h \303\240s 17h", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetQuadroHor->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("QuadroDeHorarios", "17h \303\240s 18h", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetQuadroHor->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("QuadroDeHorarios", "18h \303\240s 19h", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetQuadroHor->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("QuadroDeHorarios", "19h \303\240s 20h", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetQuadroHor->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("QuadroDeHorarios", "20h \303\240s 21h", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetQuadroHor->verticalHeaderItem(16);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("QuadroDeHorarios", "21h \303\240s 22h", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetQuadroHor->verticalHeaderItem(17);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("QuadroDeHorarios", "22h \303\240s 23h", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetQuadroHor->verticalHeaderItem(18);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("QuadroDeHorarios", "23h \303\240s 00h", nullptr));

        const bool __sortingEnabled = tableWidgetQuadroHor->isSortingEnabled();
        tableWidgetQuadroHor->setSortingEnabled(false);
        tableWidgetQuadroHor->setSortingEnabled(__sortingEnabled);

        botaoEditar->setText(QCoreApplication::translate("QuadroDeHorarios", "Editar", nullptr));
        botaoSalvar->setText(QCoreApplication::translate("QuadroDeHorarios", "Salvar", nullptr));
        botaoExcluir->setText(QCoreApplication::translate("QuadroDeHorarios", "Excluir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuadroDeHorarios: public Ui_QuadroDeHorarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADRODEHORARIOS_H
