#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Test Player"){
    CHECK_THROWS(Player(NULL));
    Player Ori("Ori");
    Player Meir("Meir");
    CHECK(Ori.stacksize() == 26);
    CHECK(Meir.stacksize() == 26);
    CHECK(Ori.cardesTaken() == 0);
    CHECK(Meir.cardesTaken() == 0);
   
    Game test(Ori,Meir);
    test.playAll();
    CHECK(Ori.stacksize() == Meir.stacksize());
    CHECK(Ori.cardesTaken()!= Meir.cardesTaken());

    CHECK(Ori.stacksize()<26 && Meir.stacksize()<26);
    CHECK(Ori.cardesTaken()> 1 || Meir.cardesTaken()>1);
}

TEST_CASE("Teat Card"){
    Card first(5,"Diamond");
    Card second(12,"Diamond");
    Card third(3,"Heart");
    Card fourth(10,"Pikes");
    Card last(10,"Heart");

    CHECK(first.compareto(fourth) == -1);
    CHECK(first.compareto(third) == 1);
    CHECK(second.compareto(third) == 1);
    CHECK(last.compareto(fourth) == 0);
}

TEST_CASE("Test Game"){
    Player Ori("Ori");
    Player Meir("Meir");
    Player p1("player1");
    Player p2("player2");
    Game once(Ori,Meir);
    CHECK_THROWS(Game(Ori,Meir));
    CHECK_NOTHROW(once.playAll());
    CHECK_THROWS(once.printLog());
    CHECK_THROWS(once.printLastTurn());
    
    CHECK_THROWS(Game(Ori,Ori));
    CHECK((Ori.cardesTaken()+Meir.cardesTaken())==52);
    CHECK((Ori.stacksize()==0)&&(Meir.stacksize()==0));

    CHECK_THROWS(once.playAll());   
    CHECK_THROWS(once.playTurn());  

    
}