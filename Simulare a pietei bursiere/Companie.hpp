#ifndef COMPANIE_HPP
#define COMPANIE_HPP

#include <string>
#include <iostream>

class Companie {
private:
    std::string nume;
    std::string simbol;
    double pret;

public:
    Companie(const std::string& nume, const std::string& simbol, double pret)
        : nume(nume), simbol(simbol), pret(pret) {}

    std::string getNume() const { return nume; }
    std::string getSimbol() const { return simbol; }
    double getPret() const { return pret; }
    void setPret(double p) { pret = p; }

    void afiseazaDetalii() const {
        std::cout << "Companie: " << nume << " (" << simbol << ") - Pret: " << pret << std::endl;
    }
};

#endif
