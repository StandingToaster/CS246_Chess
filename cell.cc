#include "cell.h"

using namespace std;

Cell::Cell() {}

Cell::~Cell() {} // DELETE chessPiece (WHEN IMPLEMENTED)

int Cell::getX() {return x;}

int Cell::getY() {return y;}

void Cell::setCoords(int x, int y) {this->x = x; this->y = y;}




