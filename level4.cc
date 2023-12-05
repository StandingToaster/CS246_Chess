#include "level4.h"
#include "cell.h"

using namespace std;

level4::level4(Board* in, Colour cur): Computer{in, cur} {}


// returns the "best" kill move and the associated score.
// Score is calculated by looking at the value of the piece captured and whether
// or not the piece moved in order to make that capture is being put at risk.
// if it is putting the piece at risk, the score is compensated by subtracting the value
// of the piece at risk from the score.
//
// Note -9 means that there was no capture move
int bestCapturemove(level4& comp, Move& move) {
    Board* b = comp.getPointer();
    comp.readyTheBoard(b);
    vector<Move> validMoves = b->getLegalMoves(comp.getColour());

    // keeps track of best kill trade score
    int BestScore = -9;
    Move bestMove = move;

    for (Move m : validMoves) {
        int currentScore = 0;

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        if (!b->attackPossible(b->getCell(sx, sy), b->getCell(dx, dy))) continue; // skip move if it isnt an attack
        
        //add the value of the piece taken
        if (b->getCell(dx, dy).getChessPiece()->getPiece() == Piece::Queen) {
            currentScore += 9;
        } else if (b->getCell(dx, dy).getChessPiece()->getPiece() == Piece::Rook) {
            currentScore += 5;
        } else if (b->getCell(dx, dy).getChessPiece()->getPiece() == Piece::Bishop ||
                b->getCell(dx, dy).getChessPiece()->getPiece() == Piece::Knight) {
            currentScore += 3;
        } else {
        currentScore += 1;
        }

        Board temp = *b;
        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx, dy));

        // subtract value of piece used if it put at risk by executing the capture
        if (temp.pieceIsAtThreat(m.getDest().getX(),m.getDest().getY())) {
            if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Queen) {
                currentScore -= 9;
            } else if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Rook) {
            currentScore -= 5;
            } else if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Bishop ||
                temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Knight) {
                currentScore -= 3;
            } else {
                currentScore -= 1;
            }
        }

        if (currentScore > BestScore) { //update bestscore and move if better capture found
            bestMove = m;
            BestScore = currentScore;
        }
    }

    //update to the best most found out of all captures
    move = bestMove;

    return BestScore;

}


// finds the BEST way to protect the piece (trys not to sacrifice important)
// pieces to protect the piece at cell at x,y and returns the final score as an int
// Move is mutated with this protection move
// This function is meant to be called on a cell on a board that is under threat
// of capture
// -9 represents no way to protect piece
int bestProtectPiece(int x, int y, Board& b, Move& m) {
    Colour col = b.getCell(x, y).getChessPiece()->getColour();

    int bestScore = -9;

    for (Move validMove : b.getLegalMoves(col)) {
        Board temp = b;

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();
        // simulate the move on a copy of the board
        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx, dy));

        int currentScore = -9;

        //add the value of the piece protected
        if (b.getCell(x, y).getChessPiece()->getPiece() == Piece::Queen) {
            currentScore = 9;
        } else if (b.getCell(x, y).getChessPiece()->getPiece() == Piece::Rook) {
            currentScore = 5;
        } else if (b.getCell(x, y).getChessPiece()->getPiece() == Piece::Bishop ||
                   b.getCell(x, y).getChessPiece()->getPiece() == Piece::Knight) {
            currentScore = 3;
        } else {
            currentScore = 1;
        }

        // checks the threat status of both the original cell at threat and the destination
        // and adjusts currectScor accordingly
        if (!temp.pieceIsAtThreat(validMove.getDest().getX(), validMove.getDest().getY())) {
            if (temp.pieceIsAtThreat(m.getDest().getX(), m.getDest().getY())) {
                if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Queen) {
                    currentScore -= 9;
                } else if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Rook) {
                currentScore -= 5;
                } else if (temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Bishop ||
                    temp.getCell(dx, dy).getChessPiece()->getPiece() == Piece::Knight) {
                    currentScore -= 3;
                } else {
                    currentScore -= 1;
                }
            }
        }

        if (currentScore > bestScore) {
            m = validMove;
            bestScore = currentScore;
        }
    }

    return bestScore;
}


// returns the "best" protected move and the associated score.
// Score is calculated by looking at the value of the piece protected and whether
// or not the piece moved in order to make that capture is being put at risk.
// if it is putting the piece at risk, the score is compensated by subtracting the value
// of the piece at risk from the score.
//
// Note -9 means that there was no protection move
int bestProtectionMove(level4& comp, Move& move) {
    Board* b = comp.getPointer();
    comp.readyTheBoard(b);
    Colour myColour = comp.getColour();
    vector<Move> validMoves = b->getLegalMoves(myColour);

    // check if any piece is at risk of capture and if so try to output a move that
    // prevents it

    int bestScore = -9;
    Move bestMove = move;

    for (Cell* c : b->getOccupiedCells(myColour)) {
        if (!b->pieceIsAtThreat(c->getX(), c->getY())) continue; // skip move if cell isnt under threat

        Move currentMove;
        // this will potentiallymutate currentMove
        int currentScore = bestProtectPiece(c->getX(), c->getY(), *b, currentMove);
        if (currentScore > bestScore) {
            bestMove = currentMove;
            bestScore = currentScore;
        }
    }

    move = bestMove;
    return bestScore;
}


Move level4::generateMove() {
    Board* b = this->getPointer();
    this->readyTheBoard(b);
    Colour myColour = this->getColour();
    vector<Move> validMoves = b->getLegalMoves(myColour);

    //Determine what the colour of the enemy king is.
    Colour enemyColour;
    if (myColour == Colour::White) {
        enemyColour = Colour::Black;
    }
    else {
        enemyColour = Colour::White;
    }

    Move cm; //capture move
    Move pm; //protect move
    int cmScore = bestCapturemove(*this, cm);
    int pmScore = bestProtectionMove(*this, pm);

    if (cmScore > -1 && cmScore > pmScore) { //cm is worth it and better than pm
        return cm;
    } else if (pmScore > -1 && pmScore > cmScore) { //pm is worth it and better than cm
        return pm;
    } else if (cmScore > -1 && pmScore >= -1 && pmScore == cmScore) { //both worth but equal
        return cm;
    }

    //if not any of the above try returning a check move:
    for (Move m : validMoves) {
        Board temp = *b;

        int sx = m.getStart().getX();
        int sy = m.getStart().getY();
        int dx = m.getDest().getX();
        int dy = m.getDest().getY();

        temp.activateMove(temp.getCell(sx, sy), temp.getCell(dx,dy));
        if (temp.checked(enemyColour)) {
            
            //ensure that the check doesnt result in putting piece at risk
            if (temp.pieceIsAtThreat(m.getDest().getX(), m.getDest().getY())) {
                return m;
            }
        }
    }


    //Now if no potential attack is detected or a check is possible, it will pick a RANDOM valid move.
    srand((unsigned) time(NULL));
    int count = rand() % validMoves.size();
    return validMoves[count];
}