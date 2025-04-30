#ifndef CDISCIPLINAS_H
#define CDISCIPLINAS_H

#include <string>
#include <vector>

class CDisciplinas {
private:
    int periodo;
    std::string nome;
    int creditos;
    int cargaHoraria;
    std::vector<std::string> preRequisitos;
    std::vector<std::string> coRequisitos; 
    std::string area;
    std::string nivel;

public:
    // Construtor com pré e co-requisitos separados
    CDisciplinas(int periodo, const std::string& nome, int creditos, int cargaHoraria,
                 const std::vector<std::string>& preRequisitos,
                 const std::vector<std::string>& coRequisitos,
                 const std::string& area, const std::string& nivel);

    // Getters 
    std::vector<std::string> getPreRequisitos() const;
    std::vector<std::string> getCoRequisitos() const;
    std::string getNome() const;
    int getPeriodo() const;

    
};

#endif
