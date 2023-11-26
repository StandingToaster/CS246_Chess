#include "cell.h"


ChessPiece::ChessPiece(Colour colour, char display): colour{colour}, display{display} {}

ChessPiece::~ChessPiece() {}

ostream& operator<<(ostream &out, const ChessPiece &cp) {
    out << cp.display;
    return out;
}


Pawn::Pawn(Colour colour): ChessPiece{colour, colour == Colour::White ? 'P' : 'p'} {}

Pawn::~Pawn() {}

bool Pawn::movePiece(Cell & start, Cell & destination) {
    return false;
}
