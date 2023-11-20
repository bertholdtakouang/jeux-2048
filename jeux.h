#ifndef GAME2048_H
#define GAME2048_H

class Game2048 {
private:
    int board[4][4];

public:
    Game2048();
    void printBoard();
    void addRandomNumber();
    bool move(char direction);
    bool isGameOver();
};

#endif // GAME2048_H
