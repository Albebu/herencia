#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "classes/Heroe.h"
#include "classes/Enemigo.h"
#include "classes/EnemigoFinal.h"

const int WIDTH = 10;
const int HEIGHT = 10;

void createBoard(char board[HEIGHT][WIDTH], Heroe& hero, EnemigoFinal& boss, std::vector<Enemigo>& enemigos);
void printBoard(char board[HEIGHT][WIDTH], const Heroe& hero);
bool batalla(Personaje& p1, Personaje& p2);
bool isMoveValid(int x, int y);

int main()
{
    srand(time(0));

    Heroe hero("Heroe", 100, 10);
    EnemigoFinal boss("Boss", 150, 20, 30, 40);

    std::vector<Enemigo> enemigos;
    for (int i = 0; i < 10; ++i) {
        enemigos.push_back(Enemigo("Enemigo" + std::to_string(i), 50, 10));
    }

    char board[HEIGHT][WIDTH];
    createBoard(board, hero, boss, enemigos);
    printBoard(board, hero);

    char move;
    // Game loop
    while (hero.getVida() > 0) {
        std::cout << "Ingrese el movimiento (w/a/s/d): ";
        std::cin >> move;

        int newX = hero.getPosX();
        int newY = hero.getPosY();

        // Movimiento del héroe
        switch (move) {
            case 'w': // Arriba
                newX--;
                break;
            case 'a': // Izquierda
                newY--;
                break;
            case 's': // Abajo
                newX++;
                break;
            case 'd': // Derecha
                newY++;
                break;
            default:
                std::cout << "Movimiento no válido!\n";
                continue; // Ignorar movimientos inválidos
        }

        if (isMoveValid(newX, newY)) {
            // Chequear la casilla de destino
            if (board[newX][newY] == 'E') {
                // Encontramos un enemigo
                for (auto& enemigo : enemigos) {
                    if (enemigo.getPosX() == newX && enemigo.getPosY() == newY) {
                        std::cout << "Batalla con " << enemigo.getNombre() << "!\n";
                        if (!batalla(hero, enemigo)) {
                            std::cout << "Game Over!\n";
                            return 0;
                        } else {
                            board[newX][newY] = '-'; // Enemigo derrotado
                        }
                        break;
                    }
                }
            } else if (board[newX][newY] == 'B') {
                // Encontramos el jefe final
                std::cout << "Batalla con el jefe final " << boss.getNombre() << "!\n";
                if (!batalla(hero, boss)) {
                    std::cout << "Game Over!\n";
                    return 0;
                } else {
                    std::cout << "Has ganado el juego!\n";
                    return 0;
                }
            }
            // Mover al héroe
            board[hero.getPosX()][hero.getPosY()] = '-';
            hero.setPosX(newX);
            hero.setPosY(newY);
            board[newX][newY] = 'H';
            printBoard(board, hero);
        } else {
            std::cout << "Movimiento inválido, intente de nuevo.\n";
        }
    }

    return 0;
}

void createBoard(char board[HEIGHT][WIDTH], Heroe& hero, EnemigoFinal& boss, std::vector<Enemigo>& enemigos)
{
    // Empty board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = '-';
        }
    }

    // Place hero
    hero.setPosX(0);
    hero.setPosY(rand() % WIDTH);
    board[hero.getPosX()][hero.getPosY()] = 'H';

    // Place final boss
    boss.setPosX(HEIGHT - 1);
    boss.setPosY(rand() % WIDTH);
    board[boss.getPosX()][boss.getPosY()] = 'B';

    // Place enemies
    for (auto& enemigo : enemigos) {
        int x, y;
        do {
            x = rand() % HEIGHT;
            y = rand() % WIDTH;
        } while (board[x][y] != '-');
        enemigo.setPosX(x);
        enemigo.setPosY(y);
        board[x][y] = 'E';
    }
}

void printBoard(char board[HEIGHT][WIDTH], const Heroe& hero)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (board[i][j] == 'E')
                std::cout << '-';
            else
                std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

bool batalla(Personaje& p1, Personaje& p2)
{
    while (p1.getVida() > 0 && p2.getVida() > 0) {
        p2.recibirDano(p1.getAtaque());
        if (p2.getVida() <= 0) {
            std::cout << p1.getNombre() << " ha derrotado a " << p2.getNombre() << "!\n";
            return true;
        }

        p1.recibirDano(p2.getAtaque());
        if (p1.getVida() <= 0) {
            std::cout << p2.getNombre() << " ha derrotado a " << p1.getNombre() << "!\n";
            return false;
        }
    }
    return false;
}

bool isMoveValid(int x, int y)
{
    return x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH;
}
