#include <algorithm>
#include <random>
#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>
#include <thread>
#include <chrono>


Deck::Deck() 
    : gen(std::random_device{}())
{
    // Initialising deck.
    for (Suit suit: {Suit::Heart, Suit::Diamond, Suit::Club, Suit::Spade})
    {
        for (Rank rank: {Rank::Ace, Rank::Two, Rank::Three, Rank::Four, 
            Rank::Five, Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, 
            Rank::Queen, Rank::King})
        {
            m_cards.push_back({suit, rank});
        }
    }
}

void Deck::shuffle() 
{
    std::cout << "The deck is being shuffled...\n";
    std::shuffle(m_cards.begin(), m_cards.end(), gen);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

Card Deck::getTopCard() 
{
    Card topCard = m_cards.back();
    m_cards.pop_back();
    std::cout << "Drawing card...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return topCard;
}

bool Deck::isEmpty() const
{
    return m_cards.empty();
}

int Deck::getNumCards() const
{
    return m_cards.size();
}




