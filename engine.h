#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "pile.h"
#include "player.h"
#define card pair<int, int>
using namespace std;

class Engine {
    vector<card> showPile;
    vector<Pile> playerCards;
    vector<Player>
    float betAmount;
    int playerCount; 
    vector<float> bets;
    int gameIndex;

    public:
    Engine(int n);
};

#endif