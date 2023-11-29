#include "level2.h"

using namespace std;

vector<Move> level2::checkForKill() {
    Board* p = this->getPointer();
    Colour cur = this->getColour();
    //Vector that will return potential moves that result in kills.
    vector<Move> temp = {};
    vector<Move> LegalMoves = p->getLegalMoves(cur);
    //Loop through all possible legal moves, determine if any result in kills, if so, add to new vector "temp".
    for (long unsigned int i = 0; i < LegalMoves.size(); ++i) {
        if (LegalMoves[i].hasEnemyPresence()) {
            temp.emplace_back(LegalMoves[i]);
        }
        else {
            continue;
        }
    }
    return temp;
}

