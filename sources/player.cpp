#include "player.hpp"
#include <string>
using namespace std;

 
    int cardesTaken();
    int stacksize();

Player :: Player(std :: string name){

}
int Player:: cardesTaken(){
    return 0;
};

int Player::stacksize(){
    return 0;
};

void Player ::addCard(Card card){
    

};

void Player ::addStats(int cardsTaken,string resulet){
    switch (resulet)
    {
    case "Win":
        (this->stats).wins++;
        break;
    case "Draw":
        (this->stats).draws++;
        break;
    case "Lose":
        (this->stats).loses++;
        break;
    default:
        break;
    }
};
