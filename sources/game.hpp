#pragma once
#include <string>
#include "player.hpp"

class Game{
    
    Player player1;
    Player player2;
    public:
    Game(Player first, Player second);
    void playTurn();
    void playAll();
    void printLog();
    void printStats();
    string printLastTurn();
    string printWiner();
};