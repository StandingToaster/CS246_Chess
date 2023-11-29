#include "level3.h"

using namespace std;

bool GenearteCaptureOrCheckMove(level3& comp, Move& move) {
    Board* b = comp.getPointer();
    vector<Move> validMoves = b->getLegalMoves(comp.getColour());

    //continues running until a move that results in a kill or check isfound
    for (Move m : validMoves) {
        if (m.hasEnemyPresence()) { // checks for kill
            move = m;
            return true;
        }
        
        Board temp = *b;
        if(temp.activateMove(m.getStart(), m.getDest())) {
            Colour enemyColour;
            if (comp.getColour() == Colour::Black) {
                enemyColour = Colour::White;
            } else {
                enemyColour = Colour::Black;
            }


            if (temp.checked(enemyColour)) {
                move = m;
                return true;
            }
        }
    }

    // if loop exited, no capture/check move was found and return false
    return false;
}

Move level3::generateMove() {
    
}