#include "level2.h"

using namespace std;



Move level2::generateMove() {
    Board* b = this->getPointer();
    vector<Move> validMoves = b->getLegalMoves(this->getColour());

    //continues running until a move that results in a kill or check isfound
    for (Move m : validMoves) {
        if (m.hasEnemyPresence()) { // checks for kill
            return m;
        }
        
        Board temp = *b;
        if(temp.activateMove(m.getStart(), m.getDest())) {
            Colour enemyColour;
            if (this->getColour() == Colour::Black) {
                enemyColour = Colour::White;
            } else {
                enemyColour = Colour::Black;
            }


            if (temp.checked(enemyColour)) {
                return m;
            }
        }
    }
    //Now if no enemyPresence is detected or a check is possible, it will pick a RANDOM valid move.
      int count = rand() % validMoves.size();
    return validMoves[count];
}

