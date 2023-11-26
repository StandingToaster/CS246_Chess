#include "cell.h"
#include "board.h"

ChessPiece::ChessPiece(Colour colour, Piece piece, char display): colour{colour}, piece{piece}, display{display} {}

ChessPiece::~ChessPiece() {}

Colour ChessPiece::getColour() {return colour;}
Piece ChessPiece::getPiece() {return piece;}

ostream& operator<<(ostream &out, const ChessPiece &cp) {
    out << cp.display;
    return out;
}


Pawn::Pawn(Colour colour): ChessPiece{colour, Piece::Pawn, colour == Colour::White ? 'P' : 'p'} {}
Pawn::~Pawn() {}
bool Pawn::movePiece(Cell & start, Cell & destination, Board & b) {

    if (start.getChessPiece()->getPiece() != Piece::Pawn) { // start piece is not pawn
        return false;
    }

    if (start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }


    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (sx == dx && sy == dy) {
        return false;
    }

    if (start.getChessPiece()->getColour() == Colour::Black) { // black pawn travels 'down' the board

        if (dx >= sx + 2 || dx <= sx - 2) {
            return false;
        }

        if (dy <= sy) {
            return false;
        }

        if (numMoves == 0) {

            if (dy >= sx + 3) {
                return false;
            }

            if ( (sx - 1 == dx && sy + 2 == dy) ||  (sx + 1 == dx && sy + 2 == dy) ) {
                return false;
            }
            
            

            if ( b.cellEmpty(sx - 1, sy + 1)  && dx == sx - 1 && dy = sy + 1) {
                return false;
            }


        }


    }

    // destination.addChessPiece(this);
    // start.removeChessPiece();


    return false;
}









Rook::Rook(Colour colour): ChessPiece{colour, Piece::Rook, colour == Colour::White ? 'R' : 'r'} {}
Rook::~Rook() {}
bool Rook::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Knight::Knight(Colour colour): ChessPiece{colour, Piece::Knight, colour == Colour::White ? 'N' : 'n'} {}
Knight::~Knight() {}
bool Knight::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Bishop::Bishop(Colour colour): ChessPiece{colour, Piece::Bishop, colour == Colour::White ? 'B' : 'b'} {}
Bishop::~Bishop() {}
bool Bishop::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Queen::Queen(Colour colour): ChessPiece{colour, Piece::Queen, colour == Colour::White ? 'Q' : 'q'} {}
Queen::~Queen() {}
bool Queen::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

King::King(Colour colour): ChessPiece{colour, Piece::King, colour == Colour::White ? 'K' : 'k'} {}
King::~King() {}
bool King::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}


