#include "engine.h"

Engine::Engine() : playerCount(n), betAmount(0){
    gameIndex = 0;
        cout << "Game Started for " << n << " players..." << '\n';

        for (int i=0; i<n; i++) {
            this -> bets.push_back(0);
        }

        Pile deck;

        cout << "Deck Shuffled..." << '\n';

        for(int i=0; i<n; i++) {
            vector<card> v;
            for (int i=0; i<3; i++) {
                v.push_back(deck.chooseCard());
            }
            Pile p(v);
            this -> playerCards.push_back(p);
        }

        cout << "Cards Distributed..." << '\n';
        cout << "Taking the Show Pile..." << '\n';

        for (int i=0; i<5; i++) {
            this -> showPile.push_back(deck.chooseCard());
        }

        cout << "Showing the first two cards..." << '\n';
        cout << "First Card: " << showPile[this -> gameIndex] << '\n';
        this -> gameIndex = 1;
        cout << "Second Card: " << showPile[this -> gameIndex] << '\n';
        this -> gameIndex++;
}