#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Card.hpp"
#include "Participant.hpp"

class Player : public Participant
{
public:
    Player(const std::string& name);
    Player();
    const std::string& getName() const;
    void setName(const std::string& name);
    void displayHand() const;
    void displayHandValue() const;

private:
    std::string m_name{};
};

#endif