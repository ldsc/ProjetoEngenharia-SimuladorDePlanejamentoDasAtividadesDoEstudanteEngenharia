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
#include <QLabel>

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
    QFont fonte("Bookman Old Style", 6);

    // ========================= TAB 1 - GRADE GERAL =========================
    QVBoxLayout *layoutTab1 = new QVBoxLayout;
    layoutTab1->setContentsMargins(20, 20, 20, 20);

    for (int periodo = 1; periodo <= 10; ++periodo) {
        QHBoxLayout *linhaPeriodo = new QHBoxLayout;
        linhaPeriodo->setSpacing(10);  // espaçamento entre botões

        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setFont(fonte);
            botao->setMinimumSize(140, 30);
            botao->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

            QString eixo = QString::fromStdString(disc.eixoTematico);
            QString cor;

            if (eixo == "Geologia e Geoquimica") cor = "#FF6B6B";
            else if (eixo == "Geral") cor = "#D3D3D3";
            else if (eixo == "Modelagem Matematica Computacional") cor = "#FFF799";
            else if (eixo == "Geofisica") cor = "#ADD8E6";
            else if (eixo == "Optativa") cor = "#C39BD3";
            else if (eixo == "Petrofisica") cor = "#90EE90";
            else if (eixo == "Engenharia de Petroleo") cor = "#4169E1";
            else if (eixo.startsWith("Exigencia")) cor = "#000000; color: white";
            else cor = "#D3D3D3";

            botao->setStyleSheet("background-color: " + cor + "; padding: 4px; border-radius: 6px;");
            linhaPeriodo->addWidget(botao);
        }

        layoutTab1->addLayout(linhaPeriodo);
    }

    QVBoxLayout *containerTab1Layout = new QVBoxLayout(ui->widget_gradeGeral);
    containerTab1Layout->addLayout(layoutTab1);

    // ========================= TAB 2 - GRADE COM PROGRESSO =========================
    QVBoxLayout *layoutTab2 = new QVBoxLayout;

    for (int periodo = 1; periodo <= 10; ++periodo) {
        QHBoxLayout *linhaPeriodo = new QHBoxLayout;
        linhaPeriodo->setSpacing(10);

        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setFont(fonte);
            botao->setMinimumSize(140, 30);

            QString cor = "background-color: lightgray";

            bool aprovada = std::any_of(
                aluno.disciplinasAprovadas.begin(), aluno.disciplinasAprovadas.end(),
                [&disc](const CDisciplinas& d) { return d.nome == disc.nome; });

            if (aprovada) cor = "background-color: lightgreen";
            else {
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

            botao->setStyleSheet(cor + "; padding: 4px; border-radius: 8px;");
            linhaPeriodo->addWidget(botao);
        }

        layoutTab2->addLayout(linhaPeriodo);
    }

    QVBoxLayout *layoutProgresso = new QVBoxLayout(ui->widget_gradeProgresso);
    layoutProgresso->addLayout(layoutTab2);

    // ========================= TAB 3 - GRADE DIFICULDADE =========================
    QVBoxLayout *layoutTab3 = new QVBoxLayout;
    layoutTab3->setContentsMargins(20, 30, 20, 20);
    layoutTab3->setSpacing(25);

    for (int periodo = 1; periodo <= 10; ++periodo) {
        QHBoxLayout *linhaPeriodo = new QHBoxLayout;
        linhaPeriodo->setSpacing(15);

        for (const auto& disc : todas) {
            if (disc.periodo != periodo) continue;

            QPushButton *botao = new QPushButton(QString::fromStdString(disc.nome));
            botao->setFont(fonte);
            botao->setMinimumSize(140, 30);
            botao->setStyleSheet("background-color: lightgray; padding: 4px; border-radius: 6px;");

            linhaPeriodo->addWidget(botao);
        }

        layoutTab3->addLayout(linhaPeriodo);
    }

    QVBoxLayout *layoutDificuldade = new QVBoxLayout(ui->widget_gradeDificuldade);
    layoutDificuldade->addLayout(layoutTab3);
}
