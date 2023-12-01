#include "level3.h"
#include "cell.h"

using namespace std;

level3::level3(Board* in, Colour cur): Computer{in, cur} {}

Move Level2Move(level3& comp, Move& move) {
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


// determines whether a piece at cell c is under threat and returns false if there
// is no piece at that cell
bool pieceIsAtThreat(Cell& c, Board& b) {
    // if no piece at cell return false
    if (c.getChessPiece() == nullptr) {
        return false;
    }


    Colour col = c.getChessPiece()->getColour();

    //check if any of the enemy teams pieces can attack cell c
    for (Cell* attacker : b.getOccupiedCells(col)) {
        if(b.attackPossible(*attacker, c)) {
            return true;
        }
    }
    
    // if loop exited piece is not under threat of attack
    return false;
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



// determines if there is a way to protect cell c and mutates m if so
bool protectPiece(Cell& c, Board& b, Move& m) {
    Colour col = c.getChessPiece()->getColour();
    Colour enemyCol = Colour::Black;
    if (col == Colour::Black) {
        enemyCol = Colour::White;
    }

    // check for all moves that may result in protecting the original cell
    // without putting itself at risk
    for (Move validMove : b.getLegalMoves(col)) {
        Board temp = b;
        // simulate the move on a copy of the board
        temp.activateMove(validMove.getStart(), validMove.getDest());

        if (!pieceIsAtThreat(c, temp) && !pieceIsAtThreat(validMove.getDest(), temp)) {
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

    //Determine what the colour of the enemy king is.
    Colour enemyColour;
        if (myColour == Colour::White) {
            enemyColour = Colour::Black;
        }
        else {
            enemyColour = Colour::White;
        }

    // check if any piece is at risk of capture and if so try to output a move that
    // prevents it
    for (Cell* c : b->getOccupiedCells(myColour)) {
        if (pieceIsAtThreat(*c, *b)) {
            Move m;

            if (protectPiece(*c, *b, m)) {
                return m;
            }
        }
    }

    // if loop exited, no protection move can be executed and computer will
    // now return move based on level2 computer logic
    Move m;
    Level2Move(*this, m);

    return m;
}