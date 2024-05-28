#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

class Personaje {
protected:
    int vida;
    int ataque;
    std::string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje(const std::string& nombre, int vida, int ataque)
        : nombre(nombre), vida(vida), ataque(ataque), posicionX(0), posicionY(0) {}

    int getVida() const { return vida; }
    int getAtaque() const { return ataque; }
    std::string getNombre() const { return nombre; }
    int getPosX() const { return posicionX; }
    int getPosY() const { return posicionY; }

    void setVida(int v) { vida = v; }
    void setPosX(int x) { posicionX = x; }
    void setPosY(int y) { posicionY = y; }

    void recibirDano(int dano) { vida -= dano; }
};

#endif // PERSONAJE_H
