#ifndef CARD_HPP
#define CARD_HPP

#include <array>

// Suits of cards.
enum class Suit
{
    Heart,
    Diamond,
    Club,
    Spade
};

// Ranks of cards.
enum class Rank
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    Suit suit;
    Rank rank;
};

int getCardValue(Card card);
// Functionality to print suit, rank and card to the console.
std::ostream& operator<<(std::ostream& os, const Suit& suit);
std::ostream& operator<<(std::ostream& os, const Rank& rank);
std::ostream& operator<<(std::ostream& os, const Card& card);

#endif


