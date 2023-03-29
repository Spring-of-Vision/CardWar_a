#include "card.hpp"

namespace ariel
{
    char number;
    int suit; // 1- heart, 2- clubs, 3- diamond, 4- spades

    Card::Card()
    {
        number = 0;
        suit = 0;
    }

    Card::Card(char n, int s)
    {
        number = n;
        suit = s;
    }
}