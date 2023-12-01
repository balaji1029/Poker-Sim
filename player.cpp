#include "poker.h"

Player::Player() : name("Default Player"), bet(0), recentBet(0) {}

Player::Player(string name) : name(name), bet(0), recentBet(0) {}

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
    float random = (float) rand() / RAND_MAX;
    random *= 100;
    this -> recentBet = random;
    this -> bet += random;
}

ostream & operator<<(ostream & ost, Player player) {
    ost << player.name;
    return ost;
}
