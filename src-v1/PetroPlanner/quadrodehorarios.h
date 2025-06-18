#ifndef QUADRODEHORARIOS_H
#define QUADRODEHORARIOS_H

#include <QMainWindow>
#include "caluno.h"

namespace Ui {
class QuadroDeHorarios;
}

class QuadroDeHorarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadroDeHorarios(CAluno* aluno, QWidget *parent = nullptr);
    ~QuadroDeHorarios();

private slots:
    void aoClicarEditar();
    void aoClicarSalvar();
    void aoClicarSimplesCelula(int row, int column);
    void aoSelecionarDisciplina(const QString& nomeSelecionado);

private:
    Ui::QuadroDeHorarios *ui;
    CAluno* aluno;

    void preencherQuadro();
    int horarioParaLinha(const QString& horario);
    int diaParaColuna(const QString& dia);
    void definirModoEdicao(bool ativo);

    bool modoEdicaoAtivo = false;

    QMap<QString, QColor> mapaCores;
    QList<QColor> coresDisponiveis;

    void carregarAtividadesExtras();
    void salvarAtividadesExtras();
};

#endif
