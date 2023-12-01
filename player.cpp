#include "poker.h"

Player::Player() : bet(0), name("Default Player") {
}

Player::Player(string name) : name(name), bet(0) {}

void Player::getPlayerCards(vector<card> cards) {
    this -> cards = Pile(cards);
}

void Player::getShowCards(vector<card> cards) {
    this -> showPile = Pile(cards);
}

void Player::getPlayers(vector<Player*> players) {
    for (Player* player : players) {
        if (player != this) {
            this -> others.push_back(player);
        }
    }
    // cout << "No. of other players = " << this -> others.size() << '\n';
}

// Here goes our logic...
void Player::getBetAmount() {
    srand(time(NULL));
    // cwait(1);
    float beT = (float) rand() / RAND_MAX;
    beT *= 100;
    this -> recentBet = beT;
    this -> bet += beT;
}

ostream & operator<<(ostream & ost, Player player) {
    ost << player.name;
    return ost;
}
