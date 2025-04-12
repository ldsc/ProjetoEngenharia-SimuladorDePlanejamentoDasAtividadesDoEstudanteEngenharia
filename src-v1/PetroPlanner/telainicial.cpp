#include "telainicial.h"
#include "ui_telainicial.h"
#include "CAluno.h"
#include <QMessageBox>

TelaInicial::TelaInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaInicial)
    , gradeCompleta(nullptr)
{
    ui->setupUi(this);
    carregarInformacoesAluno();
}

TelaInicial::~TelaInicial()
{
    delete ui;
    if (gradeCompleta) {
        delete gradeCompleta;
    }
}

void TelaInicial::on_botaoVerGradeCompleta_clicked()
{
    if (!gradeCompleta) {
        gradeCompleta = new ModuloGradeCompleta(aluno, this);
    }
    gradeCompleta->show();
}

void TelaInicial::carregarInformacoesAluno()
{
    CAluno aluno;
    if (!aluno.lerDoArquivo("InformacoesAluno.txt")) {
        QMessageBox::warning(this, "Erro", "Não foi possível carregar o arquivo InformacoesAluno.txt");
        return;
    }

    ui->labelNome->setText("Nome: " + aluno.nome);
    ui->labelMatricula->setText("Matrícula: " + aluno.matricula);
    ui->labelCurso->setText("Curso: " + aluno.curso);
    ui->labelPeriodo->setText("Período: " + QString::number(aluno.periodo));
    ui->labelCRA->setText("CRA: " + QString::number(aluno.cra));
}
