#include "jeux.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    games2048 game;
    game.plays();
    return 0;
}