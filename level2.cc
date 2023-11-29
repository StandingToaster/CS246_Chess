#include "level2.h"

using namespace std;

bool level2::checkForKill(Move input) {
   return input.hasEnemyPresence();
}

Move level2::generateMove() {
    Board* b = this->getPointer();
    vector<Move> validMoves = b->getLegalMoves(this->getColour());

    //continues running until a move that results in a kill or check isfound
    for (Move m : validMoves) {
        //implement logic here
        return m;
    }
    
}