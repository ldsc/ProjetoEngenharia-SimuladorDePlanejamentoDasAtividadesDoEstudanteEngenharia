#include "telainicial.h"
#include "ui_telainicial.h"
#include "CAluno.h"
#include <QMessageBox>
#include <QScreen>
#include <QFile>
#include <QTextStream>

TelaInicial::TelaInicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TelaInicial)
    , gradeCompleta(nullptr){
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

    QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContentsFaltas);
    ui->scrollAreaWidgetContentsFaltas->setLayout(layout);

    // Preenche a lista de faltas
    preencherFaltasEmGrupoBox(&aluno);


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
    QuadroDeHorarios* quadro = new QuadroDeHorarios(&aluno, this);
    quadro->show();
}


void TelaInicial::preencherFaltasEmGrupoBox(CAluno* aluno) {
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContentsFaltas->layout());
    if (!layout) return;

    // Limpa o conteúdo anterior
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    std::vector<CDisciplinas> todas = getDisciplinasCurso();

    for (const CDisciplinas& disc : todas) {
        QString nome = QString::fromStdString(disc.getNome()).trimmed();
        int chSemanal = disc.getHoras();
        if (chSemanal <= 0) continue;

        // Verifica se é disciplina em andamento do aluno
        auto it = std::find_if(aluno->disciplinasEmCurso.begin(), aluno->disciplinasEmCurso.end(),
                               [&](const CDisciplinas& d) {
                                   return QString::fromStdString(d.nome).trimmed() == nome;
                               });
        if (it == aluno->disciplinasEmCurso.end()) continue;

        // Procura número de faltas no InformacoesAluno.txt
        int faltasRegistradas = 0;
        QFile file("InformacoesAluno.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString linha = in.readLine().trimmed();
                if (linha.startsWith(nome + " ;")) {
                    QString faltasStr = linha.section(";", 1, 1).trimmed();
                    faltasRegistradas = faltasStr.toInt();
                    break;
                }
            }
            file.close();
        }

        int faltasPossiveis = static_cast<int>(0.25 * chSemanal * 4 * 4);
        int faltasRestantes = faltasPossiveis - faltasRegistradas;

        // Cria QLabel e QProgressBar
        QLabel* label = new QLabel(nome);
        QProgressBar* barra = new QProgressBar;
        barra->setRange(0, faltasPossiveis);
        barra->setValue(faltasRestantes);
        barra->setFormat(QString("%1").arg(faltasRestantes));

        QString cor;
        if (faltasRestantes == faltasPossiveis)
            cor = "#90ee90";
        else if (faltasRestantes > 2)
            cor = "orange";
        else if (faltasRestantes == 1)
            cor = "orangered";
        else
            cor = "red";



        barra->setStyleSheet(
            "QProgressBar {"
            "  border: 2px solid blue;"
            "  border-radius: 8px;"
            "  text-align: center;"
            "}"
            "QProgressBar::chunk {"
            "  background-color: #82b4cf;"
            "  border-radius: 6px;"
            "}"
            );




        // Adiciona horizontalmente
        QHBoxLayout* linha = new QHBoxLayout;
        linha->addWidget(label);
        linha->addWidget(barra);

        QWidget* container = new QWidget;
        container->setLayout(linha);

        layout->addWidget(container);
    }

    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}



void TelaInicial::on_botaoRefresh_clicked()
{
    aluno.lerDoArquivo("InformacoesAluno.txt"); // Atualiza os dados
    preencherFaltasEmGrupoBox(&aluno);          // Atualiza o conteúdo das faltas
}


