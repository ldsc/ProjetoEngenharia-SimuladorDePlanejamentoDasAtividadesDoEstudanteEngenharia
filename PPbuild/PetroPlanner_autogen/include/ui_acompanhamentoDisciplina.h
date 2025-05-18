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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QGroupBox *groupBoxDiscAnd;
    QLabel *labelTrab;
    QLabel *labelDiscAnd;
    QLabel *labelProvas;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayoutTrabs;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayoutProvas;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *botaoAdcTrab;
    QPushButton *botaoRemTrab;
    QPushButton *botaoAdcProva;
    QPushButton *botaoRemProva;
    QPushButton *botaoEditar;
    QPushButton *botaoSalvar;
    QLabel *labelProvas_2;
    QLabel *labelMedia;
    QProgressBar *progressBarFaltas;
    QLabel *labelFaltas;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AcompanhamentoDisciplina)
    {
        if (AcompanhamentoDisciplina->objectName().isEmpty())
            AcompanhamentoDisciplina->setObjectName("AcompanhamentoDisciplina");
        AcompanhamentoDisciplina->resize(992, 879);
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
        pushButton_DiscEmAnd->setGeometry(QRect(40, 70, 621, 51));
        pushButton_DiscEmAnd->setStyleSheet(QString::fromUtf8("background-color: #82b4cf;  color: black ; border-radius: 15px; font-weight: bold;"));
        label_NomeDisc = new QLabel(centralwidget);
        label_NomeDisc->setObjectName("label_NomeDisc");
        label_NomeDisc->setGeometry(QRect(60, 90, 581, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setBold(true);
        label_NomeDisc->setFont(font1);
        label_NomeDisc->setStyleSheet(QString::fromUtf8("background: none;  qproperty-alignment: 'AlignHCenter';"));
        groupBoxDiscAnd = new QGroupBox(centralwidget);
        groupBoxDiscAnd->setObjectName("groupBoxDiscAnd");
        groupBoxDiscAnd->setGeometry(QRect(40, 170, 701, 411));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Book Antiqua")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(false);
        groupBoxDiscAnd->setFont(font2);
        groupBoxDiscAnd->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        groupBoxDiscAnd->setStyleSheet(QString::fromUtf8("background-color: white; color: black; border: none; border-radius: 30px;"));
        labelTrab = new QLabel(groupBoxDiscAnd);
        labelTrab->setObjectName("labelTrab");
        labelTrab->setGeometry(QRect(40, 120, 121, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font3.setPointSize(10);
        font3.setBold(false);
        labelTrab->setFont(font3);
        labelTrab->setStyleSheet(QString::fromUtf8(""));
        labelDiscAnd = new QLabel(groupBoxDiscAnd);
        labelDiscAnd->setObjectName("labelDiscAnd");
        labelDiscAnd->setGeometry(QRect(90, 20, 421, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font4.setPointSize(18);
        font4.setBold(true);
        labelDiscAnd->setFont(font4);
        labelDiscAnd->setStyleSheet(QString::fromUtf8("color: black"));
        labelProvas = new QLabel(groupBoxDiscAnd);
        labelProvas->setObjectName("labelProvas");
        labelProvas->setGeometry(QRect(50, 220, 121, 21));
        labelProvas->setFont(font3);
        labelProvas->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget = new QWidget(groupBoxDiscAnd);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(130, 80, 381, 81));
        horizontalLayoutTrabs = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayoutTrabs->setObjectName("horizontalLayoutTrabs");
        horizontalLayoutTrabs->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(groupBoxDiscAnd);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(130, 180, 381, 81));
        horizontalLayoutProvas = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayoutProvas->setObjectName("horizontalLayoutProvas");
        horizontalLayoutProvas->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(groupBoxDiscAnd);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(50, 370, 121, 21));
        label1->setFont(font3);
        label1->setStyleSheet(QString::fromUtf8(""));
        label2 = new QLabel(groupBoxDiscAnd);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(190, 370, 141, 21));
        label2->setFont(font3);
        label2->setStyleSheet(QString::fromUtf8(""));
        label3 = new QLabel(groupBoxDiscAnd);
        label3->setObjectName("label3");
        label3->setGeometry(QRect(370, 370, 141, 21));
        label3->setFont(font3);
        label3->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(groupBoxDiscAnd);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 370, 12, 12));
        label->setStyleSheet(QString::fromUtf8("background-color: green; /* ou red, yellow, etc */\n"
"border-radius: 6px;       /* metade do tamanho para ficar circular */\n"
"min-width: 12px;\n"
"min-height: 12px;\n"
"max-width: 12px;\n"
"max-height: 12px;\n"
""));
        label_2 = new QLabel(groupBoxDiscAnd);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 370, 12, 12));
        label_2->setStyleSheet(QString::fromUtf8("background-color: gray; border-radius: 6px; min-width: 12px;\n"
"min-height: 12px;\n"
"max-width: 12px;\n"
"max-height: 12px;\n"
""));
        label_3 = new QLabel(groupBoxDiscAnd);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(350, 370, 12, 12));
        label_3->setStyleSheet(QString::fromUtf8("background-color: red; border-radius: 6px; min-width: 12px;\n"
"min-height: 12px;\n"
"max-width: 12px;\n"
"max-height: 12px;\n"
""));
        botaoAdcTrab = new QPushButton(groupBoxDiscAnd);
        botaoAdcTrab->setObjectName("botaoAdcTrab");
        botaoAdcTrab->setGeometry(QRect(610, 80, 70, 70));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font5.setPointSize(12);
        font5.setBold(true);
        botaoAdcTrab->setFont(font5);
        botaoAdcTrab->setToolTipDuration(-4);
        botaoAdcTrab->setStyleSheet(QString::fromUtf8("background-color:#a6a6a6; color: white; border-radius: 35px;"));
        botaoRemTrab = new QPushButton(groupBoxDiscAnd);
        botaoRemTrab->setObjectName("botaoRemTrab");
        botaoRemTrab->setGeometry(QRect(530, 80, 70, 70));
        botaoRemTrab->setFont(font5);
        botaoRemTrab->setToolTipDuration(-4);
        botaoRemTrab->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 35px;"));
        botaoAdcProva = new QPushButton(groupBoxDiscAnd);
        botaoAdcProva->setObjectName("botaoAdcProva");
        botaoAdcProva->setGeometry(QRect(610, 180, 70, 70));
        botaoAdcProva->setFont(font5);
        botaoAdcProva->setToolTipDuration(-4);
        botaoAdcProva->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 35px;"));
        botaoRemProva = new QPushButton(groupBoxDiscAnd);
        botaoRemProva->setObjectName("botaoRemProva");
        botaoRemProva->setGeometry(QRect(530, 180, 70, 70));
        botaoRemProva->setFont(font5);
        botaoRemProva->setToolTipDuration(-4);
        botaoRemProva->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 35px;"));
        botaoEditar = new QPushButton(groupBoxDiscAnd);
        botaoEditar->setObjectName("botaoEditar");
        botaoEditar->setGeometry(QRect(540, 260, 131, 61));
        botaoEditar->setFont(font5);
        botaoEditar->setToolTipDuration(-4);
        botaoEditar->setStyleSheet(QString::fromUtf8("background-color: #ffa308; color: white; border-radius: 30px;"));
        botaoSalvar = new QPushButton(groupBoxDiscAnd);
        botaoSalvar->setObjectName("botaoSalvar");
        botaoSalvar->setGeometry(QRect(540, 330, 131, 61));
        botaoSalvar->setFont(font5);
        botaoSalvar->setToolTipDuration(-4);
        botaoSalvar->setStyleSheet(QString::fromUtf8("background-color: #a6a6a6; color: white; border-radius: 30px;"));
        labelProvas_2 = new QLabel(groupBoxDiscAnd);
        labelProvas_2->setObjectName("labelProvas_2");
        labelProvas_2->setGeometry(QRect(50, 310, 121, 21));
        labelProvas_2->setFont(font3);
        labelProvas_2->setStyleSheet(QString::fromUtf8(""));
        labelMedia = new QLabel(groupBoxDiscAnd);
        labelMedia->setObjectName("labelMedia");
        labelMedia->setGeometry(QRect(130, 310, 121, 21));
        labelMedia->setFont(font4);
        labelMedia->setStyleSheet(QString::fromUtf8("color: black"));
        progressBarFaltas = new QProgressBar(centralwidget);
        progressBarFaltas->setObjectName("progressBarFaltas");
        progressBarFaltas->setGeometry(QRect(10, 630, 731, 31));
        progressBarFaltas->setStyleSheet(QString::fromUtf8("QProgressBar {color: white;    border: 2px solid white;    border-radius: 8px;  text-align: center;} QProgressBar::chunk {background-color: #82b4cf; border-radius: 6px;}"));
        progressBarFaltas->setMinimum(6);
        progressBarFaltas->setValue(80);
        labelFaltas = new QLabel(centralwidget);
        labelFaltas->setObjectName("labelFaltas");
        labelFaltas->setGeometry(QRect(760, 640, 201, 16));
        labelFaltas->setFont(font1);
        labelFaltas->setStyleSheet(QString::fromUtf8("color: white"));
        AcompanhamentoDisciplina->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AcompanhamentoDisciplina);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 992, 22));
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
        groupBoxDiscAnd->setTitle(QString());
        labelTrab->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Trabalhos:", nullptr));
        labelDiscAnd->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Acompanhamento das Avalia\303\247\303\265es", nullptr));
        labelProvas->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Provas:", nullptr));
        label1->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Nota a se tirar", nullptr));
        label2->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Nota acima da m\303\251dia", nullptr));
        label3->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Nota abaixo da m\303\251dia", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        botaoAdcTrab->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "+ Trab", nullptr));
        botaoRemTrab->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "- Trab", nullptr));
        botaoAdcProva->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "+ Prova", nullptr));
        botaoRemProva->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "- Prova", nullptr));
        botaoEditar->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Editar", nullptr));
        botaoSalvar->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Salvar", nullptr));
        labelProvas_2->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "M\303\251dia:", nullptr));
        labelMedia->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "Media", nullptr));
        labelFaltas->setText(QCoreApplication::translate("AcompanhamentoDisciplina", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AcompanhamentoDisciplina: public Ui_AcompanhamentoDisciplina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACOMPANHAMENTODISCIPLINA_H
