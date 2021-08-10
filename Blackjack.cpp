#include "Header.h"

Player::Player() { Player::takeInput(); }

PlayerCommands PlayerEntity::getPlayerState()
{
    return playerState;
}

void PlayerEntity::setPlayerState(PlayerCommands input)
{
    playerState = input;
}

int PlayerEntity::getCards() { return cards; }

int PlayerEntity::setCards()
{
    cards = drawCard();
    return cards;
}

int PlayerEntity::drawCard()
{
    srand((unsigned)time(NULL));

    int randomCard{ 2 + (rand() % 11) };

    if (randomCard == 11 && getCards() >= 11)
    {
        return 1;
    }

    return cards += randomCard;
}

void Player::takeInput()
{
    if (getCards() == 0) { std::cout << "Please enter an input: "; }
    else { std::cout << getCards() << " !hit or !pass?"; }
    char input;
    std::cin >> input;
    switch (input)
    {
    case 'S':
        setPlayerState(Start);
        break;
    case 'H':
        setPlayerState(Hit);
        break;
    case 'P':
        setPlayerState(Pass);
        break;
    case 'Q':
        setPlayerState(Quit);
        break;
    default:
        setPlayerState(Invalid_Input);
        break;
    }
    Player::actionCommandArgument();
}


void Player::actionCommandArgument()
{
    switch (getPlayerState())
    {
    case Start:
        std::cout << "Starting game...";
        Player::setCards();
        break;
    case Hit:
        std::cout << "Hit!";
        Player::drawCard();
        break;
    case Pass:
        std::cout << "Passing...";
        break;
    case Quit:
        exit(0);
    case Invalid_Input:
        std::cout << "Invalid input, please try again...\n";
        Player::takeInput();
        break;
    }
}
