#pragma once

#ifndef Player_hpp
#define Player_hpp

#include "card.hpp"
#include <iostream>

namespace ariel
{
    class Player
    {
        std::string name;
        bool isPlaying;
        Card stack[0];
        int size;
        int won;

        public:
            Player(std::string str);
            Player(Player &p);

            int stacksize();
            int cardesTaken();
            bool getPlaying();
    };
}

#endif