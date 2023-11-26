#include "cell.h"
#include "board.h"

ChessPiece::ChessPiece(Colour colour, Piece piece, char display): colour{colour}, piece{piece}, display{display} {}

ChessPiece::~ChessPiece() {}

Colour ChessPiece::getColour() {return colour;}
Piece ChessPiece::getPiece() {return piece;}

ostream& operator<<(ostream &out, const ChessPiece &cp) {
    out << cp.display;
    return out;
}


Pawn::Pawn(Colour colour): ChessPiece{colour, Piece::Pawn, colour == Colour::White ? 'P' : 'p'} {}
Pawn::~Pawn() {}
bool Pawn::movePiece(Cell & start, Cell & destination, Board & b) {
    
    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::Pawn) { // start piece is not pawn
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }


    if (start.getChessPiece()->getColour() == Colour::Black) { // black pawn travels 'down' the board

        // black pawn attacking bottom left diagonally.
        if (!b.cellEmpty(sx - 1, sy + 1) && dx == sx - 1 && dy == sy + 1) {
            destination.deleteChessPiece();
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }

        // black pawn attacking bottom right diagonally. 
        if (!b.cellEmpty(sx + 1, sy + 1) && dx == sx + 1 && dy == sy + 1) {
            destination.deleteChessPiece();
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }

        // space right below black pawn is dest
        if (b.cellEmpty(sx, sy + 1) && dx == sx && dy == sy + 1) { 
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }

        if (firstMove) {
            
            // black pawn moving down 2 squares if conducting first move.
            if (b.cellEmpty(sx, sy + 1) && b.cellEmpty(sx, sy + 2) && dx == sx && dy == sy + 2) {
                destination.addChessPiece(this);
                start.removeChessPiece();
                firstMove = false;
                return true;
            }

        }


    } else { // pawn is white, travels 'up' the board

        // white pawn attacking upper left diagonally
        if (!b.cellEmpty(sx - 1, sy - 1) && dx == sx - 1 && dy == sy - 1) {
            destination.deleteChessPiece();
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }   

        // white pawn attacking upper right diagonally
        if (!b.cellEmpty(sx + 1, sy - 1) && dx == sx + 1 && dy == sy - 1) {
            destination.deleteChessPiece();
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }

        // space right above black pawn is dest
        if (b.cellEmpty(sx, sy - 1) && dx == sx && dy == sy - 1) { 
            destination.addChessPiece(this);
            start.removeChessPiece();
            firstMove = false;
            return true;
        }

        if (firstMove) {
            // white pawn moving up 2 squares if conducting first move.
            if (b.cellEmpty(sx, sy - 1) && b.cellEmpty(sx, sy - 2) && dx == sx && dy == sy - 2) {
                destination.addChessPiece(this);
                start.removeChessPiece();
                firstMove = false;
                return true;
            }

        }


    }

    return false;
    
}




Rook::Rook(Colour colour): ChessPiece{colour, Piece::Rook, colour == Colour::White ? 'R' : 'r'} {}
Rook::~Rook() {}
bool Rook::movePiece(Cell & start, Cell & destination, Board & b) {

    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::Rook) { // start piece is not rook
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }
    
    // moving vertically
    if (sx == dx) {

        // moving up
        if (dy < sy) {
            int y = sy - 1;

            while (y >= 0) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                y--;
            }

        } else { // moving down
            int y = sy + 1;
            while (y <= 7) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                y++;
            }

        }

    } else if (sy == dy) { // moving horizontally

        // moving left
        if (dx < sx) {
            int x = sx - 1;

            while (x >= 0) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                x--;
            }

        } else { // moving right
            int x = sx + 1;
            while (x <= 7) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                x++;
            }

        }


    }

    return false;
}




Knight::Knight(Colour colour): ChessPiece{colour, Piece::Knight, colour == Colour::White ? 'N' : 'n'} {}
Knight::~Knight() {}
bool Knight::movePiece(Cell & start, Cell & destination, Board & b) {

    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::Knight) { // start piece is not knight
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // dest is top-left
    if (dx == sx - 1 && dy == sy - 2) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is top-right
    if (dx == sx + 1 && dy == sy - 2) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is right-top
    if (dx == sx + 2 && dy == sy - 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is right-bottom
    if (dx == sx + 2 && dy == sy + 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is bottom-right
    if (dx == sx + 1 && dy == sy + 2) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is bottom-left
    if (dx == sx - 1 && dy == sy + 2) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is left-bottom
    if (dx == sx - 2 && dy == sy + 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is left-top
    if (dx == sx - 2 && dy == sy - 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }


    return false;
}

Bishop::Bishop(Colour colour): ChessPiece{colour, Piece::Bishop, colour == Colour::White ? 'B' : 'b'} {}
Bishop::~Bishop() {}
bool Bishop::movePiece(Cell & start, Cell & destination, Board & b) {
    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::Bishop) { // start piece is not bishop
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // going top right
    if (dx > sx && dy < sy) {

        int x = sx + 1;
        int y = sy - 1;

        while (x <= 7 && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x++;
            y--;

        }

    } else if (dx > sx && dy > sy) { // going bottom right
        int x = sx + 1;
        int y = sy + 1;

        while (x <= 7 && y <= 7) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x++;
            y++;

        }

    } else if (dx < sx && dy > sy) { // going bottom left

        int x = sx - 1;
        int y = sy + 1;

        while (x >= 0 && y <= 7) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x--;
            y++;

        }


    } else if (dx < sx && dy < sy) { // going top left

        int x = sx - 1;
        int y = sy - 1;

        while (x >= 0 && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x--;
            y--;

        }

    }

    return false;
}

Queen::Queen(Colour colour): ChessPiece{colour, Piece::Queen, colour == Colour::White ? 'Q' : 'q'} {}
Queen::~Queen() {}
bool Queen::movePiece(Cell & start, Cell & destination, Board & b) {
    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::Queen) { // start piece is not queen
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // going top right
    if (dx > sx && dy < sy) {

        int x = sx + 1;
        int y = sy - 1;

        while (x <= 7 && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x++;
            y--;

        }

    } else if (dx > sx && dy > sy) { // going bottom right
        int x = sx + 1;
        int y = sy + 1;

        while (x <= 7 && y <= 7) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x++;
            y++;

        }

    } else if (dx < sx && dy > sy) { // going bottom left

        int x = sx - 1;
        int y = sy + 1;

        while (x >= 0 && y <= 7) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x--;
            y++;

        }


    } else if (dx < sx && dy < sy) { // going top left

        int x = sx - 1;
        int y = sy - 1;

        while (x >= 0 && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                destination.deleteChessPiece();
                destination.addChessPiece(this);
                start.removeChessPiece();
                return true;
            }

            x--;
            y--;

        }

    }

    // moving vertically
    if (sx == dx) {

        // moving up
        if (dy < sy) {
            int y = sy - 1;

            while (y >= 0) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                y--;
            }

        } else { // moving down
            int y = sy + 1;
            while (y <= 7) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                y++;
            }

        }

    } else if (sy == dy) { // moving horizontally

        // moving left
        if (dx < sx) {
            int x = sx - 1;

            while (x >= 0) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                x--;
            }

        } else { // moving right
            int x = sx + 1;
            while (x <= 7) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    destination.deleteChessPiece();
                    destination.addChessPiece(this);
                    start.removeChessPiece();
                    return true;
                }
                x++;
            }
        }
    }


    return false;
}

King::King(Colour colour): ChessPiece{colour, Piece::King, colour == Colour::White ? 'K' : 'k'} {}
King::~King() {}
bool King::movePiece(Cell & start, Cell & destination, Board & b) {
    int sx = start.getX();
    int sy = start.getY();
    int dx = destination.getX();
    int dy = destination.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return false;
    }
    if (start.getChessPiece()->getPiece() != Piece::King) { // start piece is not king
        return false;
    }
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // moving into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // dest is top
    if (dx == sx && dy == sy - 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is top-right
    if (dx == sx + 1 && dy == sy - 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is right
    if (dx == sx + 1 && dy == sy) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is bottom-right
    if (dx == sx + 1 && dy == sy + 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is bottom
    if (dx == sx && dy == sy + 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is bottom-left
    if (dx == sx - 1 && dy == sy + 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is left
    if (dx == sx - 1 && dy == sy) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    // dest is top-left
    if (dx == sx - 1 && dy == sy - 1) {
        destination.deleteChessPiece();
        destination.addChessPiece(this);
        start.removeChessPiece();
        return true;
    }

    return false;
}


