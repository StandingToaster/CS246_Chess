#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {}

Cell::~Cell() {} // DELETE chessPiece (WHEN IMPLEMENTED)

int Cell::getX() {return x;}

int Cell::getY() {return y;}

ChessPiece * Cell::getChessPiece() {
    return piece;
}

void Cell::setCoords(int x, int y) {this->x = x; this->y = y;}

void Cell::setColour(Colour c) {this->colour = c;}

void Cell::addChessPiece(ChessPiece * piece) {
    if (this->piece != nullptr) {
        delete this->piece;
    }

    this->piece = piece;
}

void Cell::removeChessPiece() {
    piece = nullptr;
}

void Cell::deleteChessPiece() {
    delete piece;
    piece = nullptr;
    
}




ostream& operator<<(ostream &out, const Cell &c) {

    if (c.colour == Colour::White) {
        if (c.piece != nullptr) {
            out << *c.piece;
        } else {
            out << " ";
        }
    } else {
        if (c.piece != nullptr) {
            out << *c.piece;
        } else {
            out << "_";
        }
    }

    return out;

}



