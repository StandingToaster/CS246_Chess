#include "cell.h"
#include "board.h"

ChessPiece::ChessPiece(Colour colour, char display): colour{colour}, display{display} {}

ChessPiece::~ChessPiece() {}

ostream& operator<<(ostream &out, const ChessPiece &cp) {
    out << cp.display;
    return out;
}


Pawn::Pawn(Colour colour): ChessPiece{colour, colour == Colour::White ? 'P' : 'p'} {}
Pawn::~Pawn() {}
bool Pawn::movePiece(Cell & start, Cell & destination, Board & b) {

    destination.addChessPiece(this);
    start.removeChessPiece();


    return false;
}









Rook::Rook(Colour colour): ChessPiece{colour, colour == Colour::White ? 'R' : 'r'} {}
Rook::~Rook() {}
bool Rook::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Knight::Knight(Colour colour): ChessPiece{colour, colour == Colour::White ? 'N' : 'n'} {}
Knight::~Knight() {}
bool Knight::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Bishop::Bishop(Colour colour): ChessPiece{colour, colour == Colour::White ? 'B' : 'b'} {}
Bishop::~Bishop() {}
bool Bishop::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

Queen::Queen(Colour colour): ChessPiece{colour, colour == Colour::White ? 'Q' : 'q'} {}
Queen::~Queen() {}
bool Queen::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}

King::King(Colour colour): ChessPiece{colour, colour == Colour::White ? 'K' : 'k'} {}
King::~King() {}
bool King::movePiece(Cell & start, Cell & destination, Board & b) {
    return false;
}


