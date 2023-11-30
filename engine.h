#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "pile.h"
#define card pair<int, int>
using namespace std;

class Engine {
    vector<card> showPile;
    vector<Pile> playerCards;
    float betAmount;
    int playerCount; 
    vector<float> bets;
    int gameIndex;

    public:
    Engine(int n) : playerCount(n), betAmount(0) {
        cout << "Game Started for " << n << " players..." << '\n';

        for (int i=0; i<n; i++) {
            bets.push_back(0);
        }

        Pile deck;

        cout << "Deck Shuffled..." << '\n';

        for(int i=0; i<n; i++) {
            vector<card> v;
            for (int i=0; i<3; i++) {
                v.push_back(deck.chooseCard());
            }
            Pile p(v);
            playerCards.push_back(p);
        }

        cout << "Cards Distributed..." << '\n';
        cout << "Taking the Show Pile..." << '\n';

        for (int i=0; i<5; i++) {
            this -> showPile.push_back(deck.chooseCard());
        }

        cout << "Showing the first two cards..." << '\n';
        cout << "First Card: " << showPile[0] << '\n';
        gameIndex = 1;
        cout << "Second Card: " << showPile[1] << '\n';
        gameIndex++;
    }
};

#endif