#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje {
public:
    Enemigo(const std::string& nombre, int vida, int ataque)
        : Personaje(nombre, vida, ataque) {}

    // Métodos específicos para el enemigo
};

#endif // ENEMIGO_H
