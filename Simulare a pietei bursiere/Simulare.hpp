#ifndef SIMULARE_HPP
#define SIMULARE_HPP

#include "Piata.hpp"
#include "Trader.hpp"
#include "Strategii.hpp"
#include <iostream>

class Simulare {
private:
    Piata& piata;
    std::vector<Trader>& traderi;
    Strategie& strategie;

public:
    Simulare(Piata& p, std::vector<Trader>& t, Strategie& s) : piata(p), traderi(t), strategie(s) {}

    void ruleaza(int pasi) {
        for (int i = 0; i < pasi; i++) {
            std::cout << "\n--- Pasul " << i + 1 << " ---\n";

            // Fluctuatii preturi
            for (auto& companie : piata.getCompanii()) {
                double variatie = strategie.calculeazaVariatiePret();
                companie.setPret(companie.getPret() + companie.getPret() * variatie);
                std::cout << "Pretul actualizat al actiunii " << companie.getSimbol() << ": " << companie.getPret() << std::endl;
            }

            // Tranzactii traderi
            for (auto& trader : traderi) {
                if (i % 2 == 0) { // Exemplu de logica de tranzactionare
                    trader.cumpara(*piata.cautaCompanie("AAPL"), 10);
                } else {
                    trader.vinde(*piata.cautaCompanie("GOOG"), 5);
                }
                trader.afiseazaPortofoliu();
            }

            std::cout << "----------------------------------\n";
        }
        std::cout << "Simularea a fost completa!" << std::endl;
    }
};

#endif
