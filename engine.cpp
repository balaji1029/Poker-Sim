#include "poker.h"

Engine::Engine(int n, vector<Player*> players) : playerCount(n), betAmount(0), players(players) {
    
    this -> gameIndex = 0;
    this -> betAmount = 0;
    cout << "Game Started for " << n << " players..." << '\n';

    for (Player* player : players) {
        player -> getPlayers(players);
    }

    // for (int i=0; i<n; i++) {
    //     this -> players.push_back(Player());
    //     this -> bets.push_back(0);
    // }
    // cout << "Deck size is " << deck.size << '\n';
}

void Engine::shuffleDeck() {
    Pile deck;

    cout << "Deck Shuffled..." << '\n';

    for(int i=0; i < this -> playerCount; i++) {
        vector<card> v;
        for (int i=0; i<3; i++) {
            v.push_back(deck.chooseCard());
        }
        players[i] -> getPlayerCards(v);
    }

    cout << "Cards Distributed..." << '\n';
    cout << "Taking the Show Pile..." << '\n';

    for (int i=0; i < playerCount; i++) {
        this -> showPile.push_back(deck.chooseCard());
    }
}

void Engine::showFirstTwoCards() {
    cout << "Showing the first two cards..." << '\n';
    this -> showCard();
    cout << "First Card: " << showedPile[this -> gameIndex - 1] << '\n';
    this -> showCard();
    cout << "Second Card: " << showedPile[this -> gameIndex - 1] << '\n';
}

void Engine::collectBets() {
    cout << "Collecting Bets..." << '\n';
    for (Player* player : this -> players) {
        player -> getBetAmount();
        this -> betAmount += player -> bet;
        cout << "Bet of " << *player << " is " << player -> bet << '\n';
    }
}

void Engine::showNextCard() {
    cout << "Showing the next card..." << '\n';
    this -> showCard();
    cout << "Next Card: " << showedPile[this -> gameIndex - 1] << '\n';
}

void Engine::showCard() {
    this -> showedPile.push_back(this -> showPile[0]);
    this -> showPile.erase(this -> showPile.begin());
    this -> gameIndex++;
    for (Player* player : this -> players) {
        player -> getShowCards(this -> showedPile);
    }
}