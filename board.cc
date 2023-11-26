#include "board.h"
#include <iostream>

using namespace std;


Board::Board() {}

Board::~Board() {}


Cell & Board::getCell(int x, int y) {
    return theBoard[y][x];
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
    }

    // Initialize other black pieces
    theBoard[0][0].addChessPiece(new Rook(Colour::Black));
    theBoard[0][1].addChessPiece(new Knight(Colour::Black));
    theBoard[0][2].addChessPiece(new Bishop(Colour::Black));
    theBoard[0][3].addChessPiece(new Queen(Colour::Black));
    theBoard[0][4].addChessPiece(new King(Colour::Black));
    theBoard[0][5].addChessPiece(new Bishop(Colour::Black));
    theBoard[0][6].addChessPiece(new Knight(Colour::Black));
    theBoard[0][7].addChessPiece(new Rook(Colour::Black));

    // Initialize white pawns
    for (int i = 0; i < boardSize; i++) {
        theBoard[6][i].addChessPiece(new Pawn(Colour::White));
    }

    // Initialize other white pieces
    theBoard[7][0].addChessPiece(new Rook(Colour::White));
    theBoard[7][1].addChessPiece(new Knight(Colour::White));
    theBoard[7][2].addChessPiece(new Bishop(Colour::White));
    theBoard[7][3].addChessPiece(new Queen(Colour::White));
    theBoard[7][4].addChessPiece(new King(Colour::White));
    theBoard[7][5].addChessPiece(new Bishop(Colour::White));
    theBoard[7][6].addChessPiece(new Knight(Colour::White));
    theBoard[7][7].addChessPiece(new Rook(Colour::White));

}

void Board::setPieceOnBoard(ChessPiece * piece, int x, int y) {
    if (0 <= x && x <= 7 && 0 <= y && y <= 7) {
        theBoard[y][x].addChessPiece(piece);
    }

}

void Board::removePieceFromBoard(int x, int y) {
    if (0 <= x && x <= 7 && 0 <= y && y <= 7) {
        theBoard[y][x].deleteChessPiece();
    }
}


void Board::activateMove(Cell & start, Cell & destination) {

    if (start.getChessPiece() != nullptr) {
        start.getChessPiece()->movePiece(start, destination, *this);
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



