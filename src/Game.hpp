#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include <string_view>

class Game
{
public:
    Game(Player& player, Dealer& dealer, Deck& deck);
    void displayWelcomeMessage() const;
    void displayWelcomePlayerMessage(std::string_view name) const;
    void displayPlayAgainMessage() const;
    void displayGetPlayerMoveMessage() const;
    char getPlayDecision() const;
    std::string getPlayerName() const;
    void setPlayerName(std::string name);
    bool playAgain() const;
    char getPlayerMove() const;
    void calculateWinner();
    void play();
    void displayScore() const;

private:
    Player m_player;
    Dealer m_dealer{};
    Deck m_deck{};
};

#endif