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
};

// Converts a card to string while printing
ostream & operator<<(ostream & ost, card c);

class Player {
    private:
    string name;
    float confidence;
    Pile cards;
    Pile showPile;
    public:
    Player();
    Player(string name);
    
    int getBetAmount();
    void getPlayerCards(vector<card>);
    void getShowCards(vector<card>);
};

class Engine {
    vector<card> showPile;
    vector<card> showedPile;
    vector<Player> players;
    vector<Pile> playerCards;
    float betAmount;
    int playerCount;
    vector<float> bets;
    int gameIndex;

    public:
    Engine(int n);
    void showCard();
};

#endif