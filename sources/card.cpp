#include "card.hpp"
using namespace std;
using namespace ariel;

    Card ::Card(int num, string type)
    {
        this->number = num;
        this->type = type;
    };

    Card ::Card()
    {
        this->number = 0;
        this->type = "";
    };

    int Card ::compareto(Card other)
    {
        if (this->getNumber() == 1)
        {
            if (other.getNumber() == 2)
            {
                return -1;
            }
            else if (other.getNumber() <= 13 && other.getNumber() >= 3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if ((this->getNumber() < other.getNumber()) && (this->getNumber() != 1))
            {
                return -1;
            }
            else if ((this->getNumber() > other.getNumber()) && (other.getNumber() != 1))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    };

    int Card::getNumber()
    {
        return this->number;
    };

    string Card::getType()
    {
        return this->type;
    };

    enum number
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    string Card::cardInfo()
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
        };
        return info;
    };
