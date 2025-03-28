#include "CDisciplinas.h"
#include <vector>
#include <iostream>

std::vector<CDisciplinas> getDisciplinasCurso() {
    std::vector<CDisciplinas> disciplinas;

    // Periodo 1
    disciplinas.push_back(CDisciplinas(1, "Quimica Geral", 4, 51, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Portugues Instrumental I", 2, 34, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Desenho Tecnico", 2, 68, {}, "Engenharia de Petroleo", "Basico"));

    // Periodo 2
    disciplinas.push_back(CDisciplinas(2, "Quimica Geral II", 4, 51, {"Quimica Geral"}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Portugues Instrumental II", 2, 34, {"Portugues Instrumental I"}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Fisica I", 4, 68, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Risco Experimental I", 2, 34, {}, "Geofisica", "Basico"));

    // Periodo 3
    disciplinas.push_back(CDisciplinas(3, "Laboratorio de Quimica Analitica", 1, 34, {"Quimica Geral"}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Fisica II", 4, 68, {"Fisica I"}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Risco Experimental II", 2, 34, {"Risco Experimental I"}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Calculo Diferencial e Integral I", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Fundamentos de Computacao", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 4
    disciplinas.push_back(CDisciplinas(4, "Fisica III", 4, 68, {"Fisica II"}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Risco Experimental III", 2, 34, {"Risco Experimental II"}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Calculo Diferencial e Integral II", 4, 68, {"Calculo Diferencial e Integral I"}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 5
    disciplinas.push_back(CDisciplinas(5, "Geologia Fisica", 4, 68, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Introducao a Analise de Processamento de Sinais", 4, 68, {}, "Geofisica", "Profissionalizante"));

    // Periodo 6
    disciplinas.push_back(CDisciplinas(6, "Mineralogia e Petrologia de Rochas Reservatorio", 4, 68, {"Geologia Fisica"}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Propriedades Fisicas de Rochas Reservatorio", 4, 68, {"Introducao a Analise de Processamento de Sinais"}, "Geofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Termodinamica", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));

    // Periodo 7
    disciplinas.push_back(CDisciplinas(7, "Geologia do Petroleo", 4, 68, {"Mineralogia e Petrologia de Rochas Reservatorio"}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Engenharia de Reservatorio", 4, 68, {"Termodinamica"}, "Engenharia de Petroleo", "Profissionalizante"));

    // Periodo 8
    disciplinas.push_back(CDisciplinas(8, "Petrofisica", 4, 68, {"Geologia do Petroleo"}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Tecnicas de Modelamento Numerico", 4, 68, {}, "Modelagem Matematica Computacional", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Engenharia de Producao", 4, 68, {"Engenharia de Reservatorio"}, "Engenharia de Petroleo", "Profissionalizante"));

    // Periodo 9
    disciplinas.push_back(CDisciplinas(9, "Engenharia de Projetos", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(9, "Petrofisica Avancada", 4, 68, {"Petrofisica"}, "Petrofisica", "Profissionalizante"));

    return disciplinas;
}
