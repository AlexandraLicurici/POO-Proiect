#ifndef STRATEGII_HPP
#define STRATEGII_HPP

#include <cstdlib>

class Strategie {
public:
    virtual double calculeazaVariatiePret() = 0;
};

class StrategieSimple : public Strategie {
public:
    double calculeazaVariatiePret() override {

        return (rand() % 100) / 1000.0 - 0.05;
    }
};

#endif
