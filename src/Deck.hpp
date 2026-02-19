#ifndef DECK_CPP
#define DECK_CPP

#include <vector>
#include "Card.hpp"
#include <random>

class Deck
{
public:
    Deck();
    void shuffle();
    Card getTopCard();
    bool isEmpty() const;
    int getNumCards() const;
    
    
private:
    std::vector<Card> m_cards{};
    std::mt19937 gen;
};

#endif