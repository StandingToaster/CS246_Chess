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

bool Move::hasEnemyPresence() {
    return dest.getChessPiece();
}


