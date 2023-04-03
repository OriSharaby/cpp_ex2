#pragma once
#include <string>

using namespace std;

namespace ariel
{}
    class Card{
        int value;
        string type;
    
    public:
        Card(int value, string type);
        Card();
        int compareto(Card card);
    };
    
