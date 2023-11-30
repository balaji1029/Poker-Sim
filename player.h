#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <string>
#include <ctime>
#include "pile.h"
#define card pair<int, int>
using namespace std;

class Player {
    private:
    string name;
    float confidence;
    Pile cards;
    Pile showPile;
    public:
    Player();
    Player(string name);
    
    int getBetAmount();
    void getPlayerCards(vector<card>);
    void getShowCards(vector<card>);
};

#endif