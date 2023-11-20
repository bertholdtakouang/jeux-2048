#include <iostream>
#include <vector>
const int BOARD_SIZE = 4;
class games2048{
public:
    games2048();
    void plays();

private:
    std::vector<std::vector<int>> board;
    int score;
    void printBoard();
    bool makeMove(char move);
    void addRandomTile();
    bool checkGameOver();
};