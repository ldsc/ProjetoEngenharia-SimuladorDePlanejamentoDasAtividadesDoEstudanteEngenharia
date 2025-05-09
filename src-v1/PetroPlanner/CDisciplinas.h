#ifndef CDISCIPLINAS_H
#define CDISCIPLINAS_H

#include <string>
#include <vector>
#include <iostream>

// Classe que representa as disciplinas
class CDisciplinas {
public:
    int periodo;                             // Período da disciplina
    std::string nome;                        // Nome da disciplina
    int creditos;                            // Créditos da disciplina
    int cargaHoraria;                        // Carga horária
    std::vector<std::string> preRequisitos;  // Lista de pré-requisitos
    std::vector<std::string> coRequisitos;   // Lista de co-requisitos
    std::string eixoTematico;                // Eixo temático da disciplina
    std::string ciclo;                       // Ciclo da disciplina (Básico, Profissionalizante, etc.)
    int nivelDificuldade;                    // Nível de dificuldade
    int horaSemanalAula;                     // Horas Semanais de Aula

    // Construtor para inicializar os atributos da disciplina
    CDisciplinas(int periodo, std::string nome, int creditos, int cargaHoraria,
                 std::vector<std::string> preRequisitos,
                 std::vector<std::string> coRequisitos,
                 std::string eixoTematico, std::string ciclo,
                 int nivelDificuldade, int horaSemanalAula)
        : periodo(periodo), nome(nome), creditos(creditos), cargaHoraria(cargaHoraria),
        preRequisitos(preRequisitos), coRequisitos(coRequisitos),
        eixoTematico(eixoTematico), ciclo(ciclo), nivelDificuldade(nivelDificuldade), horaSemanalAula(horaSemanalAula) {}

    // Método para exibir as informações de uma disciplina
    void exibirInformacoes() const {
        std::cout << "Período: " << periodo << ", Nome: " << nome << ", Carga Horária: " << cargaHoraria
                  << "h, Créditos: " << creditos << ", Eixo Temático: " << eixoTematico << ", Ciclo: " << ciclo
                  << ", Nível de Dificuldade: " << nivelDificuldade << "\n";

        if (!preRequisitos.empty()) {
            std::cout << "Pré-requisitos: ";
            for (const auto& pre : preRequisitos)
                std::cout << pre << " ";
            std::cout << "\n";
        }

        if (!coRequisitos.empty()) {
            std::cout << "Co-requisitos: ";
            for (const auto& co : coRequisitos)
                std::cout << co << " ";
            std::cout << "\n";
        }

    }


    std::string getNome() const {

        return nome;
    };

    int getHoras() const{

        return horaSemanalAula;
    };


};

// Função para retornar todas as disciplinas já pré-definidas
std::vector<CDisciplinas> getDisciplinasCurso();

#endif
