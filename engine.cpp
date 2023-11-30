#include "poker.h"

Engine::Engine(int n) : playerCount(n), betAmount(0){
    gameIndex = 0;
    cout << "Game Started for " << n << " players..." << '\n';

    for (int i=0; i<n; i++) {
        this -> players.push_back(Player());
        this -> bets.push_back(0);
    }

    Pile deck;

    cout << "Deck Shuffled..." << '\n';

    for(int i=0; i<n; i++) {
        vector<card> v;
        for (int i=0; i<3; i++) {
            v.push_back(deck.chooseCard());
        }
        players[i].getPlayerCards(v);
    }

    cout << "Cards Distributed..." << '\n';
    cout << "Taking the Show Pile..." << '\n';

    for (int i=0; i<5; i++) {
        this -> showPile.push_back(deck.chooseCard());
    }

    cout << "Deck size is " << deck.size << '\n';

    cout << "Showing the first two cards..." << '\n';
    this -> showCard();
    cout << "First Card: " << showedPile[this -> gameIndex - 1] << '\n';
    this -> showCard();
    cout << "Second Card: " << showedPile[this -> gameIndex - 1] << '\n';
}

void Engine::showCard() {
    this -> showedPile.push_back(this -> showPile[0]);
    this -> showPile.erase(this -> showPile.begin());
    this -> gameIndex++;
    for (Player player : this -> players) {
        player.getShowCards(this -> showedPile);
    }
}