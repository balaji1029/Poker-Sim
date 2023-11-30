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

class Pile {
    vector<card> pile;
    int size;

    public:
    Pile() {
        for(int i=0; i<4; i++) {
            for(int j=0; j<13; j++) {
                this -> pile.push_back(make_pair(i+1, j+1));
            }
        }
        size = 52;
    }

    Pile(vector<card> d) : pile(d), size(d.size()) {}

    card chooseCard() {
        srand(time(NULL));
        int r = rand();

        r %= this -> size;
        card p = this -> pile[r];
        this -> pile.erase(this -> pile.begin() + r);
        this -> size--;
        return p;
    }

    void addCard(card p) {
        this -> pile.push_back(p);
        this -> size++;
    }
};

ostream & operator<<(ostream & ost, card c) {
    string s = "";
    switch (c.second) {
        case 1:
            s += "Ace of "; break;
        case 2:
            s += "Two of "; break;
        case 3:
            s += "Three of "; break;
        case 4:
            s += "Four of "; break;
        case 5:
            s += "Five of "; break;
        case 6:
            s += "Six of "; break;
        case 7:
            s += "Seven of "; break;
        case 8:
            s += "Eight of "; break;
        case 9:
            s += "Nine of "; break;
        case 10:
            s += "Ten of "; break;
        case 11:
            s += "King of "; break;
        case 12:
            s += "Queen of "; break;
        case 13:
            s += "Jack of "; break;
    }
    switch (c.first) {
        case 1:
            s += "Hearts"; break;
        case 2:
            s += "Diamonds"; break;
        case 3:
            s += "Spades"; break;
        case 4:
            s += "Cloves"; break;
    }
    ost << s;
    return ost;
}
#endif