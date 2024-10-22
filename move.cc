#include "move.h"

Move::Move() {}

Move::Move(Cell & start, Cell & dest): start{start}, dest{dest} {}

Move::Move(const Move& other): start{other.start}, dest{other.dest} {}

Move& Move::operator=(const Move& other) {
    
    if (this == &other) return *this;
    
    start = other.start;
    dest = other.dest;

    return *this;
}

Move::~Move() {}


Cell & Move::getStart() {return start;}

Cell & Move::getDest() {return dest;}


bool Move::hasEnemyPresence() { // Make sure this works as intended (nullptr returns 0, regular ptr returns 1)
    if (dest.getChessPiece() == nullptr) {
        return false;
    }
    else {
        return true;
    }
}


