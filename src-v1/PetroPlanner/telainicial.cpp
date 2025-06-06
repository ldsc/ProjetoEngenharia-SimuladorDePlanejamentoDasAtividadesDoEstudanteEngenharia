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

    connect(ui->botaoSimulacao, &QPushButton::clicked, this, &TelaInicial::abrirTelaSimulacao);
    connect(ui->botaoQuadrodeHorarios, &QPushButton::clicked, this, &TelaInicial::abrirQuadroDeHorarios);


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

    if (!this->aluno.lerDoArquivo("InformacoesAluno.txt")) {
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





    //Aparecimento das horas cursadas em Disciplinas em andamento
    int horas = aluno.calcularHorasEmCurso();
    int limite = 16;

    ui->progressBarHoras->setMaximum(limite);
    ui->progressBarHoras->setValue(std::min(horas, limite)); // nunca passa de 16 na barra

    ui->labelHorasEmCurso2->setText(QString::number(horas) + "/16 horas");


    PreencherDisciplinasEmCurso(aluno.disciplinasEmCurso);

}


//Disciplinas em curso aparecerem na tela inicial
void TelaInicial::PreencherDisciplinasEmCurso(const std::vector<CDisciplinas>& disciplinasEmCurso) {
    // Cria um novo widget de conteúdo para o scroll
    QWidget* conteudo = new QWidget();
    QGridLayout* gridLayout = new QGridLayout(conteudo);
    conteudo->setLayout(gridLayout);

    int row = 0, col = 0;

    for (const auto& disc : disciplinasEmCurso) {
        QPushButton* botao = new QPushButton(QString::fromStdString(disc.nome));
        botao->setFixedSize(180, 40);
        botao->setStyleSheet("QPushButton {"
                             "background-color: #82b4cf;"
                             "color: black;"
                             "border-radius: 15px;"
                             "font-weight: bold;"
                             "}");

        connect(botao, &QPushButton::clicked, this, [=]() {
            abrirJanelaDisciplina(disc.nome);
        });

        gridLayout->addWidget(botao, row, col);
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }

    ui->scrollAreaDiscAnd->setWidget(conteudo);
    ui->scrollAreaDiscAnd->setWidgetResizable(true);


}



void TelaInicial::abrirJanelaDisciplina(const std::string& nomeDisciplina) {
    AcompanhamentoDisciplina* janela = new AcompanhamentoDisciplina(QString::fromStdString(nomeDisciplina), this);
    janela->show();
}



void TelaInicial::abrirTelaSimulacao()
{
    telaSimulacao = new SimulacaoPlanejamentoSEM(&aluno, this);
    telaSimulacao->show();
}


void TelaInicial::abrirQuadroDeHorarios() {
    QuadroDeHorarios* quadro = new QuadroDeHorarios(this);
    quadro->show();
}

