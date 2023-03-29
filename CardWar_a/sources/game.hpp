#pragma once

#ifndef Game_hpp
#define Game_hpp
#include "player.hpp"

namespace ariel
{
    class Game
    {
        Player one;
        Player two;

        public:

            Game(Player &p1, Player &p2);
            
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
    };
}

#endif