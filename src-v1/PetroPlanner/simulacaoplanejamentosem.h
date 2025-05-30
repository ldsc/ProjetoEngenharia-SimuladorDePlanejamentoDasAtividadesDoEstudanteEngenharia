#ifndef SIMULACAOPLANEJAMENTOSEM_H
#define SIMULACAOPLANEJAMENTOSEM_H

#include <QMainWindow>

namespace Ui {
class SimulacaoPlanejamentoSEM;
}

class SimulacaoPlanejamentoSEM : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulacaoPlanejamentoSEM(QWidget *parent = nullptr);
    ~SimulacaoPlanejamentoSEM();

private:
    Ui::SimulacaoPlanejamentoSEM *ui;
};

#endif
