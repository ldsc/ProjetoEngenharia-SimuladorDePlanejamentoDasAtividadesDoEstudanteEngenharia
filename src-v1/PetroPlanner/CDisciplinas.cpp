#include "CDisciplinas.h"
#include <vector>
#include <iostream>

std::vector<CDisciplinas> getDisciplinasCurso() {
    std::vector<CDisciplinas> disciplinas;

    // Periodo 1
    disciplinas.push_back(CDisciplinas(1, "Quimica Geral I", 3, 51, {}, {}, "Geologia e Geoquimica", "Basico" , 3, 3));
    disciplinas.push_back(CDisciplinas(1, "Portugues Instrumental I", 2, 68, {}, {}, "Geral", "Basico" , 1, 2));
    disciplinas.push_back(CDisciplinas(1, "Desenho Tecnico", 2, 85, {} , {} , "Geral", "Basico" , 3, 4));
    disciplinas.push_back(CDisciplinas(1, "Calculo Diferencial e Integral I", 6, 102, {}, {}, "Modelagem Matematica Computacional", "Basico" , 5, 4));
    disciplinas.push_back(CDisciplinas(1, "Introducao a Engenharia de Petroleo", 2, 34, {}, {}, "Modelagem Matematica Computacional", "Basico" , 2, 2));
    disciplinas.push_back(CDisciplinas(1, "Fundamentos da Ciencia da Computacao", 4, 85, {}, {}, "Modelagem Matematica Computacional", "Basico" , 2, 4));

    // Periodo 2
    disciplinas.push_back(CDisciplinas(2, "Quimica Geral II", 3, 51, {"Quimica geral I"}, {}, "Geologia e Geoquimica", "Basico" , 3, 3));
    disciplinas.push_back(CDisciplinas(2, "Portugues Instrumental II", 2, 68, {}, {}, "Geral", "Basico" , 1, 2));
    disciplinas.push_back(CDisciplinas(2, "Optativa do CCH", 2, 68, {}, {}, "Optativa", "Basico" , 1, 2));
    disciplinas.push_back(CDisciplinas(2, "Fisica I", 4, 68, {"Calculo Diferencial e Integral I"}, {"Fisica Experimental I"}, "Geofisica", "Basico" , 4, 4));
    disciplinas.push_back(CDisciplinas(2, "Fisica Experimental I", 1, 34, {"Calculo Diferencial e Integral I"}, {"Fisica I"}, "Geofisica", "Basico" , 2, 4));
    disciplinas.push_back(CDisciplinas(2, "Calculo Diferencial e Integral II", 5, 68, {"Calculo Diferencial e Integral I"}, {}, "Modelagem Matematica Computacional", "Basico" , 5, 4));
    disciplinas.push_back(CDisciplinas(2, "Higiene e Seguranca do Trabalho", 2, 34, {}, {}, "Geral", "Basico" , 1, 2));
    disciplinas.push_back(CDisciplinas(2, "Algebra Linear", 4, 68, {}, {}, "Modelagem Matematica Computacional", "Basico" , 4, 4));

    // Periodo 3
    disciplinas.push_back(CDisciplinas(3, "Laboratorio de Quimica Analitica", 1, 34, {"Quimica Geral II"}, {"Quimica Analitica"}, "Geologia e Geoquimica", "Basico" , 1, 4));
    disciplinas.push_back(CDisciplinas(3, "Quimica Analitica", 3, 51, {"Quimica Geral II"}, {"Laboratorio de Quimica Analitica"}, "Geologia e Geoquimica", "Basico" , 3, 4));
    disciplinas.push_back(CDisciplinas(3, "Introducao a Economia", 4, 68, {"Calculo Diferencial e Integral II"}, {}, "Geral", "Basico" , 1, 4));
    disciplinas.push_back(CDisciplinas(3, "Fisica II", 4, 68, {"Fisica I", "Fisica Experimental I", "Calculo Diferencial e Integral II"}, {"Fisica Experimental II"}, "Geofisica", "Basico" , 4, 4));
    disciplinas.push_back(CDisciplinas(3, "Fisica Experimental II", 1, 34, {"Fisica I", "Fisica Experimental I"}, {"Fisica II"}, "Geofisica", "Basico" , 2, 4));
    disciplinas.push_back(CDisciplinas(3, "Calculo Diferencial e Integral III", 4, 68, {"Calculo Diferencial e Integral II"}, {}, "Modelagem Matematica Computacional", "Basico" , 5, 4));
    disciplinas.push_back(CDisciplinas(3, "Introducao a Probabilidade e Estatistica", 4, 68, {"Calculo Diferencial e Integral I"}, {}, "Modelagem Matematica Computacional", "Basico" , 4, 4));

    // Periodo 4
    disciplinas.push_back(CDisciplinas(4, "Quimica Organica", 4, 68, {"Quimica Geral I"}, {}, "Geologia e Geoquimica", "Basico" , 4, 4));
    disciplinas.push_back(CDisciplinas(4, "Optativa do CCH", 2, 68, {}, {}, "Geral", "Basico" , 1, 2));
    disciplinas.push_back(CDisciplinas(4, "Fisica III", 4, 68, {"Fisica II", "Fisica Experimental II", "Calculo Diferencial e Integral III" }, {"Fisica Experimental III"}, "Geofisica", "Basico" , 4, 4));
    disciplinas.push_back(CDisciplinas(4, "Fisica Experimental III", 1, 34, {"Fisica II", "Fisica Experimental II", "Calculo Diferencial e Integral III"}, {"Fisica III"}, "Geofisica", "Basico" , 2, 4));
    disciplinas.push_back(CDisciplinas(4, "Termodinamica para Engenharia", 4, 68, {"Quimica Geral I", "Calculo Diferencial e Integral II"}, {}, "Engenharia de Petroleo", "Basico" , 3, 4));
    disciplinas.push_back(CDisciplinas(4, "Calculo Numerico", 4, 68, {"Algebra Linear", "Fundamentos da Ciencia da Computacao"}, {}, "Modelagem Matematica Computacional", "Basico" , 3, 4));

    // Periodo 5
    disciplinas.push_back(CDisciplinas(5, "Geologia Fisica", 4, 68, {}, {}, "Geologia e Geoquimica", "Profissionalizante" , 2, 3));
    disciplinas.push_back(CDisciplinas(5, "Introducao a Analise e Processamento de Sinais", 4, 68, {"Calculo Diferencial e Integral III"}, {}, "Geofisica", "Profissionalizante" , 4, 4));
    disciplinas.push_back(CDisciplinas(5, "Resistencia dos Materiais", 4, 68, {"Calculo Diferencial e Integral III"}, {}, "Petrofisica", "Profissionalizante" , 1, 4));
    disciplinas.push_back(CDisciplinas(5, "Mecanica dos Fluidos", 4, 68, {"Fisica III"}, {},"Engenharia de Petroleo", "Profissionalizante" , 5, 4));
    disciplinas.push_back(CDisciplinas(5, "Fisica-Matematica I", 4, 68, {"Calculo Diferencial e Integral II"}, {}, "Modelagem Matematica Computacional", "Profissionalizante" , 2, 4));
    disciplinas.push_back(CDisciplinas(5, "Introducao ao Projeto de Engenharia", 3, 51, {"Introducao a Engenharia de Petroleo", "Fundamentos da Ciencia da Computacao"}, {}, "Modelagem Matematica Computacional", "Profissionalizante" , 3, 3));

    // Periodo 6
    disciplinas.push_back(CDisciplinas(6, "Mineralogia e Petrologia de Rochas Reservatorio", 3, 51, {"Geologia Fisica"}, {}, "Geologia e Geoquimica", "Profissionalizante" , 2, 3));
    disciplinas.push_back(CDisciplinas(6, "Metodos Geofisicos de Exploracao", 4, 68, {"Fisica III", "Introducao a Analise e Processamento de Sinais"}, {},"Geofisica", "Profissionalizante" , 2, 4));
    disciplinas.push_back(CDisciplinas(6, "Propriedades Fisicas de Minerais e Rochas", 4, 68, {"Fisica III"}, {}, "Petrofisica", "Profissionalizante" , 2, 4));
    disciplinas.push_back(CDisciplinas(6, "Engenharia de Reservatorios I", 4, 68, {"Termodinamica para Engenharia"}, {}, "Engenharia de Petroleo", "Profissionalizante" , 5, 4));
    disciplinas.push_back(CDisciplinas(6, "Fisica-Matematica II", 4, 68, {"Fisica-Matematica I"}, {}, "Modelagem Matematica Computacional", "Profissionalizante" , 2, 4));
    disciplinas.push_back(CDisciplinas(6, "Programacao Orientada a Objeto com C++", 3, 51, {"Introducao a Probabilidade e Estatistica", "Calculo Numerico","Introducao ao Projeto de Engenharia"}, {}, "Modelagem Matematica Computacional", "Profissionalizante" , 5, 3));

    // Periodo 7
    disciplinas.push_back(CDisciplinas(7, "Geoquimica do Petroleo", 3, 51, {"Quimica Organica","Mineralogia e Petrologia de Rochas Reservatorio"}, {}, "Geologia e Geoquimica", "Profissionalizante" , 2, 3));
    disciplinas.push_back(CDisciplinas(7, "Estratigrafia e Sedimentacao", 3, 51, {"Geologia Fisica"}, {}, "Geologia e Geoquimica", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(7, "Analise de Dados Experimentais", 4, 68, {"Metodos Geofisicos de Exploracao"},{}, "Geofisica", "Profissionalizante" , 2, 4));
    disciplinas.push_back(CDisciplinas(7, "Petrofisica Experimental", 2, 68, {"Propriedades Fisicas de Minerais e Rochas"}, {}, "Petrofisica", "Profissionalizante" , 1, 4));
    disciplinas.push_back(CDisciplinas(7, "Engenharia de Reservatorios II", 4, 51, {"Engenharia de Reservatorios I"}, {}, "Engenharia de Petroleo", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(7, "Tecnicas de Modelamento Numerico I", 4, 68, {"Fisica-Matematica II", "Programacao Orientada a Objeto com C++"},{}, "Modelagem Matematica Computacional", "Profissionalizante" , 3,4));

    // Periodo 8
    disciplinas.push_back(CDisciplinas(8, "Geologia do Petroleo", 3, 51, {"Geoquimica do Petroleo"}, {}, "Geologia e Geoquimica", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(8, "Controle Ambiental na Industria do Petroleo", 3, 51, {}, {}, "Geologia e Geoquimica", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(8, "Perfilagem de Pocos I", 4, 68, {"Propriedades Fisicas de Minerais e Rochas"}, {}, "Petrofisica", "Profissionalizante" , 3, 4));
    disciplinas.push_back(CDisciplinas(8, "Elevacao e Escoamento", 4, 68, {"Mecanica dos Fluidos"}, {}, "Engenharia de Petroleo", "Profissionalizante" , 3, 4));
    disciplinas.push_back(CDisciplinas(8, "Engenharia de Poco", 4, 68, {"Mecanica dos Fluidos"}, {}, "Engenharia de Petroleo", "Profissionalizante" , 3, 4));
    disciplinas.push_back(CDisciplinas(8, "Projeto de Software Aplicado a Engenharia", 2, 34, {"Programacao Orientada a Objeto com C++"}, {}, "Modelagem Matematica Computacional", "Profissionalizante" , 3, 4));


    // Periodo 9
    disciplinas.push_back(CDisciplinas(9, "Perfilagem de Pocos II", 4, 68, {"Perfilagem de Pocos I"}, {}, "Petrofisica", "Profissionalizante" , 3, 4));
    disciplinas.push_back(CDisciplinas(9, "Seminarios em Engenharia de Petroleo", 1, 17, {}, {}, "Geral", "Profissionalizante" , 3, 1));
    disciplinas.push_back(CDisciplinas(9, "Optativa 1", 2, 0 , {}, {}, "Optativa", "Profissionalizante" , 3, 2));
    disciplinas.push_back(CDisciplinas(9, "Optativa 2", 3, 0 , {}, {}, "Optativa", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(9, "Exigencia Trabalho Conclusao Curso", 0 , 34, {}, {}, "Exigencia", "Profissionalizante" , 3, 0));

    // Periodo 10
    disciplinas.push_back(CDisciplinas(10, "Energias Renovaveis", 2, 51, {}, {}, "Geral", "Profissionalizante" , 3, 3));
    disciplinas.push_back(CDisciplinas(10, "Optativa 3", 4, 0 , {}, {}, "Optativa", "Profissionalizante" , 3, 4));
    disciplinas.push_back(CDisciplinas(10, "Exigencia Trabalho de Conclusao de Curso", 0 , 34, {}, {}, "Exigencia", "Profissionalizante" , 0, 0));
    disciplinas.push_back(CDisciplinas(10, "Exigencia Estagio Curricular Obrigatorio", 0 , 170, {}, {}, "Exigencia", "Profissionalizante" , 0, 0));
    disciplinas.push_back(CDisciplinas(10, "Exigencia Atividades Academicas Complementares", 0 , 60, {}, {}, "Exigencia", "Profissionalizante" , 0, 0));
    disciplinas.push_back(CDisciplinas(10, "Exigencia Atividades Curriculares de Extensao", 0 , 370, {}, {}, "Exigencia", "Profissionalizante" , 0, 0));
    disciplinas.push_back(CDisciplinas(10, "Exigencia Projeto de Trabalho de Conclusao de Curso", 0  , 68, {}, {}, "Exigencia", "Profissionalizante" , 0, 0));



    return disciplinas;
}

int calcularCargaHorariaTotalCurso() {
    std::vector<CDisciplinas> todas = getDisciplinasCurso();
    int total = 0;
    for (const auto& disc : todas) {
        total += disc.getCH();
    }
    return total;
}

