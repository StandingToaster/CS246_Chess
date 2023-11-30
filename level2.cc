#include "level2.h"

using namespace std;

level2::level2(Board* in, Colour cur): Computer{in, cur} {}

Move level2::generateMove() {
    Board* b = this->getPointer();
    this->readyTheBoard(b);
    vector<Move> validMoves = b->getLegalMoves(this->getColour());
    Colour myColour = this->getColour();
//Determine what the colour of the enemy king is.
    Colour enemyColour;
        if (myColour == Colour::White) {
            enemyColour = Colour::Black;
        }
        else {
            enemyColour = Colour::White;
        }

    for (Move m : validMoves) {
        
        Board temp = *b;
        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

    //Does this move result in a check?
        if (b->checked(enemyColour)) {
            
            //If so, does it result in a kill?
            for (Move m : validMoves) {

                int sx = m.getStart().getX();
                int sy = m.getStart().getY();
                int dx = m.getDest().getX();
                int dy = m.getDest().getY();

                if (b->attackPossible(b->getCell(sx, sy), b->getCell(dx,dy))) {
                    return m;
                }
            }


        }

        //Does it result in only a check and no kill?
        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx,dy));
        if (temp.checked(enemyColour)) {
            return m;
        }

    }
     //Does it result in a kill in general?
    for (Move m : validMoves) {

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        if (b->attackPossible(b->getCell(sx, sy), b->getCell(dx,dy))) {
            return m;
        }
    }
    

    //Now if no potential attack is detected or a check is possible, it will pick a RANDOM valid move.
    srand((unsigned) time(NULL));
    int count = rand() % validMoves.size();
    return validMoves[count];
}

