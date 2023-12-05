#include "level3.h"
#include "cell.h"

using namespace std;

level3::level3(Board* in, Colour cur): Computer{in, cur} {}

// returns a move similar to level2s logic but also ensures that a check/capture is not returned
// if it results in the piece used being put under threat
Move NonRiskyLevel2(level3& comp) {
    Board* b = comp.getPointer();
    comp.readyTheBoard(b);
    vector<Move> validMoves = b->getLegalMoves(comp.getColour());
    Colour myColour = comp.getColour();

    //Determine what the colour of the enemy king is.
    Colour enemyColour;
    if (myColour == Colour::White) {
        enemyColour = Colour::Black;
    }
    else {
        enemyColour = Colour::White;
    }

    //first, try returning a capturing move first
    for (Move m : validMoves) {

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        if (b->attackPossible(b->getCell(sx, sy), b->getCell(dx,dy))) {
            Board temp = *b;
            temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx,dy));

            //ensure that the capture doesnt result in putting piece at risk
            if (temp.pieceIsAtThreat(dx, dy)) {
                return m;
            }
        }
    }


    //then, try finding a checking move
    for (Move m : validMoves) {
        Board temp = *b;

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx,dy));
        if (temp.checked(enemyColour)) {
            
            //ensure that the check doesnt result in putting piece at risk
            if (temp.pieceIsAtThreat(dx, dy)) {
                return m;
            }
        }
    }


    //Now if no potential attack is detected or a check is possible, it will pick a RANDOM valid move.
    srand((unsigned) time(NULL));
    int count = rand() % validMoves.size();
    return validMoves[count];

}


// returns the valid moves for a piece at a specific cell on the board
vector<Move> PieceMoves(Cell& c, Board& b) {
    Colour col = c.getChessPiece()->getColour();

    vector<Move> pieceMoves;

    for (Move m : b.getLegalMoves(col)) {
        if (m.getStart().getX() == c.getX() && m.getStart().getY() == c.getY()) {
            pieceMoves.emplace_back(m);
        }
    }

    return pieceMoves;
}



// determines if there is a way to protect cell at x,y and mutates m if so
bool protectPiece(int x, int y, Board& b, Move& m) {
    Colour col = b.getCell(x, y).getChessPiece()->getColour();

    // check for all moves that may result in protecting the original cell
    // without putting itself at risk
    for (Move validMove : b.getLegalMoves(col)) {
        Board temp = b;

        int sx = validMove.getStart().getX();
        int sy = validMove.getStart().getY();
        int dx = validMove.getDest().getX();
        int dy = validMove.getDest().getY();
        // simulate the move on a copy of the board
        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx, dy));

        // checks the threat status of both the original cell at threat and the destination
        if (!temp.pieceIsAtThreat(x, y) && !temp.pieceIsAtThreat(validMove.getDest().getX(), validMove.getDest().getY())) {
            m = validMove;
            return true;
        }
    }

    return false;
}



Move level3::generateMove() {
    Board* b = this->getPointer();
    this->readyTheBoard(b);
    vector<Move> validMoves = b->getLegalMoves(this->getColour());
    Colour myColour = this->getColour();

    // check if any piece is at risk of capture and if so try to output a move that
    // prevents it
    for (Cell* c : b->getOccupiedCells(myColour)) {

        if (b->pieceIsAtThreat(c->getX(), c->getY())) {
            Move m;

            if (protectPiece(c->getX(), c->getY(), *b, m)) {
                return m;
            }
        }
    }

    // if loop exited, no protection move can be executed and computer will
    // now return move based on level2 computer logic
    return NonRiskyLevel2(*this);

}