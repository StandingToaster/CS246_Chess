#include "board.h"
#include <iostream>

using namespace std;

Board::Board() {}

Board::Board(const Board& other):boardSize(other.boardSize) {

    // Resizing the board and each row to be size 8 in length
    theBoard.resize(boardSize);
    for (int i = 0; i < boardSize; i++) {
        theBoard[i].resize(boardSize);
    }

    for (int i = 0; i < boardSize; i++) { // i = Y
        for (int j = 0; j < boardSize; j++) { // j = X
            theBoard[i][j] = other.theBoard[i][j];
            if (theBoard[i][j].getChessPiece() != nullptr) {
                addBlackOrWhitePieceCell(&(theBoard[i][j]));
            }
        }
    }

    allBlackLegalMoves.resize(other.allBlackLegalMoves.size());
    allWhiteLegalMoves.resize(other.allWhiteLegalMoves.size());    
    
    for (long unsigned int i = 0; i < allBlackLegalMoves.size(); i++) {
        allBlackLegalMoves[i] = other.allBlackLegalMoves[i];;
    }
    
    for (long unsigned int i = 0; i < allWhiteLegalMoves.size(); i++) {
        allWhiteLegalMoves[i] = other.allWhiteLegalMoves[i];
    }
    
}


Board::~Board() {}

Cell & Board::getCell(int x, int y) {
    if (0 <= x && x < boardSize && 0 <= y && y < boardSize) {
        return theBoard[y][x];
    } else {
        return theBoard[0][0]; // x, y out of bounds
    }
}

int Board::getBoardSize() {return boardSize;}


vector<Move> Board::getLegalMoves(Colour colour) {
    if (colour == Colour::Black) {
        return this->allBlackLegalMoves;
    }
    else {
        return this->allWhiteLegalMoves;
    }
}


bool Board::cellEmpty(int x, int y) {
    if (0 <= x && x < boardSize && 0 <= y && y < boardSize) {
        if (theBoard[y][x].getChessPiece() == nullptr) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void Board::setEmptyBoard() {

    // Resizing the board and each row to be size 8 in length
    theBoard.resize(boardSize);
    for (int i = 0; i < boardSize; i++) {
        theBoard[i].resize(boardSize);
    }

    bool whiteFirst = true;
    for (int i = 0; i < boardSize; i++) { // i = Y
        for (int j = 0; j < boardSize; j++) { // j = X
            theBoard[i][j].setCoords(j, i);

            if (j % 2 == 0 && whiteFirst) {
                theBoard[i][j].setColour(Colour::White);
            } else if (j % 2 != 0 && whiteFirst) {
                theBoard[i][j].setColour(Colour::Black);
            } else if (j % 2 == 0 && !whiteFirst) {
                theBoard[i][j].setColour(Colour::Black);
            } else {
                theBoard[i][j].setColour(Colour::White);
            }

            theBoard[i][j].deleteChessPiece(); // deletes any chess pieces if there are any on this cell. 
        
        }
        whiteFirst = !whiteFirst;
    }

    blackPieceCells.clear();
    whitePieceCells.clear();
    clearLegalMoves();

}

void Board::setDefaultBoard() { 

    this->setEmptyBoard();

    // Initialize black pawns
    for (int i = 0; i < boardSize; i++) {
        theBoard[1][i].addChessPiece(new Pawn(Colour::Black));
        addBlackOrWhitePieceCell(&theBoard[1][i]);
    }

    // Initialize other black pieces
    theBoard[0][0].addChessPiece(new Rook(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][0]);
    theBoard[0][1].addChessPiece(new Knight(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][1]);
    theBoard[0][2].addChessPiece(new Bishop(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][2]);
    theBoard[0][3].addChessPiece(new Queen(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][3]);
    theBoard[0][4].addChessPiece(new King(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][4]);
    theBoard[0][5].addChessPiece(new Bishop(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][5]);
    theBoard[0][6].addChessPiece(new Knight(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][6]);
    theBoard[0][7].addChessPiece(new Rook(Colour::Black));
    addBlackOrWhitePieceCell(&theBoard[0][7]);

    // Initialize white pawns
    for (int i = 0; i < boardSize; i++) {
        theBoard[6][i].addChessPiece(new Pawn(Colour::White));
        addBlackOrWhitePieceCell(&theBoard[6][i]);
    }

    // Initialize other white pieces
    theBoard[7][0].addChessPiece(new Rook(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][0]);
    theBoard[7][1].addChessPiece(new Knight(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][1]);
    theBoard[7][2].addChessPiece(new Bishop(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][2]);
    theBoard[7][3].addChessPiece(new Queen(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][3]);
    theBoard[7][4].addChessPiece(new King(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][4]);
    theBoard[7][5].addChessPiece(new Bishop(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][5]);
    theBoard[7][6].addChessPiece(new Knight(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][6]);
    theBoard[7][7].addChessPiece(new Rook(Colour::White));
    addBlackOrWhitePieceCell(&theBoard[7][7]);

}

void Board::setPieceOnBoard(ChessPiece * piece, int x, int y) {
    if (0 <= x && x < boardSize && 0 <= y && y < boardSize) {
        
        if (cellEmpty(x, y)) {
            theBoard[y][x].addChessPiece(piece);
            addBlackOrWhitePieceCell(&theBoard[y][x]);
            removeBlackOrWhitePieceCell();
        }
        
        else if (!cellEmpty(x,y)) {
            // printBlackPieceCells();
            theBoard[y][x].deleteChessPiece();
            // removeBlackOrWhitePieceCell();
            theBoard[y][x].addChessPiece(piece);

            // addBlackOrWhitePieceCell(&theBoard[y][x]);
        }
    }
}

void Board::removePieceFromBoard(int x, int y) {
    if (0 <= x && x <= 7 && 0 <= y && y <= 7) {
        theBoard[y][x].deleteChessPiece();
        removeBlackOrWhitePieceCell();
    }
}

void Board::addBlackOrWhitePieceCell(Cell * hasPiece) {
    if (hasPiece->getChessPiece() != nullptr) {
        Colour c = hasPiece->getChessPiece()->getColour();
        if (c == Colour::Black) {
            blackPieceCells.emplace_back(hasPiece);
        } 
        else if (c == Colour::White) {
            whitePieceCells.emplace_back(hasPiece);
        }
    }
}

void Board::removeBlackOrWhitePieceCell() {

    for (long unsigned int i = 0; i < blackPieceCells.size(); i++) {
        if (blackPieceCells[i]->getChessPiece() == nullptr || blackPieceCells[i]->getChessPiece()->getColour() != Colour::Black) {
            blackPieceCells.erase(blackPieceCells.begin() + i);
        }
    }

    for (long unsigned int i = 0; i < whitePieceCells.size(); i++) {
        if (whitePieceCells[i]->getChessPiece() == nullptr || whitePieceCells[i]->getChessPiece()->getColour() != Colour::White) {
            whitePieceCells.erase(whitePieceCells.begin() + i);
        }
    }

}


void Board::printBlackPieceCells() {
    for (long unsigned int i = 0; i < blackPieceCells.size(); i++) {
        cout << "(" << blackPieceCells[i]->getX() << "," << blackPieceCells[i]->getY() << ")" << " : " << *blackPieceCells[i] << endl;
    }
}
void Board::printWhitePieceCells() {
    for (long unsigned int i = 0; i < whitePieceCells.size(); i++) {
        cout << "(" << whitePieceCells[i]->getX() << "," << whitePieceCells[i]->getY() << ")" << " : " << *whitePieceCells[i] << endl;
    }
}



void Board::addBlackOrWhiteLegalMove(Move move) {
    Colour c = move.getStart().getChessPiece()->getColour();
    if (c == Colour::Black) {
        allBlackLegalMoves.emplace_back(move);
    }
    else if (c == Colour::White) {
        allWhiteLegalMoves.emplace_back(move);
    }
}

void Board::calculateAllLegalMoves() {
    // determines all black legal moves
    for (long unsigned int i = 0; i < blackPieceCells.size(); i++) { 
        blackPieceCells[i]->getChessPiece()->determineLegalMoves(*blackPieceCells[i], *this);
        
    }

    // determines all white legal moves
    for (long unsigned int i = 0; i < whitePieceCells.size(); i++) { 
        whitePieceCells[i]->getChessPiece()->determineLegalMoves(*whitePieceCells[i], *this);
    }

}


void Board::clearLegalMoves() {
    allBlackLegalMoves.clear();
    allWhiteLegalMoves.clear();
}

void Board::printBlackLegalMoves() {
    for (long unsigned int i = 0; i < allBlackLegalMoves.size(); i++) {
        cout << allBlackLegalMoves[i].getStart() << " - " <<
        "Start: " << "(" << allBlackLegalMoves[i].getStart().getX() << "," << allBlackLegalMoves[i].getStart().getY() << ") "
        << "Dest: " << "(" << allBlackLegalMoves[i].getDest().getX() << "," << allBlackLegalMoves[i].getDest().getY() << ")" << endl;
    }
    cout << "Num Black Legal Moves: " << allBlackLegalMoves.size() << endl;
}
void Board::printWhiteLegalMoves() {
    
    for (long unsigned int i = 0; i < allWhiteLegalMoves.size(); i++) {
        cout << allWhiteLegalMoves[i].getStart() << " - " <<
        "Start: " << "(" << allWhiteLegalMoves[i].getStart().getX() << "," << allWhiteLegalMoves[i].getStart().getY() << ") "
        << "Dest: " << "(" << allWhiteLegalMoves[i].getDest().getX() << "," << allWhiteLegalMoves[i].getDest().getY() << ")" << endl;
    }
    cout << "Num White Legal Moves: " << allWhiteLegalMoves.size() << endl;
}


bool Board::activateMove(Cell & start, Cell & destination) {

    if (start.getChessPiece() != nullptr) {
        if (start.getChessPiece()->movePiece(start, destination, *this)) {

            addBlackOrWhitePieceCell(&destination);
            removeBlackOrWhitePieceCell();
            return true;
        }
    }  
    return false;
}

bool Board::attackPossible(Cell & start, Cell & destination) {
    if (start.getChessPiece() != nullptr) {
        return start.getChessPiece()->canAttack(start, destination, *this);
    } else {
        return false;
    }
}

void Board::promotePawn(Piece promoteTo) {

    // promote black pawns, when y = boardsize - 1
    for (int i = 0; i < boardSize; i++) {
        if (theBoard[boardSize - 1][i].getChessPiece() != nullptr 
        && theBoard[boardSize - 1][i].getChessPiece()->getColour() == Colour::Black
        && theBoard[boardSize - 1][i].getChessPiece()->getPiece() == Piece::Pawn) {
            
            if (promoteTo == Piece::Rook) {
                setPieceOnBoard(new Rook(Colour::Black), i, boardSize - 1 );
            } else if (promoteTo == Piece::Knight) {
                setPieceOnBoard(new Knight(Colour::Black), i, boardSize - 1 );
            } else if (promoteTo == Piece::Bishop) {
                setPieceOnBoard(new Bishop(Colour::Black), i, boardSize - 1 );
            } else if (promoteTo == Piece::Queen) {
                setPieceOnBoard(new Queen(Colour::Black), i, boardSize - 1 );
            }

            break; // there will only be one black pawn on the last row at any given time
 
        }
    }

    // promote white pawns, when y = 0
    for (int i = 0; i < boardSize; i++) {
        if (theBoard[0][i].getChessPiece() != nullptr 
        && theBoard[0][i].getChessPiece()->getColour() == Colour::White
        && theBoard[0][i].getChessPiece()->getPiece() == Piece::Pawn) {
            
            
            if (promoteTo == Piece::Rook) {
                setPieceOnBoard(new Rook(Colour::White), i, 0);
            } else if (promoteTo == Piece::Knight) {
                setPieceOnBoard(new Knight(Colour::White), i, 0);
            } else if (promoteTo == Piece::Bishop) {
                setPieceOnBoard(new Bishop(Colour::White), i, 0);
            } else if (promoteTo == Piece::Queen) {
                setPieceOnBoard(new Queen(Colour::White), i, 0);
            }

            break; // there will only be one white pawn on the first row at any given time
 
        }
    }

}


bool Board::checked(Colour kingColour) {
    int kingX;
    int kingY;

    // Get X and Y coords of king whose check status is in question.
    if (kingColour == Colour::Black) { // king is black
        for (long unsigned int i = 0; i < blackPieceCells.size(); i++) {
            if (blackPieceCells[i]->getChessPiece()->getPiece() == Piece::King) {
                kingX = blackPieceCells[i]->getX();
                kingY = blackPieceCells[i]->getY();
                break;
            }
        }

        // determines if any white piece can attack the black king.
        for (long unsigned int i = 0; i < whitePieceCells.size(); i++) {
            if (attackPossible(getCell(whitePieceCells[i]->getX(), whitePieceCells[i]->getY()), getCell(kingX, kingY))) {
                return true;
            }
        }

    } else { // king is white
        for (long unsigned int i = 0; i < whitePieceCells.size(); i++) {
            if (whitePieceCells[i]->getChessPiece()->getPiece() == Piece::King) {
                kingX = whitePieceCells[i]->getX();
                kingY = whitePieceCells[i]->getY();
                break;
            }
        }

        // determine if any black piece can attack the white king. 
        for (long unsigned int i = 0; i < blackPieceCells.size(); i++) {
            if (attackPossible(getCell(blackPieceCells[i]->getX(), blackPieceCells[i]->getY()), getCell(kingX, kingY))) {
                return true;
            }
        }

    }

    return false;

}

bool Board::checkMated(Colour kingColour) {
    
    if (!checked(kingColour)) {
        return false;
    }

    // Essentially, all legal moves are calculated, and for the corresponding king color, each move is simulated from the 
    // vector of legal moves for the corresponding color. So a copy of the current board is made to ensure its state is not
    // changed, and the move is simulated. If check returns true for each simulated move, the king is checkmated. However even 
    // if one simulated move results in check returning false, the king is not checkmated. 
    clearLegalMoves();
    calculateAllLegalMoves();
    if (kingColour == Colour::Black) { // checking if black king is checkmated. 

        for (long unsigned int i = 0; i < allBlackLegalMoves.size(); i++) {
            Move m = allBlackLegalMoves[i];
            Cell & start = m.getStart();
            Cell & dest = m.getDest();

            int sx = start.getX();
            int sy = start.getY();
            int dx = dest.getX();
            int dy = dest.getY();

            Board b_copy = *this;
            b_copy.activateMove(b_copy.getCell(sx, sy), b_copy.getCell(dx, dy)); // something here
            // cout << b_copy << endl;

            if (!b_copy.checked(Colour::Black)) {
               // cout << "NOT CHECKMATED" << endl;
                return false;
            }
        }
    }

    if (kingColour == Colour::White) { // checking if white king is checkmated.
        for (long unsigned int i = 0; i < allWhiteLegalMoves.size(); i++) {
            Move m = allWhiteLegalMoves[i];
            Cell & start = m.getStart();
            Cell & dest = m.getDest();
        
            int sx = start.getX();
            int sy = start.getY();
            int dx = dest.getX();
            int dy = dest.getY();
            
            Board b_copy = *this;
            
            b_copy.activateMove(b_copy.getCell(sx, sy), b_copy.getCell(dx, dy)); 
            // cout << b_copy << endl;

            if (!b_copy.checked(Colour::White)) {
                //cout << "NOT CHECKMATED" << endl;
                return false;
            }
        }

    }

    //cout << "CHECKMATE!" << endl;
    return true;
}

bool Board::stalemated() {

    clearLegalMoves();
    calculateAllLegalMoves();

    // Check if black king is not checked and has no legal moves
    if (!checked(Colour::Black) && allBlackLegalMoves.size() == 0) {
        return true;
    }   

    // Check if white king is not checked and has no legal moves. 
    if (!checked(Colour::White) && allWhiteLegalMoves.size() == 0) {
        return true;
    }


    int numBlackKing = 0;
    int numBlackKnights = 0;
    int numBlackBishops = 0;

    int numWhiteKing = 0;
    int numWhiteKnights = 0;
    int numWhiteBishops = 0;

    int numEmpty = 0;

    // Determine num empty cells in theBoard 
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (cellEmpty(j, i)) {
                numEmpty++;
            }
        }
    }

    for (long unsigned int i = 0; i < blackPieceCells.size(); i++) {
        if (blackPieceCells[i]->getChessPiece()->getPiece() == Piece::King) {
            numBlackKing++;
        }

        if (blackPieceCells[i]->getChessPiece()->getPiece() == Piece::Knight) {
            numBlackKnights++;
        }

        if (blackPieceCells[i]->getChessPiece()->getPiece() == Piece::Bishop) {
            numBlackBishops++;
        }
    }

    for (long unsigned int i = 0; i < whitePieceCells.size(); i++) {
        if (whitePieceCells[i]->getChessPiece()->getPiece() == Piece::King) {
            numWhiteKing++;
        }

        if (whitePieceCells[i]->getChessPiece()->getPiece() == Piece::Knight) {
            numWhiteKnights++;
        }

        if (whitePieceCells[i]->getChessPiece()->getPiece() == Piece::Bishop) {
            numWhiteBishops++;
        }
    }

    if (numBlackKing == 1 && numWhiteKing == 1 && numEmpty == 62) {
        return true;
    }
        
    if (numBlackKing == 1 && numBlackBishops == 1 && numWhiteKing == 1 && numEmpty == 61) {
        return true;
    }

    if (numBlackKing == 1 && numBlackKnights == 1 && numWhiteKing == 1 && numEmpty == 61) {
        return true;
    }

    if (numWhiteKing == 1 && numWhiteBishops == 1 && numBlackKing == 1 && numEmpty == 61) {
        return true;
    }

    if (numWhiteKing == 1 && numWhiteKnights == 1 && numBlackKing == 1 && numEmpty == 61) {
        return true;
    }

    return false;

}



ostream& operator<<(ostream &out, const Board &b) {
    int row = 8;
    for (int i = 0; i < b.boardSize; i++) {
        out << row << " ";
        row--;
        for (int j = 0; j < b.boardSize; j++) {
            out << b.theBoard[i][j];
        }
        out << endl;
    }

    out << endl;

    out << "  abcdefgh" << endl;

    return out;
    
}

vector<Cell*> Board::getOccupiedCells(Colour colour) {
    if (colour == Colour::Black) {
        return blackPieceCells;
    } else {
        return whitePieceCells;
    }
}

