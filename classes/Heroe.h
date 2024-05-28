#ifndef HEROE_H
#define HEROE_H

#include "Personaje.h"

class Heroe : public Personaje {
public:
    Heroe(const std::string& nombre, int vida, int ataque)
        : Personaje(nombre, vida, ataque) {}

    // Métodos específicos para el héroe
};

#endif // HEROE_H
