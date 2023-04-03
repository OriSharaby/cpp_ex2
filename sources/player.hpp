#pragma once
#include <string>
#include "card.hpp"

class Player{

    string name;
    Card* card;
    int score;
    int stackSize;
    //Array for stats;

    public:
    Player(std :: string name);
    int cardesTaken();
    int stacksize();
    
};
