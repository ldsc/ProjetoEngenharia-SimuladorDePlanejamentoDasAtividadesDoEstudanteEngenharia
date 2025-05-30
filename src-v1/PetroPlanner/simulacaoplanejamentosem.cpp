#include "simulacaoplanejamentosem.h"
#include "ui_simulacaoplanejamentosem.h"

SimulacaoPlanejamentoSEM::SimulacaoPlanejamentoSEM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimulacaoPlanejamentoSEM)
{
    ui->setupUi(this);
}

SimulacaoPlanejamentoSEM::~SimulacaoPlanejamentoSEM()
{
    delete ui;
}
