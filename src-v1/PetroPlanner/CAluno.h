#ifndef CFLUIDO_H
#define CFLUIDO_H

#include <string>

class CFluido {
protected:
    std::string nome;
    double densidade = 0.0;
    double viscosidade = 0.0;

public:
    // Construtor
    CFluido() {}
    ~CFluido() {}
    CFluido(std::string nome, double Dens, double visc)
    : nome(nome), densidade(Dens), viscosidade(visc) {}

    // Getters
    std::string Nome() const { return nome; }
    double Densidade() const { return densidade; }
    double Viscosidade() const { return viscosidade; }

    // Setters
    void Nome(double nome) { nome = nome; }
    void Densidade(double Dens) { densidade = Dens; }
    void Viscosidade(double visc) { viscosidade = visc; }

};

#endif
