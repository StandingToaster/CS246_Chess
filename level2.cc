#include "level2.h"

using namespace std;

vector<Move> level2::checkForKill() {
    Board* p = this->getPointer();
    Colour cur = this->getColour();
    vector<Move> temp = {};
    vector<Move> LegalMoves = p->getLegalMoves(cur);
    for (int i = 0; i < LegalMoves.size(); ++i) {
        if (LegalMoves[i].hasEnemyPresence()) {
            temp.emplace_back(LegalMoves[i]);
        }
        else {
            continue;
        }
    }
    return temp;
}

