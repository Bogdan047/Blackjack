#ifndef BLACKJACK_H
#define	BLACKJACK_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum PlayerCommands
{
    Start,
    Hit,
    Pass,
    Quit,
    Invalid_Input,
    Default_State
};

class PlayerEntity 
{
public:
    PlayerCommands getPlayerState();
    void setPlayerState(PlayerCommands input);
    int getCards();
    int drawCard();
    int setCards();

private:
    int cards{ 0 };
    PlayerCommands playerState{ Default_State };
};

class Player: PlayerEntity
{
    void takeInput();
    void actionCommandArgument();
};



/* 
			AI FUNCTIONALITY
*/

class Computer: PlayerEntity
{
public:
    




};







#endif
