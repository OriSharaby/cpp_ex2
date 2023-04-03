#pragma once
#include <string>
#include "player.hpp"

class Game{
    
    public:
    Game(Player first, Player second);
    void playTurn();
    void playAll();
    void printLog();
    void printStats();
    string printLastTurn();
    string printWiner();
};