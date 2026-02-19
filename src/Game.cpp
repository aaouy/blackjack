#include "Game.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include "Dealer.hpp"
#include "Constants.hpp"
#include "Card.hpp"
#include <iostream>
#include <string_view>
#include <thread>
#include <chrono>

Game::Game(Player& player, Dealer& dealer, Deck& deck)
    : m_player{player}, m_dealer{dealer}, m_deck{deck} {}


void Game::displayWelcomeMessage() const
{
    std::cout << "Welcome to blackjack! Click c to continue or e to exit.\n";
}

char Game::getPlayDecision() const
{
    char response{};
    do {
        std::cin >> response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (response != 'c' && response != 'e')
        {
            std::cout << "Invalid input! Please try again!\n";
        }

    } while (response != 'c' && response != 'e');

    return response;
}

void Game::displayWelcomePlayerMessage(std::string_view name) const
{
    std::cout << "Welcome " << name << "!\n\n";
}

void Game::displayPlayAgainMessage() const
{
    std::cout << "\nWould you like to play again (y/n)?\n";
}

void Game::displayGetPlayerMoveMessage() const
{
    std::cout << "Would you like to hit or stand? (enter h for hit and s for stand)\n";
}

std::string Game::getPlayerName() const
{
    std::cout << "Please enter your name: ";
    std::string name{};
    std::getline(std::cin, name);

    return name;
}

void Game::setPlayerName(std::string name)
{
    m_player.setName(name);
}

bool Game::playAgain() const
{
    char input{};
    do 
    {
        displayPlayAgainMessage();
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (input != 'y' && input != 'n')
        {
            std::cout << "Invalid input! Please try again!\n";
        }
    } while (input != 'y' && input != 'n');
    
    return input == 'y' ? true : false;
}

char Game::getPlayerMove() const
{
    char input{};
    do 
    {
        displayGetPlayerMoveMessage();
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (input != 'h' && input != 's')
        {
            std::cout << "Invalid input! Please try again!\n";
        }
    } while (input != 'h' && input != 's');

    return input;
}

void Game::calculateWinner()
{
    if (m_player.getHandValue() > constants::MAX_NUM_POINTS || (m_dealer.getHandValue() <= constants::MAX_NUM_POINTS && m_player.getHandValue() < m_dealer.getHandValue()))
    {
        std::cout << "You lose!\n";
        m_dealer.incrementNumOfGamesWon();
    }
    else if (m_dealer.getHandValue() > constants::MAX_NUM_POINTS || (m_player.getHandValue() <= constants::MAX_NUM_POINTS && m_player.getHandValue() > m_dealer.getHandValue()))
    {
        std::cout << "You win!\n";
        m_player.incrementNumOfGamesWon();
    }
    else
    {
        std::cout << "Draw!\n";
    }
}

void Game::displayScore() const
{
    std::cout << "\nThe score is:\nYou: " << m_player.getNumOfGamesWon() << "\tDealer: " << m_dealer.getNumOfGamesWon() << '\n';
}

void Game::play()
{
    displayWelcomeMessage();
    if (getPlayDecision() == 'e')
    {
        return;
    }

    setPlayerName(getPlayerName());
    displayWelcomePlayerMessage(m_player.getName());
    m_deck.shuffle();

    bool isPlaying{true};
    do
    {
        if (m_deck.getNumCards() < constants::RESHUFFLE_THRESHOLD)
        {
            std::cout << "Deck has reached minimum number of cards allowed! Placing discarded cards back into the deck...";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            m_deck = {};
            m_deck.shuffle();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        // Ensure hands are cleared and deck is shuffled at the start of every round.
        m_player.clearHand();
        m_dealer.clearHand();

        // Player draws two cards.
        for (int i = 0; i < 2; ++i)
        {
            Card card = m_deck.getTopCard();
            m_player.addCard(card);
            std::cout << "You drew a card!\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "\nYou drew two cards!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "\nDealer's turn!\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Dealer draws a card. 
        Card dealerCard{m_deck.getTopCard()};
        m_dealer.addCard(dealerCard);
        std::cout << "The dealer drew a card\n\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Display the player's hand.
        m_player.displayHand();
        m_player.displayHandValue();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "\n";

        // Player draws card until they stand or bust.
        while (m_player.getHandValue() < constants::MAX_NUM_POINTS && getPlayerMove() == 'h' && m_deck.getNumCards() > 0)
        {
            Card playerCard{m_deck.getTopCard()};
            m_player.addCard(playerCard);

            std::cout << "\nYou drew a " << playerCard << "!\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));

            m_player.displayHand();
            m_player.displayHandValue();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << '\n';
        }

        if (m_player.getHandValue() > constants::MAX_NUM_POINTS)
        {
            std::cout << "You busted!\n";
            calculateWinner();
        }
        else if (m_deck.getNumCards() == 0)
        {
            std::cout << "\nNo more cards left! This round ends in a draw.\n";
        }
        else
        {
            std::cout << "\nThe dealer's card was: " << dealerCard << '\n';
            while (m_dealer.getHandValue() < constants::MIN_DEALER_HAND_VALUE && m_deck.getNumCards() > 0)
            {
                Card dealerCard{m_deck.getTopCard()};
                m_dealer.addCard(dealerCard);
                std::cout << "\nThe dealer drew a " << dealerCard << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(2));

                if (m_dealer.getHandValue() == constants::MIN_DEALER_HAND_VALUE && m_dealer.getNumOfAcesWithValueEleven() > 0)
                {
                    m_dealer.changeNumOfAcesWithValueEleven(-1);
                    m_dealer.changeHandValue(-10);
                }

                m_dealer.displayHand();
                m_dealer.displayHandValue();
                std::cout << '\n';
            }
            calculateWinner();
        }

        displayScore();
        isPlaying = playAgain();
        if (isPlaying)
        {
            std::cout << "Preparing next round...\n\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

    } while (isPlaying);
}
