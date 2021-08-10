// Blackjack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"

int main()
{
    Player: PlayerEntity player1;

    while (player1.getCards() < 21)
    {
        player1.takeInput();
        if (player1.getPlayerState() == Pass) { break; }
    }

    if (player1.getCards() == 21) { std::cout << "You Win!\n"; }
    else { std::cout << "You Lost...\n"; }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

