#include "cell.h"

using namespace std;

Cell::Cell() {}

Cell::~Cell() {} // DELETE chessPiece (WHEN IMPLEMENTED)

int Cell::getX() {return x;}

int Cell::getY() {return y;}

void Cell::setCoords(int x, int y) {this->x = x; this->y = y;}

void Cell::setColour(Colour c) {this->colour = c;}

ostream& operator<<(ostream &out, const Cell &c) {

    if (c.colour == Colour::White) {
        out << " ";
    } else {
        out << "_";
    }

    return out;

}



