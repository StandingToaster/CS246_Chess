#include "move.h"

Move::Move(Cell & start, Cell & dest): start{start}, dest{dest} {}

Move::Move(const Move& other): start{other.start}, dest{other.dest} {}

Move::~Move() {}
bool Move::hasEnemyPresence() {
    return dest.getChessPiece();
}


