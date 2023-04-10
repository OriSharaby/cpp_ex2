#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace ariel{};

    class Card{
        int number;
        string type;
    
    public:
        Card(int number, string type);
        Card();
        int compareto(Card other);
        int getNumber();
        string getType();
        string cardInfo();
    };
