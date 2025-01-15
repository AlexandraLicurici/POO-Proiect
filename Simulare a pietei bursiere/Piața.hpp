#ifndef PIATA_HPP
#define PIATA_HPP

#include <vector>
#include "Actiune.hpp"

class Piața {
private:
    std::vector<Actiune> actiuni;

public:
    void adaugaActiune(const Actiune& actiune) {
        actiuni.push_back(actiune);
    }

    std::vector<Actiune>& getActiuni() { return actiuni; }
};

#endif
