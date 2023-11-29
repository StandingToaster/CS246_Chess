#include "move.h"

bool Move::hasEnemyPresence() {
    return dest.getChessPiece();
}

