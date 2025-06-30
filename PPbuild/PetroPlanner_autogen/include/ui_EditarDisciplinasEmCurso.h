/********************************************************************************
** Form generated from reading UI file 'editardisciplinasemcurso.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARDISCIPLINASEMCURSO_H
#define UI_EDITARDISCIPLINASEMCURSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditarDisciplinasEmCurso
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelTitulo;
    QScrollArea *scrollArea;
    QWidget *scrollAreaContent;
    QWidget *widget;

    void setupUi(QDialog *EditarDisciplinasEmCurso)
    {
        if (EditarDisciplinasEmCurso->objectName().isEmpty())
            EditarDisciplinasEmCurso->setObjectName("EditarDisciplinasEmCurso");
        EditarDisciplinasEmCurso->resize(854, 502);
        EditarDisciplinasEmCurso->setStyleSheet(QString::fromUtf8("background-color: blue;"));
        buttonBox = new QDialogButtonBox(EditarDisciplinasEmCurso);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(470, 440, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        labelTitulo = new QLabel(EditarDisciplinasEmCurso);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setGeometry(QRect(180, 20, 541, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(24);
        font.setBold(true);
        labelTitulo->setFont(font);
        labelTitulo->setStyleSheet(QString::fromUtf8("color: white"));
        scrollArea = new QScrollArea(EditarDisciplinasEmCurso);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(150, 90, 651, 331));
        scrollArea->setWidgetResizable(true);
        scrollAreaContent = new QWidget();
        scrollAreaContent->setObjectName("scrollAreaContent");
        scrollAreaContent->setGeometry(QRect(0, 0, 649, 329));
        widget = new QWidget(scrollAreaContent);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 651, 331));
        scrollArea->setWidget(scrollAreaContent);

        retranslateUi(EditarDisciplinasEmCurso);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditarDisciplinasEmCurso, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditarDisciplinasEmCurso, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditarDisciplinasEmCurso);
    } // setupUi

    void retranslateUi(QDialog *EditarDisciplinasEmCurso)
    {
        EditarDisciplinasEmCurso->setWindowTitle(QCoreApplication::translate("EditarDisciplinasEmCurso", "Dialog", nullptr));
        labelTitulo->setText(QCoreApplication::translate("EditarDisciplinasEmCurso", "Marque as Disciplinas em Curso", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditarDisciplinasEmCurso: public Ui_EditarDisciplinasEmCurso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARDISCIPLINASEMCURSO_H
