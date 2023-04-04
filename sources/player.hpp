#pragma once
#include <string>
#include "card.hpp"
#include "stats.hpp"


class Player{

    string name;
    Card ownedCards[52];
    int takenCards;
    int stackSize;
    Stats stats;
    


    public:
    Player(std :: string name);
    int cardsTaken();
    int stacksize();
    string getName();
    string statsToPrint();
    void addCard(Card card);
    void updateStats(int cardTaken, string resuls);
    Card takeFirstCard();

    
};
