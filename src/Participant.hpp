#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <vector>
#include "Card.hpp"

class Participant
{
    public:
        Participant();
        const std::vector<Card>& getHand() const;
        void displayHand() const;
        int getNumOfGamesWon() const;
        void incrementNumOfGamesWon();
        int getHandValue() const;
        int getNumOfAcesWithValueEleven() const;
        void changeNumOfAcesWithValueEleven(int val);
        void changeHandValue(int val);
        void addCard(Card& card);
        void clearHand();

    private:
        int m_numOfGamesWon{0};
        std::vector<Card> m_hand;
        int m_handValue{0};
        int m_numOfAcesWithValueEleven{0};
};

#endif