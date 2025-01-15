#ifndef PIATA_HPP
#define PIATA_HPP

#include <vector>
#include "Companie.hpp"

class Piata {
private:
    std::vector<Companie> companii;

public:
    void adaugaCompanie(const Companie& companie) {
        companii.push_back(companie);
    }

    std::vector<Companie>& getCompanii() {
        return companii;
    }

    Companie* cautaCompanie(const std::string& simbol) {
        for (auto& companie : companii) {
            if (companie.getSimbol() == simbol) {
                return &companie;
            }
        }
        return nullptr;
    }

    void afiseazaPiata() const {
        for (const auto& companie : companii) {
            companie.afiseazaDetalii();
        }
    }
};

#endif
