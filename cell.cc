#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {}
Cell::Cell(const Cell& other): x{other.x}, y{other.y}, colour{other.colour} {

    if (other.piece == nullptr) {
        piece = nullptr;
    } else if (other.piece->getPiece() == Piece::Pawn) {
        piece = new Pawn (*(static_cast<Pawn *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Rook) {
        piece = new Rook (*(static_cast<Rook *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Knight) {
        piece = new Knight (*(static_cast<Knight *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Bishop) {
        piece = new Bishop (*(static_cast<Bishop *>(other.piece)));
    }  else if (other.piece->getPiece() == Piece::Queen) {
        piece = new Queen (*(static_cast<Queen *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::King) {
        piece = new King (*(static_cast<King *>(other.piece)));
    } 
}

Cell& Cell::operator=(const Cell& other) {
    if (this == &other) return *this;
    x = other.x;
    y = other.y;
    colour = other.colour;

    if (other.piece == nullptr) {
        piece = nullptr;
    } else if (other.piece->getPiece() == Piece::Pawn) {
        piece = new Pawn (*(static_cast<Pawn *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Rook) {
        piece = new Rook (*(static_cast<Rook *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Knight) {
        piece = new Knight (*(static_cast<Knight *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::Bishop) {
        piece = new Bishop (*(static_cast<Bishop *>(other.piece)));
    }  else if (other.piece->getPiece() == Piece::Queen) {
        piece = new Queen (*(static_cast<Queen *>(other.piece)));
    } else if (other.piece->getPiece() == Piece::King) { 
        piece = new King (*(static_cast<King *>(other.piece)));
    } 

    return *this;
}
Cell::~Cell() {delete piece;} // DELETE chessPiece (WHEN IMPLEMENTED)

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

    if (c.piece != nullptr) {
        out << *c.piece;
    } else {
        if (c.colour == Colour::Black) {
            out << "_";
        } else {
            out << " ";
        }
    }

    return out;

}

/* old cell ouput logic
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

*/



