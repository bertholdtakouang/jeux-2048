#include <iostream>
#include "jeux.h"

int main() {
    Game2048 game;

    char move;
    while (true) {
        // Affichage du tableau
        game.printBoard();

        // Lire le mouvement de l'utilisateur
        std::cout << "Entrez un mouvement (w/a/s/d) ou q pour quitter : ";
        std::cin >> move;

        if (move == 'q') {
            std::cout << "Vous avez quitté le jeu. Au revoir!" << std::endl;
            break;
        }

        // Effectuer le mouvement
        if (!game.move(move)) {
            std::cout << "Mouvement invalide. Réessayez." << std::endl;
        }

        // Ajouter un nouveau chiffre après chaque mouvement
        game.addRandomNumber();

        // Vérifier si le jeu est terminé
        if (game.isGameOver()) {
            std::cout << "Game Over! Merci d'avoir joué." << std::endl;
            break;
        }
    }

    return 0;
}
