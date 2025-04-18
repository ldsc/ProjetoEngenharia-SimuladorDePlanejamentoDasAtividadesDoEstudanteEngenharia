#include "telainicial.h"
#include "ui_telainicial.h"
#include "CAluno.h"
#include <QMessageBox>
#include <QScreen>

TelaInicial::TelaInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaInicial)
    , gradeCompleta(nullptr)
{
    ui->setupUi(this);

    // Tamanho da janela igual ao da tela do computador
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        this->setGeometry(screen->geometry());
    }

    // Fundo azul claro
    this->setStyleSheet("background-color: #004AAD;");

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


    QString listaEmCurso;
    for (const auto& disc : aluno.disciplinasEmCurso) {
        listaEmCurso += QString::fromStdString(disc.nome) + ", ";
    }
    if (!listaEmCurso.isEmpty())
        listaEmCurso.chop(2); // Remove a última vírgula

    ui->labelDisciplinasEmCurso->setText("Disciplinas em curso: " + listaEmCurso);

}
