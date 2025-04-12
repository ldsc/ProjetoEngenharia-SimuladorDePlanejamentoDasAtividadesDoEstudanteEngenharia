#include "CDisciplinas.h"
#include <vector>
#include <iostream>

std::vector<CDisciplinas> getDisciplinasCurso() {
    std::vector<CDisciplinas> disciplinas;

    // Periodo 1
    disciplinas.push_back(CDisciplinas(1, "Quimica Geral I", 3, 51, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Portugues Instrumental I", 2, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Desenho Tecnico", 2, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Calculo Diferencial e Integral I", 6, 102, {}, "Modelagem Matematica Computacional", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Introducao a Engenharia de Petroleo", 2, 34, {}, "Modelagem Matematica Computacional", "Basico"));
    disciplinas.push_back(CDisciplinas(1, "Fundamentos da Ciencia da Computacao", 4, 85, {}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 2
    disciplinas.push_back(CDisciplinas(2, "Quimica Geral II", 3, 51, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Portugues Instrumental II", 2, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Optativa do CCH", 2, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Fisica I", 4, 68, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Fisica Experimental I", 1, 34, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Calculo Diferencial e Integral II", 5, 68, {}, "Modelagem Matematica Computacional", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Higiene e Seguranca do Trabalho", 2, 34, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(2, "Algebra Linear", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 3
    disciplinas.push_back(CDisciplinas(3, "Laboratorio de Quimica Analitica", 1, 34, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Quimica Analitica", 3, 51, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Introducao a Economia", 4, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Fisica II", 4, 68, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Fisica Experimental II", 1, 34, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Calculo Diferencial e Integral III", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));
    disciplinas.push_back(CDisciplinas(3, "Introducao a Probabilidade e Estatistica", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 4
    disciplinas.push_back(CDisciplinas(4, "Quimica Organica", 4, 68, {}, "Geologia e Geoquimica", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Optativa do CCH", 2, 68, {}, "Geral", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Fisica III", 4, 68, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Fisica Experimental III", 1, 34, {}, "Geofisica", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Termodinamica para Engenharia", 4, 68, {}, "Engenharia de Petroleo", "Basico"));
    disciplinas.push_back(CDisciplinas(4, "Calculo Numerico", 4, 68, {}, "Modelagem Matematica Computacional", "Basico"));

    // Periodo 5
    disciplinas.push_back(CDisciplinas(5, "Geologia Fisica", 4, 68, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Introducao a Analise e Processamento de Sinais", 4, 68, {}, "Geofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Resistencia dos Materiais", 4, 68, {}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Mecanica dos Fluidos", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Fisica-Matematica I", 4, 68, {}, "Modelagem Matematica Computacional", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(5, "Introducao ao Projeto de Engenharia", 3, 51, {}, "Modelagem Matematica Computacional", "Profissionalizante"));

    // Periodo 6
    disciplinas.push_back(CDisciplinas(6, "Mineralogia e Petrologia de Rochas Reservatorio", 3, 51, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Metodos Geofisicos de Exploracao", 4, 68, {}, "Geofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Propriedades Fisicas de Minerais e Rochas", 4, 68, {}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Engenharia de Reservatorios I", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Fisica-Matematica II", 4, 68, {}, "Modelagem Matematica Computacional", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(6, "Programacao Orientada a Objeto com C++", 3, 51, {}, "Modelagem Matematica Computacional", "Profissionalizante"));

    // Periodo 7
    disciplinas.push_back(CDisciplinas(7, "Geoquimica do Petroleo", 3, 51, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Estratigrafia e Sedimentacao", 3, 51, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Analise de Dados Experimentais", 4, 68, {}, "Geofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Petrofisica Experimental", 2, 68, {}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Engenharia de Reservatorios II", 4, 51, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(7, "Tecnicas de Modelamento Numerico I", 4, 68, {}, "Modelagem Matematica Computacional", "Profissionalizante"));

    // Periodo 8
    disciplinas.push_back(CDisciplinas(8, "Geologia do Petroleo", 3, 51, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Controle Ambiental na Industria do Petroleo", 3, 51, {}, "Geologia e Geoquimica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Perfilagem de Pocos I", 4, 68, {}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Elevacao e Escoamento", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Engenharia de Poco", 4, 68, {}, "Engenharia de Petroleo", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(8, "Projeto de Software Aplicado a Engenharia", 2, 34, {}, "Modelagem Matematica Computacional", "Profissionalizante"));


    // Periodo 9
    disciplinas.push_back(CDisciplinas(9, "Perfilagem de Pocos II", 4, 68, {}, "Petrofisica", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(9, "Seminarios em Engenharia de Petroleo", 1, 17, {}, "Geral", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(9, "Optativa 1*", 2, ?, {}, "Geral", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(9, "Optativa 2*", 3, ?, {}, "Geral", "Profissionalizante"));

    // Periodo 10
    disciplinas.push_back(CDisciplinas(10, "Energias Renovaveis", 2, 51, {}, "Geral", "Profissionalizante"));
    disciplinas.push_back(CDisciplinas(10, "Optativa 3*", 4, ?, {}, "Geral", "Profissionalizante"));
    

    return disciplinas;
}
