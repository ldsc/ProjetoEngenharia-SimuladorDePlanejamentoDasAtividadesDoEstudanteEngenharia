#ifndef CDISCIPLINAS_H
#define CDISCIPLINAS_H

#include <string>
#include <vector>
#include <iostream>

// Classe que representa as disciplinas
class CDisciplinas {
public:
    int periodo;                 // Período da disciplina
    std::string nome;            // Nome da disciplina
    int creditos;                // Créditos da disciplina
    int cargaHoraria;            // Carga horária
    std::vector<std::string> preRequisitos;  // Lista de pré-requisitos
    std::string eixoTematico;    // Eixo temático da disciplina
    std::string ciclo;           // Ciclo da disciplina (Básico, Profissionalizante, etc.)

    // Construtor para inicializar os atributos da disciplina
    CDisciplinas(int periodo, std::string nome, int creditos, int cargaHoraria, std::vector<std::string> preRequisitos, std::string eixoTematico, std::string ciclo)
        : periodo(periodo), nome(nome), creditos(creditos), cargaHoraria(cargaHoraria), preRequisitos(preRequisitos), eixoTematico(eixoTematico), ciclo(ciclo) {}

    // Método para exibir as informações de uma disciplina
    void exibirInformacoes() const {
        std::cout << "Período: " << periodo << ", Nome: " << nome << ", Carga Horária: " << cargaHoraria
                  << "h, Créditos: " << creditos << ", Eixo Temático: " << eixoTematico << ", Ciclo: " << ciclo << "\n";
        if (!preRequisitos.empty()) {
            std::cout << "Pré-requisitos: ";
            for (const auto& pre : preRequisitos) {
                std::cout << pre << " ";
            }
            std::cout << "\n";
        }
    }
};

// Função para retornar todas as disciplinas já pré-definidas
std::vector<CDisciplinas> getDisciplinasCurso();

#endif
