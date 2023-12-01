#ifndef POKER_H
#define POKER_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#define card pair<int, int>
using namespace std;

// Represents a pile of cards
class Pile {

    vector<card> pile;                                    // Contains the cards in the pile

    public:
    int size;                                             // Self explanatory 😏 (No. of cards in the pile)

    // Constructors
    Pile();
    Pile(vector<card> d);

    // Functions to remove or add a card
    card chooseCard();                                    // Chooses a random card from the pile
    void addCard(card p);                                 // Adds a given card to the pile

    card & operator[] (int const i);                      // Operator to get a card of index i from the pile

};

ostream & operator<<(ostream & ost, card c);              // Converts a card to string while printing

class Player {

    float confidence;
    Pile cards;                                           // Pile of cards the player gets
    Pile showPile;                                        // Cards in the show pile already shown
    vector<Player*> others;                               // Pointers to the other players (excluding the player)

    public:
    string name;                                          // Player's name            
    float bet;                                            // Player's bet amount till now
    float recentBet;                                      // Player's recent bet

    // Constructors
    Player();                                             // Constructor with default name
    Player(string name);                                  // Constructor with a name
    
    void getBetAmount();                                  // Gets the bet amount
    void getPlayerCards(vector<card>);                    // Updates the player's cards at the beginning of the game
    void getShowCards(vector<card>);                      // Updates the show cards whenever a card is shown
    void getPlayers(vector<Player*> players);             // Gets and stores the pointers to other players
};

// Converts a player to string while printing
ostream & operator<<(ostream & ost, Player player);

class Engine {

    vector<card> showPile;                                // Vector of cards in the show pile that are not shown
    vector<card> showedPile;                              // Vector of cards that are already shown
    vector<Player*> players;                              // Pointer to all the players
    float betAmount;                                      // Total bet amount by all the players
    int playerCount;                                      // Total number of players
    int gameIndex;                                        // Denotes the number of cards already shown from the show pile

    public:
    void showCard();                                      // Shows a card from the show pile
    Engine(int n, vector<Player*> players);               // Starts the engine 🚂🚂
    void shuffleDeck();                                   // Shuffles the deck 🃏
    void showFirstTwoCards();                             // Shows the first two cards
    void collectBets();                                   // Collects the bet from every player
    void showNextCard();                                  // Shows the next card
};

#endif