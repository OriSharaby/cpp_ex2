#include "game.hpp"
#include <string.h>
#include <random>

#include <algorithm>
using namespace std;


Game ::Game(Player &first, Player &second) : player1(first),player2(second){
    this->turnsPlayed = 0;
    this->cardCounter = 0;
    this->reset = true;
    this->turnsDB = new string[26];
    this->deck = new Card[52];
    for (int i = 0; i < 26; i++)
    {
        this->turnsDB[i] = "";
    }
    void prepareGame();

};
void Game ::playTurn()
{

    if (this->player1.getName() == this->player2.getName())
    {
        throw std::runtime_error ("Player can't play against himself!");
    }
    if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0 || this->turnsPlayed > 26)
    {
        throw std::runtime_error ("The players have no cards left!");
    }
    cout <<player1.stacksize()<<endl;
    if (reset == true)
    {
        this->lastTurn = "";
    }
    Card c1 = this->player1.takeFirstCard();
    Card c2 = this->player2.takeFirstCard();
    cardCounter += 2;
    int resulet = c1.compareto(c2);
    if (resulet == 1)
    {
        this->player1.updateStats(cardCounter, "Win");
        this->player2.updateStats(cardCounter, "Lose");

        lastTurn += this->player1.getName() + " played " + c1.cardInfo() + " " +
                    this->player2.getName() + " played " + c2.cardInfo() + ". " + this->player1.getName() + " wins. ";
        turnsPlayed++;
        this->reset = true;
    }
    else if (resulet == -1)
    {
        this->player2.updateStats(cardCounter, "Win");
        this->player1.updateStats(cardCounter, "Lose");
        lastTurn += this->player1.getName() + " played " + c1.cardInfo() + " " +
                    this->player2.getName() + " played " + c2.cardInfo() + ". " + this->player2.getName() + " wins. ";
        turnsPlayed++;
        this->reset = true;
    }
    else
    {
        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
        {
            this->player1.updateStats(cardCounter / 2, "Draw");
            this->player2.updateStats(cardCounter / 2, "Draw");
            return;
        }
        c1 = this->player1.takeFirstCard();
        c2 = this->player2.takeFirstCard();
        cardCounter += 2;

        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
        {
            this->player1.updateStats(cardCounter / 2, "Draw");
            this->player2.updateStats(cardCounter / 2, "Draw");
            return;
        }
        lastTurn += this->lastTurn + this->player1.getName() + " played " + c1.cardInfo() + " " +
                    this->player2.getName() + " played " + c2.cardInfo() + ". Draw. ";

        this->reset = false;
        this->playTurn();
    }
    this->turnsDB[turnsPlayed] = lastTurn;
};

int Game ::getTurnsPlayed()
{
    return this->turnsPlayed;
};
void Game ::playAll()
{
    while (this->player1.stacksize() != 0 || this->player2.stacksize() != 0)
    {
        this->playTurn();
    }
};
void Game ::printLog()
{
    for (int i = 0; i < 26; i++)
    {
        cout << this->turnsDB[i] << endl;
    }
};
void Game ::printStats()
{
    player1.statsToPrint();
    player2.statsToPrint();
};

void Game ::printLastTurn()
{
    cout << turnsDB[getTurnsPlayed()] << endl;
};

void Game ::printWiner()
{
    string winner;
    if (player1.cardesTaken() > player2.cardesTaken())
    {
        winner += "The winner is " + player1.getName();
    }
    else if (player1.cardesTaken() < player2.cardesTaken())
    {
        winner += "The winner is " + player2.getName();
    }
    else
    {
        winner += "Draw!, there is no winner";
    }
    cout << winner << endl;
};

void Game ::prepareGame()
{
    string suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
    for (int i = 0; i < 4; i++)
    {
        string suit = suits[i];
        for (int j = 0; j < 13; j++)
        {
            (this->deck)[(i * 13) + j] = Card(j + 1, suit);
        }
    }
    std::mt19937 rng(std::random_device{}());       // random seed generator by mt19937 algorithm
    std::shuffle(this->deck, this->deck + 52, rng); // shuffle deck by randomizing order (seed)
    int index = 0;
    while (index < 26)
    {
        player1.addCard(this->deck[index]);
        index++;
    }

    while (index < 52)
    {
        player2.addCard(this->deck[index]);
        index++;
    }
};
