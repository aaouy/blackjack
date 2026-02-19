#include "Participant.hpp"
#include "Card.hpp"
#include <iostream>
#include <typeinfo>
#include "Constants.hpp"
#include <chrono>
#include <thread>

Participant::Participant(){}

const std::vector<Card>& Participant::getHand() const
{
    return m_hand;
}

int Participant::getNumOfGamesWon() const
{
    return m_numOfGamesWon;
}

void Participant::incrementNumOfGamesWon() 
{
    m_numOfGamesWon++;
}

int Participant::getHandValue() const
{
    return m_handValue;
}

int Participant::getNumOfAcesWithValueEleven() const
{
    return m_numOfAcesWithValueEleven;
}

void Participant::changeNumOfAcesWithValueEleven(int val)
{
    m_numOfAcesWithValueEleven += val;
}

void Participant::addCard(Card& card)
{
    m_hand.push_back(card);
    changeHandValue(getCardValue(card));

    if (card.rank == Rank::Ace)
    {
        changeNumOfAcesWithValueEleven(1);
    }

    if (m_handValue > constants::MAX_NUM_POINTS && m_numOfAcesWithValueEleven > 0)
    {
        changeHandValue(-10);
        changeNumOfAcesWithValueEleven(-1);        
    }

}

void Participant::changeHandValue(int val)
{
    m_handValue += val;
}

void Participant::clearHand()
{
    m_hand.clear();
    m_handValue = 0;
    m_numOfAcesWithValueEleven = 0;
}

void Participant::displayHand() const
{
    for (Card card: getHand())
    {
        std::cout << card << ", ";
    }
    std::cout << '\n';
}