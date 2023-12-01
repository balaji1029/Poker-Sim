#include "poker.h"
#include <iostream>

int main() {
    // Initialize players with their personality...
    Player player1("Player 1"), player2("Player 2"), player3("Player 3"), player4("Player 4"), player5("Player 5");
    vector<Player*> players(5);
    players[0] = &player1;
    players[1] = &player2;
    players[2] = &player3;
    players[3] = &player4;
    players[4] = &player5;

    Engine engine(5, players);
    engine.shuffleDeck();
    engine.showFirstTwoCards();
    engine.collectBets();
    engine.showNextCard();
    engine.collectBets();
    engine.showNextCard();
    engine.collectBets();
    engine.showNextCard();
}