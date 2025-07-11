#include "EditarDisciplinasAprovadas.h"
#include "ui_EditarDisciplinasAprovadas.h"
#include "CDisciplinas.h"
#include "CAluno.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

EditarDisciplinasAprovadas::EditarDisciplinasAprovadas(CAluno* aluno, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::EditarDisciplinasAprovadas),
    aluno(aluno)
{
    ui->setupUi(this);

    ui->buttonBox->setStyleSheet(R"(
        QPushButton {
            color: white;
            background-color: transparent;
            border: 2px solid white;
            border-radius: 6px;
            padding: 6px 12px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #82b4cf;
        }
    )");

    ui->scrollArea->setStyleSheet(R"(
        QScrollBar:vertical, QScrollBar:horizontal {
            background: transparent;
            width: 12px;
            height: 12px;
            margin: 0px;
        }

        QScrollBar::handle:vertical, QScrollBar::handle:horizontal {
            background: white;
            border-radius: 6px;
            min-height: 20px;
            min-width: 20px;
        }

        QScrollBar::add-line, QScrollBar::sub-line {
            background: none;
            border: none;
        }

        QScrollBar::add-page, QScrollBar::sub-page {
            background: none;
        }
    )");

    if (!ui->scrollAreaContent->layout()) {
        QVBoxLayout* layout = new QVBoxLayout();
        ui->scrollAreaContent->setLayout(layout);
    }

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaContent->layout());
    ui->scrollArea->setWidget(ui->scrollAreaContent);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollAreaContent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);

    QString style = R"(
        QCheckBox {
            color: white;
            font-weight: bold;
        }
        QCheckBox::indicator {
            width: 18px;
            height: 18px;
        }
        QCheckBox::indicator:checked {
            background-color: #82b4cf;
            border: 1px solid white;
        }
        QCheckBox::indicator:unchecked {
            background-color: transparent;
            border: 1px solid white;
        }
    )";

    // Leitura do arquivo para saber quais disciplinas estão aprovadas
    QMap<QString, QString> statusDisciplinas;
    QFile file("InformacoesAluno.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString linha = in.readLine();
            QString nome = linha.section(";", 1, 1).trimmed();
            QString status = linha.section(";", 3, 3).trimmed();
            statusDisciplinas[nome] = status;
        }
        file.close();
    }

    // Mostrar TODAS as disciplinas do curso
    for (const CDisciplinas& disc : getDisciplinasCurso()) {
       QString nome = QString::fromStdString(disc.nome);
        QCheckBox* cb = new QCheckBox(nome);
        cb->setStyleSheet(style);

        // Marcar se está "Aprovada" no txt
        if (statusDisciplinas.contains(nome) && statusDisciplinas[nome] == "Aprovada") {
            cb->setChecked(true);
        } else {
            cb->setChecked(false);
        }

        layout->addWidget(cb);
        checkboxes[nome] = cb;
    }

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &EditarDisciplinasAprovadas::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &EditarDisciplinasAprovadas::on_buttonBox_rejected);
}

EditarDisciplinasAprovadas::~EditarDisciplinasAprovadas()
{
    delete ui;
}

void EditarDisciplinasAprovadas::on_buttonBox_accepted()
{
    QFile file("InformacoesAluno.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList linhas;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linha = in.readLine();
        QString nome = linha.section(";", 1, 1).trimmed();

        if (checkboxes.contains(nome)) {
            if (checkboxes[nome]->isChecked()) {
                linha = linha.section(";", 0, 2) + "; Aprovada";
            } else {
                linha = linha.section(";", 0, 2) + "; Nao Cursada";
            }
        }

        linhas << linha;
    }
    file.close();

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString& l : linhas)
            out << l << "\n";
        file.close();
    }

    accept(); // Fecha com sucesso
}

void EditarDisciplinasAprovadas::on_buttonBox_rejected()
{
    reject(); // Fecha sem salvar
}
