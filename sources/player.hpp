#include <string>
#include "card.hpp"

class Player{
    private:
    std :: string name;
    public:
    Player(std :: string name);
    int cardesTaken();
    int stacksize();
};
