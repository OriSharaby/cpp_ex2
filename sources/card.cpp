#include "card.hpp"
using namespace ariel;

    Card :: Card(int value, string type){
        this->value =value;
        this->type = type;
    };

    Card :: Card(){
        this->value = 0;
        this->type = "";
    };

    int Card :: compareto(Card other){
        if(this->value<other.value){
            return -1;
        }
        else if(this->value>other.value){
            return 1;
        }
        else{
            return 0;
        }
    };