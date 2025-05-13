#ifndef ACOMPANHAMENTODISCIPLINA_H
#define ACOMPANHAMENTODISCIPLINA_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QPair>
#include <QList>

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

    void preencherAmbosLayouts(const QString& trabStr, const QString& provaStr);
    void preencherNotas(QHBoxLayout* layout, const QString& notasStr, double& somaNotas, double& somaPesos, QList<QPair<QLabel*, double>>& previsoesCinza);
    void atualizarMediaGeral(double somaNotas, double somaPesos, QList<QPair<QLabel*, double>> previsoesCinza);
};

#endif
