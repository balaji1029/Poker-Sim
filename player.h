#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#define card pair<int, int>
using namespace std;

class Player {
    float confidence;
    Pile cards;
    Pile showPile;
    
    int getAmount();
    void getCards();
};

#endif