#include "player.hpp"
#include <string>
using namespace std;
using namespace ariel;


Player :: Player(std :: string name){
    this->name = name;
    this->takenCards = 0;
    this->cardsLeft = 0;
    this->stats = new Stats();
    this->myStack =stack<Card>();

}
int Player:: cardesTaken(){
    return this->takenCards;
};

int Player::stacksize(){
    return this->cardsLeft;
};

string Player :: getName(){
    return this->name;
}

void Player ::addCard(Card card){
    (this->myStack).push(card);
};

void Player :: setcardsLeft(int amount){
    this->cardsLeft -= amount;
};
void Player ::updateStats(int cardsCounter,string resulet){
    if( resulet == "Win"){
        this->stats->wins++;
    }
    else if(resulet == "Draw"){
        this->stats->draws++;
    }
    else{
        this->stats->loses++;
    }
};
void Player :: statsToPrint(){

    cout << this->name << " has " << this->stats->wins << " wins, " <<
    this->stats->loses << " loses and " << this->stats->draws << " draws." << endl;

    // total cards won
    cout << this->name << " has won " << this->cardesTaken() << " cards." << endl;

    // Win and draw percentages
    cout << this->name << " has " << this->stats->wins * 100 / 26 << "% win percentage and " <<
    this->stats->draws * 100 / 26 << "% draw percentage." << endl;
};

Card Player ::takeFirstCard(){
    if(this->stacksize()==0){
        throw std::runtime_error ("The pack of cards is over!");
    }
    Card topCard = this->myStack.top();
    this->myStack.pop();
    this->setcardsLeft(1);
    return topCard;

};
