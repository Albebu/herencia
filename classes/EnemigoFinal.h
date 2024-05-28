#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Enemigo.h"
#include <cstdlib> // para rand()

class EnemigoFinal : public Enemigo {
private:
    int superAtaque1;
    int superAtaque2;

public:
    EnemigoFinal(const std::string& nombre, int vida, int ataque, int superAtaque1, int superAtaque2)
        : Enemigo(nombre, vida, ataque), superAtaque1(superAtaque1), superAtaque2(superAtaque2) {}

    int usarSuperAtaque() {
        int ataqueSeleccionado = rand() % 2;
        return ataqueSeleccionado == 0 ? superAtaque1 : superAtaque2;
    }
};

#endif // ENEMIGOFINAL_H
