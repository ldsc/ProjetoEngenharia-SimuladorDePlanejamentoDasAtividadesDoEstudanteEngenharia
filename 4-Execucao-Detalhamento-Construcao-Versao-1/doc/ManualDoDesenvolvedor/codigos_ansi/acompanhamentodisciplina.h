#ifndef ACOMPANHAMENTODISCIPLINA_H
#define ACOMPANHAMENTODISCIPLINA_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QPair>
#include <QList>
#include <QLineEdit>
#include <QCheckBox>

namespace Ui {
class AcompanhamentoDisciplina;
}

class AcompanhamentoDisciplina : public QMainWindow
{
    Q_OBJECT

public:
    explicit AcompanhamentoDisciplina(const QString& nomeDisciplina, QWidget *parent = nullptr);
    ~AcompanhamentoDisciplina();



private:
    Ui::AcompanhamentoDisciplina *ui;
    bool modoEdicaoAtivo = false;

    void preencherAmbosLayouts(const QString& trabStr, const QString& provaStr);
    void preencherNotas(QHBoxLayout* layout, const QString& notasStr, double& somaNotas, double& somaPesos, QList<QPair<QLabel*, double>>& previsoesCinza);
    void atualizarMediaGeral(double somaNotas, double somaPesos, QList<QPair<QLabel*, double>> previsoesCinza);

    QString nomeAtualDisciplina;
    QStringList novaListaTrabalhos;
    QStringList novaListaProvas;

    struct EntradaNota {
        QLineEdit* editNota;
        QLineEdit* editPeso;
        QCheckBox* checkSimulado;
    };

    QList<EntradaNota> entradasTrabalhos;
    QList<EntradaNota> entradasProvas;

    QSet<QLineEdit*> camposSimulados;

    int faltasRegistradasTemp = 0;
    int faltasPossiveisTemp = 0;

    void atualizarFaltasTemp();


private slots:
    void aoClicarEditar();
    void aoClicarSalvar();
    void adicionarTrabalho();
    void removerTrabalho();
    void adicionarProva();
    void removerProva();
    void salvarAlteracoes();
    void atualizarMedia();
    void aoClicarFinalizarDisc();
    void adicionarFalta();
    void removerFalta();
    void atualizarFaltas();




};

#endif
