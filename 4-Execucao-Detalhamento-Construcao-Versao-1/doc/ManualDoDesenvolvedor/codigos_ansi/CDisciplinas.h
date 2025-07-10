#ifndef CDISCIPLINAS_H
#define CDISCIPLINAS_H

#include <string>
#include <vector>
#include <iostream>
#include <Qstring>

// Classe que representa as disciplinas
class CDisciplinas {
public:
    int periodo;                             // Per�odo da disciplina
    std::string nome;                        // Nome da disciplina
    int creditos;                            // Cr�ditos da disciplina
    int cargaHoraria;                        // Carga hor�ria
    std::vector<std::string> preRequisitos;  // Lista de pr�-requisitos
    std::vector<std::string> coRequisitos;   // Lista de co-requisitos
    std::string eixoTematico;                // Eixo tem�tico da disciplina
    std::string ciclo;                       // Ciclo da disciplina (B�sico, Profissionalizante, etc.)
    int nivelDificuldade;                    // N�vel de dificuldade
    int horaSemanalAula;                     // Horas Semanais de Aula
    QString diasHorarios;


    // Construtor para inicializar os atributos da disciplina
    CDisciplinas(int periodo, std::string nome, int creditos, int cargaHoraria,
                 std::vector<std::string> preRequisitos,
                 std::vector<std::string> coRequisitos,
                 std::string eixoTematico, std::string ciclo,
                 int nivelDificuldade, int horaSemanalAula)
        : periodo(periodo), nome(nome), creditos(creditos), cargaHoraria(cargaHoraria),
        preRequisitos(preRequisitos), coRequisitos(coRequisitos),
        eixoTematico(eixoTematico), ciclo(ciclo), nivelDificuldade(nivelDificuldade), horaSemanalAula(horaSemanalAula) {}

    // M�todo para exibir as informa��es de uma disciplina
    void exibirInformacoes() const {
        std::cout << "Per�odo: " << periodo << ", Nome: " << nome << ", Carga Hor�ria: " << cargaHoraria
                  << "h, Cr�ditos: " << creditos << ", Eixo Tem�tico: " << eixoTematico << ", Ciclo: " << ciclo
                  << ", N�vel de Dificuldade: " << nivelDificuldade << "\n";

        if (!preRequisitos.empty()) {
            std::cout << "Pr�-requisitos: ";
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
    }

    int getHoras() const{

        return horaSemanalAula;
    }

    int getCH() const{
        return cargaHoraria;
    }


};

// Fun��o para retornar todas as disciplinas j� pr�-definidas
std::vector<CDisciplinas> getDisciplinasCurso();

int calcularCargaHorariaTotalCurso();


#endif
