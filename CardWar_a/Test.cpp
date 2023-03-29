//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#ifndef Test_cpp
#define Test_cpp

#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace std;
using namespace ariel;

Player p1("Alice");
Player p2("Bob");

Game game(p1,p2);

TEST_CASE("testing setup") {
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.getPlaying() == true);
    CHECK(p2.getPlaying() == true);

    Game newGame(p1,p2);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("testing turns") {
   for (int i=0;i<5;i++) {
    game.playTurn();
   }

    CHECK(p1.stacksize() <= 21);
    CHECK(p2.stacksize() <= 21);
    
    CHECK(p1.cardesTaken() >= 0);
    CHECK(p2.cardesTaken() >= 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}

TEST_CASE("ruling out exceptions") {
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());
            
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("testing end of game") {
    game.playAll();

    CHECK_THROWS(game.playTurn());

    CHECK(p1.getPlaying() == false);
    CHECK(p2.getPlaying() == false);

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);

    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}

#endif