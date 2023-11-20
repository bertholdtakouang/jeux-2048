#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int BOARD_SIZE = 4;

class Game2048 {
public:
    Game2048() : score(0) {
        board.resize(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
        addRandomTile();
        addRandomTile();
    }

    void play() {
        while (true) {
            printBoard();
            if (checkGameOver()) {
                std::cout << "Game Over! Score : " << score << std::endl;
                break;
            }
            char move;
            std::cout << "Enter a move (W/A/S/D): ";
            std::cin >> move;
            if (makeMove(move)) {
                addRandomTile();
            }
        }
    }

private:
    std::vector<std::vector<int>> board;
    int score;

    void printBoard() {
        system("clear");  // Clear the console (Linux/Unix)
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                std::cout << board[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(char move) {
        // Implement the move logic (e.g., merging tiles and updating the board)
        // Return true if a move was successful (i.e., tiles moved or merged), otherwise return false.
        // Update the score.
        return false;
    }

    void addRandomTile() {
        // Add a random tile (2 or 4) to an empty cell on the board.
    }

    bool checkGameOver() {
        // Check if the game is over (no valid moves left).
        return false;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Game2048 game;
    game.play();

    return 0;
}