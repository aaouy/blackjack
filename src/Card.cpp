#include "Card.hpp"
#include "Constants.hpp"
#include <iostream>

int getCardValue(Card card)
{
    switch (card.rank)
    {
    case Rank::Two:
        return 2;
    case Rank::Three:
        return 3;
    case Rank::Four:
        return 4;
    case Rank::Five:
        return 5;
    case Rank::Six:
        return 6;
    case Rank::Seven:
        return 7;
    case Rank::Eight:
        return 8;
    case Rank::Nine:
        return 9;
    case Rank::Ten:
    case Rank::Jack:
    case Rank::Queen:
    case Rank::King:
        return 10;
    case Rank::Ace:
        return 11;
    default:
        return 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Suit& suit)
{
    switch (suit)
    {
    case Suit::Spade:
        os << "Spades";
        break;
    case Suit::Club:
        os << "Clubs";
        break;
    case Suit::Diamond:
        os << "Diamonds";
        break;
    case Suit::Heart:
        os << "Hearts";
        break;
    default:
        os << "Unknown";
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Rank& rank)
{
    switch (rank)
    {
    case Rank::Ace:
        os << "Ace";
        break;
    case Rank::Two:
        os << "Two";
        break;
    case Rank::Three:
        os << "Three";
        break;
    case Rank::Four:
        os << "Four";
        break;
    case Rank::Five:
        os << "Five";
        break;
    case Rank::Six:
        os << "Six";
        break;
    case Rank::Seven:
        os << "Seven";
        break;
    case Rank::Eight:
        os << "Eight";
        break;
    case Rank::Nine:
        os << "Nine";
        break;
    case Rank::Ten:
        os << "Ten";
        break;
    case Rank::Jack:
        os << "Jack";
        break;
    case Rank::Queen:
        os << "Queen";
        break;
    case Rank::King:
        os << "King";
        break;
    default:
        os << "Unknown";
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << card.rank << " of " << card.suit;
    return os;
}