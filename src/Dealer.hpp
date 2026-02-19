#ifndef DEALER_HPP
#define DEALER_HPP

#include <vector>
#include "Card.hpp"
#include "Participant.hpp"

class Dealer : public Participant
{
public:
    Dealer();
    void displayHand() const;
    void displayHandValue() const;
};

#endif