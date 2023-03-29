#include <iostream>
#include "player.hpp"
#include "card.hpp"
using namespace std;

namespace ariel
{
    string name;
    bool isPlaying;
    Card stack[0];
    int size;
    int won;

    Player::Player(string str)
    {
        name = str;
        size = 0;
        won = 0;
        isPlaying = false;
    }

    Player::Player(Player &p)
    {
        
    }

    int Player::stacksize()
    {
        return size;
    }

    int Player::cardesTaken()
    {
        return won;
    }

    bool Player::getPlaying()
    {
        return isPlaying;
    }
}