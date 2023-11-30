#include "computer.h"

using namespace std;

Computer::Computer(Board* board, Colour cur): current{board}, currentColour{cur} {}

Colour Computer::getColour() {
    return this->currentColour;
}

Board* Computer::getPointer() {
    return this->current;
}

void Computer::readyTheBoard(Board* input) {
    input->clearLegalMoves();
    input->calculateAllLegalMoves();
    return;
}

