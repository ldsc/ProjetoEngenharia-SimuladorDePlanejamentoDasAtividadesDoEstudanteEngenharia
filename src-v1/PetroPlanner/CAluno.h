#ifndef CALUNO_H
#define CALUNO_H

#include <QString>
#include <vector>
#include "CDisciplinas.h"

class CAluno {
public:
    QString nome;
    QString matricula;
    QString curso;
    int periodo = 0;
    float cra = 0.0;


    std::vector<CDisciplinas> disciplinasEmCurso;
    std::vector<CDisciplinas> disciplinasAprovadas;
    std::vector<CDisciplinas> disciplinasNaoCursadas;

    bool lerDoArquivo(const QString& caminho);
    int calcularHorasEmCurso() const;


};

#endif
