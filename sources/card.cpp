#include "card.hpp"
using namespace ariel;

Card ::Card(int number, string type)
{
    this->number = number;
    this->type = type;
};

Card ::Card()
{
    this->number = 0;
    this->type = "";
};

int Card ::compareto(Card other)
{
    if (this->number < other.number)
    {
        return -1;
    }
    else if (this->number > other.number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

int Card ::getNumber()
{
    return this->number;
};

string Card ::getType()
{
    return this->type;
};

string Card ::cardInfo()
{
    string info = "";
    int num = this->number;
    switch (num)
    {
    case 1:
        info += "Ace of " + this->type;
        break;
    case 11:
        info += "Jack of " + this->type;
        break;
    case 12:
        info += "Queen of " + this->type;
        break;
    case 13:
        info += "King of " + this->type;
        break;
    default:
        info += to_string(this->number) + " of " + this->type;
        break;
    }
    return info;
};