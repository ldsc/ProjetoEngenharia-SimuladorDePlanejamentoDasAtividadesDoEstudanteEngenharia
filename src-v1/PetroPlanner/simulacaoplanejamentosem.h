#ifndef SIMULACAOPLANEJAMENTOSEM_H
#define SIMULACAOPLANEJAMENTOSEM_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMap>
#include <QSet>
#include <QCheckBox>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include "caluno.h"

namespace Ui {
class SimulacaoPlanejamentoSEM;
}

class SimulacaoPlanejamentoSEM : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulacaoPlanejamentoSEM(CAluno* aluno, QWidget *parent = nullptr);
    ~SimulacaoPlanejamentoSEM();

private slots:
    void avancarSemestre();
    void salvarComoImagem();

private:
    Ui::SimulacaoPlanejamentoSEM *ui;
    CAluno* aluno;

    int periodoAtualSimulado;

    QWidget* container;
    QVBoxLayout* layoutSimulacao;
    QScrollArea* scrollArea;

    struct SimulacaoSemestre {
        int numero;
        QHBoxLayout* layoutCheck;
        QHBoxLayout* layoutDisciplinas;
        QList<QCheckBox*> checkboxes;
        QMap<QString, QPushButton*> botoesDisciplinas;
        QSet<QString> disciplinasEscolhidas;
    };

    QVector<SimulacaoSemestre> semestres;
    QVector<CDisciplinas> disciplinasDisponiveis;
    QVector<CDisciplinas> disciplinasAprovadas;
    QVector<CDisciplinas> disciplinasEmCurso;

    bool preRequisitosOk(const CDisciplinas& disc) const;
    void atualizarSemestres();
};

#endif
