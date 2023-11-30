#include "level2.h"

using namespace std;

level2::level2(Board* in, Colour cur): Computer{in, cur} {}

Move level2::generateMove() {
    Board* b = this->getPointer();
    this->readyTheBoard(b);
    vector<Move> validMoves = b->getLegalMoves(this->getColour());

    //continues running until a move that results in a kill or check isfound
    for (Move m : validMoves) {

        if (m.hasEnemyPresence()) { // checks for kill
            return m;
        }
        
        Board temp = *b;
        // SHOULD BE temp.getCell(x,y) !!!!!!!!!!!!!!!!!!!!!!!!
        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        if (temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx, dy))) {
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
    srand((unsigned) time(NULL));
    int count = rand() % validMoves.size();
    return validMoves[count];
}

