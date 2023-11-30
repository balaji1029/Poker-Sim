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
    vector<card> showedPile;
    vector<Player> players;
    vector<Pile> playerCards;
    float betAmount;
    int playerCount;
    vector<float> bets;
    int gameIndex;

    public:
    Engine(int n);
    void showCard();
};

#endif