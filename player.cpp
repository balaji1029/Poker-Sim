#include "player.h"

Player::Player() {}

Player::Player(string name) : name(name) {}

void Player::getPlayerCards(vector<card> cards) {
    this -> cards = Pile(cards);
}

void Player::getShowCards(vector<card> cards) {
    this -> showPile = Pile(cards);
}