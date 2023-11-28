#include "board.h"
#include <iostream>

using namespace std;


Board::Board() {}

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

    bool whiteFirst = true;;
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
        theBoard[y][x].addChessPiece(piece);
        addBlackOrWhitePieceCell(&theBoard[y][x]);
        removeBlackOrWhitePieceCell();
    }

}

void Board::removePieceFromBoard(int x, int y) {
    if (0 <= x && x <= 7 && 0 <= y && y <= 7) {
        theBoard[y][x].deleteChessPiece();
        removeBlackOrWhitePieceCell();
    }
}

void Board::addBlackOrWhitePieceCell(Cell * hasPiece) {
    Colour c = hasPiece->getChessPiece()->getColour();
    if (c == Colour::Black) {
        blackPieceCells.emplace_back(hasPiece);
    } 
    else if (c == Colour::White) {
        whitePieceCells.emplace_back(hasPiece);
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


void Board::activateMove(Cell & start, Cell & destination) {

    if (start.getChessPiece() != nullptr) {
        if (start.getChessPiece()->movePiece(start, destination, *this)) {
            addBlackOrWhitePieceCell(&destination);
            removeBlackOrWhitePieceCell();
        }
    }  
}

bool Board::attackPossible(Cell & start, Cell & destination) {
    if (start.getChessPiece() != nullptr) {
        return start.getChessPiece()->canAttack(start, destination, *this);
    } else {
        return false;
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



