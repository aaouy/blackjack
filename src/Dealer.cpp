#include "Dealer.hpp"
#include <vector>
#include "Card.hpp"
#include <iostream>
#include "Participant.hpp"

Dealer::Dealer()
    : Participant(){}

void Dealer::displayHand() const
{
    std::cout << "The dealer's hand is:\n";
    Participant::displayHand();
}

void Dealer::displayHandValue() const
{
    std::cout << "The dealer's hand value is: " << getHandValue() << '\n';
}
