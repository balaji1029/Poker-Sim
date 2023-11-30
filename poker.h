#ifndef POKER_H
#define POKER_H

#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

class Player {
    float confidence;
    
    int getAmount();
};

class Deck {
    vector<pair<int, int>> deck;
    int size;

    Deck() {
        for(int i=0; i<4; i++) {
            for(int j=0; j<13; j++) {
                this -> deck.push_back(make_pair(i+1, j+1));
            }
        }
        size = 52;
    }

    Deck(vector<pair<int, int>> d) : deck(d), size(d.size()) {}

    pair<int, int> choose() {
        srand(2);
        int r = rand();

        r %= size;
        pair<int, int> p =this -> deck[r];
        this -> deck.erase(deck.begin() + r);
        this -> size--;
    }
};

#endif