#include "cell.h"
#include "board.h"

ChessPiece::ChessPiece(Colour colour, Piece piece, char display): colour{colour}, piece{piece}, display{display} {}
ChessPiece::ChessPiece(const ChessPiece& other): colour{other.colour}, piece{other.piece}, display{other.display} {}
ChessPiece& ChessPiece::operator=(const ChessPiece& other) {
    if (this == &other) return *this;

    colour = other.colour;
    piece = other.piece;
    display = other.display;

    return *this;
}

ChessPiece::~ChessPiece() {}

Colour ChessPiece::getColour() {return colour;}
Piece ChessPiece::getPiece() {return piece;}

ostream& operator<<(ostream &out, const ChessPiece &cp) {
    out << cp.display;
    return out;
}


Pawn::Pawn(Colour colour): ChessPiece{colour, Piece::Pawn, colour == Colour::White ? 'P' : 'p'} {}
Pawn::Pawn(const Pawn& other): ChessPiece{other} {}
Pawn& Pawn::operator=(const Pawn& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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

    } else if (start.getChessPiece()->getColour() == Colour::White){ // pawn is white, travels 'up' the board

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
bool Pawn::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() != nullptr && start.getChessPiece()->getColour() == destination.getChessPiece()->getColour()) { // attacking into destination with same color piece
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    if (start.getChessPiece()->getColour() == Colour::Black) { // black pawn travels 'down' the board

        // black pawn attacking bottom left diagonally.
        if (!b.cellEmpty(sx - 1, sy + 1) && dx == sx - 1 && dy == sy + 1) {
            return true;
        }

        // black pawn attacking bottom right diagonally. 
        if (!b.cellEmpty(sx + 1, sy + 1) && dx == sx + 1 && dy == sy + 1) {
            return true;
        }

    } else if (start.getChessPiece()->getColour() == Colour::White) {
        
        // white pawn attacking upper left diagonally
        if (!b.cellEmpty(sx - 1, sy - 1) && dx == sx - 1 && dy == sy - 1) {
            return true;
        }   

        // white pawn attacking upper right diagonally
        if (!b.cellEmpty(sx + 1, sy - 1) && dx == sx + 1 && dy == sy - 1) {
            return true;
        }
    } 

    return false;


}
void Pawn::determineLegalMoves(Cell & start, Board & b) {

    int sx = start.getX();
    int sy = start.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return;
    }
    if (start.getChessPiece()->getPiece() != Piece::Pawn) { // start piece is not pawn
        return;
    }


    if (start.getChessPiece()->getColour() == Colour::Black) { // black pawn travels 'down' the board

        // black pawn can attack bottom left diagonally.
        if (!b.cellEmpty(sx - 1, sy + 1) && b.getCell(sx - 1, sy + 1).getChessPiece()->getColour() != Colour::Black) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx - 1, sy + 1)});
        }

        // black pawn can attack bottom right diagonally. 
        if (!b.cellEmpty(sx + 1, sy + 1) && b.getCell(sx - 1, sy + 1).getChessPiece()->getColour() != Colour::Black) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx + 1, sy + 1)});
        }

        // space right below black pawn is empty
        if (b.cellEmpty(sx, sy + 1)) { 
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx, sy + 1)});

        }

        if (firstMove) {
            
            // black pawn can move down 2 squares if conducting first move.
            if (b.cellEmpty(sx, sy + 1) && b.cellEmpty(sx, sy + 2)) {
                b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx, sy + 2)});
            }

        }

    } else if (start.getChessPiece()->getColour() == Colour::White){ // pawn is white, travels 'up' the board

        // white pawn can attack upper left diagonally
        if (!b.cellEmpty(sx - 1, sy - 1)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx - 1, sy - 1)});
        }   

        // white pawn can attack upper right diagonally
        if (!b.cellEmpty(sx + 1, sy - 1)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx + 1, sy - 1)});

        }

        // space right above black pawn is empty
        if (b.cellEmpty(sx, sy - 1)) { 
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx, sy - 1)});
        }

        if (firstMove) {
            // white pawn moving up 2 squares if conducting first move.
            if (b.cellEmpty(sx, sy - 1) && b.cellEmpty(sx, sy - 2)) {
                b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx, sy - 2)});
            }

        }


    }


}







Rook::Rook(Colour colour): ChessPiece{colour, Piece::Rook, colour == Colour::White ? 'R' : 'r'} {}
Rook::Rook(const Rook& other): ChessPiece{other} {}
Rook& Rook::operator=(const Rook& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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
            while (y < b.getBoardSize()) {
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
            while (x < b.getBoardSize()) {
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
bool Rook::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() == nullptr) { // moving into a destination cell with no chesspiece on it. 
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
                    return true;
                }
                y--;
            }

        } else { // moving down
            int y = sy + 1;
            while (y < b.getBoardSize()) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
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
                    return true;
                }
                x--;
            }

        } else { // moving right
            int x = sx + 1;
            while (x < b.getBoardSize()) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    return true;
                }
                x++;
            }
        }

    }

    return false;

}
void Rook::determineLegalMoves(Cell & start, Board & b) {
    int sx = start.getX();
    int sy = start.getY();

    if (start.getChessPiece() == nullptr) { // start piece non-existant
        return;
    }
    if (start.getChessPiece()->getPiece() != Piece::Rook) { // start piece is not rook
        return;
    }

    // moving vertically
    // moving up
    int y = sy - 1;

    while (y >= 0) {
        if (!b.cellEmpty(sx, y) && b.getCell(sx, y).getChessPiece()->getColour() != start.getChessPiece()->getColour()) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx,y)});
            break;
        }

        if (!b.cellEmpty(sx, y) && b.getCell(sx, y).getChessPiece()->getColour() == start.getChessPiece()->getColour()) {
            break;
        }

        if (b.cellEmpty(sx, y)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx,y)});
        }
        y--;
    }

    // moving down
    y = sy + 1;
    while (y < b.getBoardSize()) {
        if (!b.cellEmpty(sx, y) && b.getCell(sx, y).getChessPiece()->getColour() != start.getChessPiece()->getColour()) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx,y)});
            break;
        }

        if (!b.cellEmpty(sx, y) && b.getCell(sx, y).getChessPiece()->getColour() == start.getChessPiece()->getColour()) {
            break;
        }

        if (b.cellEmpty(sx, y)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(sx,y)});
        }
        y++;
    }


    // moving horizontally
    // moving left
    int x = sx - 1;

    while (x >= 0) {
        if (!b.cellEmpty(x, sy) && b.getCell(x, sy).getChessPiece()->getColour() != start.getChessPiece()->getColour()) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(x,sy)});
            break;
        }

        if (!b.cellEmpty(x, sy) && b.getCell(x, sy).getChessPiece()->getColour() == start.getChessPiece()->getColour()) {
            break;
        }

        if (b.cellEmpty(x, sy)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(x,sy)});
        }
        x--;
    }

    // moving right
    x = sx + 1;
    while (x < b.getBoardSize()) {
        if (!b.cellEmpty(x, sy) && b.getCell(x, sy).getChessPiece()->getColour() != start.getChessPiece()->getColour()) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(x,sy)});
            break;
        }

        if (!b.cellEmpty(x, sy) && b.getCell(x, sy).getChessPiece()->getColour() == start.getChessPiece()->getColour()) {
            break;
        }

        if (b.cellEmpty(x, sy)) {
            b.addBlackOrWhiteLegalMove(Move{start, b.getCell(x,sy)});
        }
        x++;
    }
}


Knight::Knight(Colour colour): ChessPiece{colour, Piece::Knight, colour == Colour::White ? 'N' : 'n'} {}
Knight::Knight(const Knight& other): ChessPiece{other} {}
Knight& Knight::operator=(const Knight& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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
bool Knight::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() == nullptr) { // destination chess piece does not exist
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // dest is top-left
    if (dx == sx - 1 && dy == sy - 2) {
        return true;
    }

    // dest is top-right
    if (dx == sx + 1 && dy == sy - 2) {
        return true;
    }

    // dest is right-top
    if (dx == sx + 2 && dy == sy - 1) {
        return true;
    }

    // dest is right-bottom
    if (dx == sx + 2 && dy == sy + 1) {
        return true;
    }

    // dest is bottom-right
    if (dx == sx + 1 && dy == sy + 2) {
        return true;
    }

    // dest is bottom-left
    if (dx == sx - 1 && dy == sy + 2) {
        return true;
    }

    // dest is left-bottom
    if (dx == sx - 2 && dy == sy + 1) {
        return true;
    }

    // dest is left-top
    if (dx == sx - 2 && dy == sy - 1) {
        return true;
    }


    return false;

}
void Knight::determineLegalMoves(Cell & start, Board & b) {

}

Bishop::Bishop(Colour colour): ChessPiece{colour, Piece::Bishop, colour == Colour::White ? 'B' : 'b'} {}
Bishop::Bishop(const Bishop& other): ChessPiece{other} {}
Bishop& Bishop::operator=(const Bishop& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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

        while (x < b.getBoardSize() && y >= 0) {
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

        while (x < b.getBoardSize() && y < b.getBoardSize()) {
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

        while (x >= 0 && y < b.getBoardSize()) {
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
bool Bishop::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() == nullptr) { // destination chess piece does not exist
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }


    // going top right
    if (dx > sx && dy < sy) {

        int x = sx + 1;
        int y = sy - 1;

        while (x < b.getBoardSize() && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                return true;
            }

            x++;
            y--;

        }

    } else if (dx > sx && dy > sy) { // going bottom right
        int x = sx + 1;
        int y = sy + 1;

        while (x < b.getBoardSize() && y < b.getBoardSize()) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                return true;
            }

            x++;
            y++;

        }

    } else if (dx < sx && dy > sy) { // going bottom left

        int x = sx - 1;
        int y = sy + 1;

        while (x >= 0 && y < b.getBoardSize()) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
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
                return true;
            }

            x--;
            y--;

        }

    }

    return false;
}
void Bishop::determineLegalMoves(Cell & start, Board & b) {

}

Queen::Queen(Colour colour): ChessPiece{colour, Piece::Queen, colour == Colour::White ? 'Q' : 'q'} {}
Queen::Queen(const Queen& other): ChessPiece{other} {}
Queen& Queen::operator=(const Queen& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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

        while (x < b.getBoardSize() && y >= 0) {
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

        while (x < b.getBoardSize() && y < b.getBoardSize()) {
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

        while (x >= 0 && y < b.getBoardSize()) {
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
            while (y < b.getBoardSize()) {
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
            while (x < b.getBoardSize()) {
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
bool Queen::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() == nullptr) { // destination chess piece does not exist
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
                    return true;
                }
                y--;
            }

        } else { // moving down
            int y = sy + 1;
            while (y < b.getBoardSize()) {
                if (!b.cellEmpty(sx, y) && y != dy) {
                    return false;
                }

                if (y == dy) {
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
                    return true;
                }
                x--;
            }

        } else { // moving right
            int x = sx + 1;
            while (x < b.getBoardSize()) {
                if (!b.cellEmpty(x, dy) && x != dx) {
                    return false;
                }

                if (x == dx) {
                    return true;
                }
                x++;
            }
        }

    }

    // going top right
    if (dx > sx && dy < sy) {

        int x = sx + 1;
        int y = sy - 1;

        while (x < b.getBoardSize() && y >= 0) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                return true;
            }

            x++;
            y--;

        }

    } else if (dx > sx && dy > sy) { // going bottom right
        int x = sx + 1;
        int y = sy + 1;

        while (x < b.getBoardSize() && y < b.getBoardSize()) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
                return true;
            }

            x++;
            y++;

        }

    } else if (dx < sx && dy > sy) { // going bottom left

        int x = sx - 1;
        int y = sy + 1;

        while (x >= 0 && y < b.getBoardSize()) {
            if (!b.cellEmpty(x,y) && x != dx && y != dy) {
                return false;
            }

            if (x == dx && y == dy) {
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
                return true;
            }

            x--;
            y--;

        }

    }

    return false;
}
void Queen::determineLegalMoves(Cell & start, Board & b) {

}

King::King(Colour colour): ChessPiece{colour, Piece::King, colour == Colour::White ? 'K' : 'k'} {}
King::King(const King& other): ChessPiece{other} {}
King& King::operator=(const King& other) {
    if (this == &other) return *this;
    ChessPiece::operator=(other);
    return *this;
}
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
bool King::canAttack(Cell & start, Cell & destination, Board & b) {
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
    if (destination.getChessPiece() == nullptr) { // destination chess piece does not exist
        return false;
    }
    if (sx == dx && sy == dy) { // start cell == destination cell
        return false;
    }

    // dest is top
    if (dx == sx && dy == sy - 1) {
        return true;
    }

    // dest is top-right
    if (dx == sx + 1 && dy == sy - 1) {
        return true;
    }

    // dest is right
    if (dx == sx + 1 && dy == sy) {
        return true;
    }

    // dest is bottom-right
    if (dx == sx + 1 && dy == sy + 1) {
        return true;
    }

    // dest is bottom
    if (dx == sx && dy == sy + 1) {
        return true;
    }

    // dest is bottom-left
    if (dx == sx - 1 && dy == sy + 1) {
        return true;
    }

    // dest is left
    if (dx == sx - 1 && dy == sy) {
        return true;
    }

    // dest is top-left
    if (dx == sx - 1 && dy == sy - 1) {
        return true;
    }

    return false;
}
void King::determineLegalMoves(Cell & start, Board & b) {

}
