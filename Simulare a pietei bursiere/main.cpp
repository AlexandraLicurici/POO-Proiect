#include <iostream>
#include "Companie.hpp"
#include "Piata.hpp"
#include "Strategii.hpp"
#include "Trader.hpp"
#include "Simulare.hpp"

int main() {

    Companie companie1("Apple Inc.", "AAPL", 150.0);
    Companie companie2("Google LLC", "GOOG", 2800.0);
    Companie companie3("Tesla", "TSLA", 700.0);
    Companie companie4("Microsoft", "MSFT", 300.0);
    Companie companie5("Amazon", "AMZN", 3500.0);


    Piata piata;
    piata.adaugaCompanie(companie1);
    piata.adaugaCompanie(companie2);
    piata.adaugaCompanie(companie3);
    piata.adaugaCompanie(companie4);
    piata.adaugaCompanie(companie5);


    Trader trader1("John Doe", 5000);
    Trader trader2("Jane Smith", 3000);
    Trader trader3("Alice Johnson", 10000);
    Trader trader4("Bob Brown", 7000);

    std::vector<Trader> traderi = {trader1, trader2, trader3, trader4};


    StrategieSimple strategie;


    Simulare simulare(piata, traderi, strategie);


    simulare.ruleaza(10);

    return 0;
}
