#ifndef PILE_H
#define PILE_H

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
    int size;

    public:
    // Constructors
    Pile();
    Pile(vector<card> d);

    // Functions to remove or add a card
    card chooseCard();
    void addCard(card p);
};

// Converts a card to string while printing
ostream & operator<<(ostream & ost, card c);

#endif