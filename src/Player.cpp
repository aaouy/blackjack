#include "Player.hpp"
#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

Player::Player()
    : Participant(){}

Player::Player(const std::string& name)
    : Participant(), m_name{name}{}

const std::string& Player::getName() const
{
    return m_name;
}

void Player::setName(const std::string& name)
{
    m_name = name;
}

void Player::displayHand() const
{
    std::cout << "Your hand is:\n";
    Participant::displayHand();
}

void Player::displayHandValue() const
{
    std::cout << "Your hand value is: " << getHandValue() << '\n';

}