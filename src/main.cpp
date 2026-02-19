#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include <string>

int main() 
{
    Player player{};
    Dealer dealer{};
    Deck deck{};
    Game game{player, dealer, deck};

    game.play();
}