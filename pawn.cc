#include "pawn.h"

Pawn::Pawn(Colour colour): ChessPiece{colour} {

    if (colour == Colour::White) {
        display = 'P';
    } else {
        display = 'p';
    }

}

Pawn::~Pawn() {}

bool Pawn::movePiece(Cell & start, Cell & destination) {
    return false;
}