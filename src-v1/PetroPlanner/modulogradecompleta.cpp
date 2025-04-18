#include "modulogradecompleta.h"
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

    // ========================= TAB 1 - GRADE GERAL =========================
    QVBoxLayout *layoutTab1 = new QVBoxLayout;

    for (int periodo = 1; periodo <= 10; ++periodo) {
        QHBoxLayout *linhaPeriodo = new QHBoxLayout;

        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            botao->setMinimumWidth(140);
            botao->setMinimumHeight(30);
            botao->setStyleSheet("background-color: lightgray; padding: 2px; border-radius: 8px; font-size: 10pt;");
            linhaPeriodo->addWidget(botao);
        }

        layoutTab1->addLayout(linhaPeriodo);
    }

    QWidget *containerTab1 = new QWidget(this);
    containerTab1->setLayout(layoutTab1);

    QVBoxLayout *layoutGeral = new QVBoxLayout(ui->widget_gradeGeral);
    layoutGeral->addWidget(containerTab1);
    ui->widget_gradeGeral->setLayout(layoutGeral);

    // ========================= TAB 2 - GRADE COM PROGRESSO =========================
    QVBoxLayout *layoutTab2 = new QVBoxLayout;

    for (int periodo = 1; periodo <= 10; ++periodo) {
        QHBoxLayout *linhaPeriodo = new QHBoxLayout;

        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            botao->setMinimumWidth(140);
            botao->setMinimumHeight(30);

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

            botao->setStyleSheet(cor + "; padding: 2px; border-radius: 8px; font-size: 10pt;");
            linhaPeriodo->addWidget(botao);
        }

        layoutTab2->addLayout(linhaPeriodo);
    }

    QWidget *containerTab2 = new QWidget(this);
    containerTab2->setLayout(layoutTab2);

    QVBoxLayout *layoutProgresso = new QVBoxLayout(ui->widget_gradeProgresso);
    layoutProgresso->addWidget(containerTab2);
    ui->widget_gradeProgresso->setLayout(layoutProgresso);
}
