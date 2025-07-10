#include "EditarDisciplinasEmCurso.h"
#include "ui_EditarDisciplinasEmCurso.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

EditarDisciplinasEmCurso::EditarDisciplinasEmCurso(CAluno* aluno, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditarDisciplinasEmCurso),
    aluno(aluno)
{
    ui->setupUi(this);


    // Deixar botões OK e Cancel brancos
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



    // Disciplinas em curso (já marcadas)
    for (const CDisciplinas& disc : aluno->disciplinasEmCurso) {
        QString nome = QString::fromStdString(disc.nome);
        QCheckBox* cb = new QCheckBox(nome);
        cb->setChecked(true);
        cb->setStyleSheet(style);
        layout->addWidget(cb);
        checkboxes[nome] = cb;
    }

    // Disciplinas não cursadas (sempre adiciona, sem checar duplicidade)
    for (const CDisciplinas& disc : aluno->disciplinasNaoCursadas) {
        QString nome = QString::fromStdString(disc.nome);

        // Se já foi adicionada, apenas desmarcar e seguir
        if (checkboxes.contains(nome)) {
            checkboxes[nome]->setChecked(false);
            continue;
        }

        // Senão, criar nova checkbox
        QCheckBox* cb = new QCheckBox(nome);
        cb->setChecked(false);
        cb->setStyleSheet(style);
        layout->addWidget(cb);
        checkboxes[nome] = cb;
    }

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &EditarDisciplinasEmCurso::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &EditarDisciplinasEmCurso::on_buttonBox_rejected);


}


EditarDisciplinasEmCurso::~EditarDisciplinasEmCurso()
{
    delete ui;
}

void EditarDisciplinasEmCurso::on_buttonBox_accepted()
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
                linha = linha.section(";", 0, 2) + "; Em Curso";
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

void EditarDisciplinasEmCurso::on_buttonBox_rejected()
{
    reject(); // Fecha sem fazer nada
}
