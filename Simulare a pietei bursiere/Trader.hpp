#ifndef TRADER_HPP
#define TRADER_HPP

#include <string>
#include <vector>
#include "Companie.hpp"

class Trader {
private:
    std::string nume;
    double capital;
    std::vector<std::pair<Companie, int>> portofoliu;

public:
    Trader(const std::string& nume, double capital) : nume(nume), capital(capital) {}

    std::string getNume() const { return nume; }
    double getCapital() const { return capital; }

    void cumpara(Companie& companie, int cantitate) {
        double cost = companie.getPret() * cantitate;
        if (cost <= capital) {
            capital -= cost;
            portofoliu.push_back({companie, cantitate});
            std::cout << nume << " a cumparat " << cantitate << " actiuni " << companie.getSimbol() << std::endl;
        } else {
            std::cout << nume << " nu are suficient capital pentru a cumpara " << cantitate << " actiuni " << companie.getSimbol() << std::endl;
        }
    }

    void vinde(Companie& companie, int cantitate) {
        for (auto& actiune : portofoliu) {
            if (actiune.first.getSimbol() == companie.getSimbol() && actiune.second >= cantitate) {
                actiune.second -= cantitate;
                capital += companie.getPret() * cantitate;
                std::cout << nume << " a vandut " << cantitate << " actiuni " << companie.getSimbol() << std::endl;
                return;
            }
        }
        std::cout << nume << " nu detine suficient " << companie.getSimbol() << " pentru a vinde " << cantitate << " actiuni." << std::endl;
    }

    void afiseazaPortofoliu() const {
        std::cout << nume << " - Capital: " << capital << " - Portofoliu: \n";
        for (const auto& actiune : portofoliu) {
            std::cout << "  " << actiune.first.getSimbol() << ": " << actiune.second << " actiuni\n";
        }
    }
};

#endif
