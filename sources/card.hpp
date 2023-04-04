#pragma once
#include <string>

using namespace std;

namespace ariel
{}
    class Card{
        int number;
        string type;
    
    public:
        Card(int number, string type);
        Card();
        int compareto(Card card);
        int getNumber();
        string getType();
        string cardInfo();
    };
    
