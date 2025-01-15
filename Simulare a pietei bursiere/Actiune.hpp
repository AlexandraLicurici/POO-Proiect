#ifndef ACTIUNE_HPP
#define ACTIUNE_HPP

#include <string>
#include <iostream>

class Actiune {
private:
    std::string simbol;
    double pret;

public:
    Actiune(const std::string& simbol, double pret) : simbol(simbol), pret(pret) {}

    // Getter pentru simbol
    std::string getSimbol() const { return simbol; }

    // Getter și setter pentru preț
    double getPret() const { return pret; }
    void schimbaPret(double variatie) { pret += pret * variatie; }
};

#endif
