#pragma once
#include <string>

using namespace std;

namespace ariel
{}
    class Card
    {
    public:
        Card(int value, string type);
        Card();
        int compareto(Card card);
    };
    
