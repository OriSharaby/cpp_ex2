#pragma once
#include <string>
#include <stack>
#include "card.hpp"
#include "stats.hpp"
using namespace std;
using namespace ariel;


class Player{

    string name;
    stack <Card> myStack;
    int takenCards;
    Stats* stats;
    


    public:
    Player(std :: string name);
    int cardesTaken();
    int stacksize();
    string getName();
    void statsToPrint();
    void addCard(Card card);
    void setTakenCards();
    void updateStats(int cardTaken, string resuls);
    Card takeFirstCard();
    
};
