#include "modulogradecompleta.h"
#include "ui_modulogradecompleta.h"
#include "ui_modulogradecompleta.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScreen>
#include <QGuiApplication>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

ModuloGradeCompleta::ModuloGradeCompleta(const CAluno& alunoRef, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModuloGradeCompleta)
    , aluno(alunoRef)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        this->setGeometry(screen->geometry());
    }

    carregarDisciplinas();
}

ModuloGradeCompleta::~ModuloGradeCompleta()
{
    delete ui;
}

void ModuloGradeCompleta::carregarDisciplinas() {
    std::vector<CDisciplinas> todas = getDisciplinasCurso();
    QGridLayout *grade = new QGridLayout();
    int row = 0;

    for (int periodo = 1; periodo <= 10; ++periodo) {
        int col = 0;
        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            botao->setMinimumWidth(200);  // Largura mínima para nome caber
            botao->setMinimumHeight(40);  // Altura padrão

            QString cor = "background-color: lightgray";

            bool aprovada = std::any_of(
                aluno.disciplinasAprovadas.begin(), aluno.disciplinasAprovadas.end(),
                [&disc](const CDisciplinas& d) { return d.nome == disc.nome; });

            if (aprovada) {
                cor = "background-color: lightgreen";
            } else {
                QFile file("InformacoesAluno.txt");
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    while (!in.atEnd()) {
                        QString linha = in.readLine();
                        if (linha.contains(QString::fromStdString(disc.nome), Qt::CaseInsensitive)) {
                            QString ultimaSituacao;
                            QStringList partes = linha.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

                            for (int i = partes.size() - 1; i >= 0; --i) {
                                QString valor = partes[i];
                                if (valor == "Aprovada" || valor == "Reprovada") {
                                    ultimaSituacao = valor;
                                    break;
                                } else if (valor == "Curso" && i > 0 && partes[i - 1] == "Em") {
                                    ultimaSituacao = "Em Curso";
                                    break;
                                } else if (valor == "Cursada" && i > 0 && partes[i - 1] == "Nao") {
                                    ultimaSituacao = "Nao Cursada";
                                    break;
                                }
                            }

                            if (ultimaSituacao == "Aprovada") cor = "background-color: lightgreen";
                            else if (ultimaSituacao == "Reprovada") cor = "background-color: red";
                            else if (ultimaSituacao == "Em Curso") cor = "background-color: yellow";
                            else if (ultimaSituacao == "Nao Cursada") cor = "background-color: lightgray";

                            break;
                        }
                    }
                    file.close();
                }
            }

            botao->setStyleSheet(cor + "; padding: 6px; border-radius: 10px;");
            grade->addWidget(botao, row, col++);

            if (col > 5) {
                col = 0;
                row++;
            }
        }
        row++;
    }

    QWidget *containerGrade = new QWidget;
    containerGrade->setLayout(grade);

    QVBoxLayout *layoutVertical = new QVBoxLayout;
    layoutVertical->addSpacing(100);             // margem superior
    layoutVertical->addWidget(containerGrade);
    layoutVertical->addSpacing(80);             // margem inferior (6cm aprox)

    QHBoxLayout *layoutHorizontal = new QHBoxLayout;
    layoutHorizontal->addSpacing(50);           // margem esquerda REDUZIDA
    layoutHorizontal->addLayout(layoutVertical);
    layoutHorizontal->addSpacing(100);          // margem direita

    ui->centralwidget->setLayout(layoutHorizontal);

}
