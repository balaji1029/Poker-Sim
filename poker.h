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
    vector<card> pile;

    public:
    int size;
    // Constructors
    Pile();
    Pile(vector<card> d);

    // Functions to remove or add a card
    card chooseCard();
    void addCard(card p);

    // Operator to get a card of index i from the pile
    card & operator[] (int const i);

};


// Converts a card to string while printing
ostream & operator<<(ostream & ost, card c);

class Player {
    float confidence;
    Pile cards;
    Pile showPile;
    vector<Player*> others;

    public:
    string name;
    float bet;
    float recentBet;
    Player();
    Player(string name);
    
    void getBetAmount();
    void getPlayerCards(vector<card>);
    void getShowCards(vector<card>);
    void getPlayers(vector<Player*> players);
};

// Converts a player to string while printing
ostream & operator<<(ostream & ost, Player player);

class Engine {

    vector<card> showPile;
    vector<card> showedPile;

    // Pointer to all the players...
    vector<Player*> players;
    float betAmount;
    int playerCount;
    // vector<float> bets;
    int gameIndex;

    public:
    void showCard();
    Engine(int n, vector<Player*> players);
    void shuffleDeck();
    void showFirstTwoCards();
    void collectBets();
    void showNextCard();
};

#endif