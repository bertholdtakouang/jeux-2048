#include "jeux.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Constructeur
Game2048::Game2048() {
    // Initialisation du tableau avec des zéros
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            board[i][j] = 0;
        }
    }
    // Ajout de deux premiers chiffres aléatoires
    addRandomNumber();
    addRandomNumber();
}

// Affichage du tableau
void Game2048::printBoard() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << std::setw(5) << board[i][j];
        }
        std::cout << std::endl;
    }
}

// Ajout d'un chiffre aléatoire
void Game2048::addRandomNumber() {
    // Recherche des positions vides
    int emptyPositions[16][2];
    int emptyCount = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) {
                emptyPositions[emptyCount][0] = i;
                emptyPositions[emptyCount][1] = j;
                ++emptyCount;
            }
        }
    }

    if (emptyCount > 0) {
        // Ajout d'un nouveau chiffre (2 ou 4) à une position vide aléatoire
        srand(time(0));
        int randomIndex = rand() % emptyCount;
        int value = (rand() % 2 + 1) * 2; // 2 ou 4
        board[emptyPositions[randomIndex][0]][emptyPositions[randomIndex][1]] = value;
    }
}

// Logique de déplacement
bool Game2048::move(char direction) {
    bool moved = false;

    // Déplacement vers la gauche
    if (direction == 'a') {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = j + 1; k < 4; ++k) {
                    if (board[i][k] != 0) {
                        if (board[i][j] == 0) {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            moved = true;
                        } else if (board[i][j] == board[i][k]) {
                            board[i][j] *= 2;
                            board[i][k] = 0;
                            // Score += board[i][j]; // Ajoutez le score si nécessaire
                            moved = true;
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }

    // Déplacement vers la droite
    else if (direction == 'd') {
        for (int i = 0; i < 4; ++i) {
            for (int j = 3; j > 0; --j) {
                for (int k = j - 1; k >= 0; --k) {
                    if (board[i][k] != 0) {
                        if (board[i][j] == 0) {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            moved = true;
                        } else if (board[i][j] == board[i][k]) {
                            board[i][j] *= 2;
                            board[i][k] = 0;
                            // Score += board[i][j]; // Ajoutez le score si nécessaire
                            moved = true;
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }

    // Déplacement vers le haut
    else if (direction == 'w') {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 3; ++i) {
                for (int k = i + 1; k < 4; ++k) {
                    if (board[k][j] != 0) {
                        if (board[i][j] == 0) {
                            board[i][j] = board[k][j];
                            board[k][j] = 0;
                            moved = true;
                        } else if (board[i][j] == board[k][j]) {
                            board[i][j] *= 2;
                            board[k][j] = 0;
                            // Score += board[i][j]; // Ajoutez le score si nécessaire
                            moved = true;
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }

    // Déplacement vers le bas
    else if (direction == 's') {
        for (int j = 0; j < 4; ++j) {
            for (int i = 3; i > 0; --i) {
                for (int k = i - 1; k >= 0; --k) {
                    if (board[k][j] != 0) {
                        if (board[i][j] == 0) {
                            board[i][j] = board[k][j];
                            board[k][j] = 0;
                            moved = true;
                        } else if (board[i][j] == board[k][j]) {
                            board[i][j] *= 2;
                            board[k][j] = 0;
                            // Score += board[i][j]; // Ajoutez le score si nécessaire
                            moved = true;
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }

    return moved;
}

// Logique de fin de jeu
bool Game2048::isGameOver() {
    // Vérifiez si le tableau est rempli (aucune case vide)
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) {
                return false; // Le jeu n'est pas terminé
            }
        }
    }

    // Vérifiez si des mouvements supplémentaires sont possibles
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // Vérifiez les tuiles adjacentes pour voir si un mouvement est possible
            if ((j < 3 && board[i][j] == board[i][j + 1]) || (i < 3 && board[i][j] == board[i + 1][j])) {
                return false; // Le jeu n'est pas terminé
            }
        }
    }

    // Aucun mouvement supplémentaire possible, le jeu est terminé
    return true;
}
