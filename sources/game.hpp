#pragma once
#include <string>
#include "player.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;


class Game{
    
    Player player1;
    Player player2;
    string* turnsDB;
    bool reset;
    int cardCounter;
    int turnsPlayed;
    Card *deck;
    string lastTurn;

    public:
    Game(Player first, Player second);
    int getTurnsPlayed();
    void playTurn();
    void playAll();
    void printLog();
    void printStats();
    void printLastTurn();
    void printWinner();
    void prepareGame();
};