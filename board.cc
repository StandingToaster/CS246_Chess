#include "board.h"
#include <iostream>

using namespace std;


Board::Board() {}

Board::~Board() {}

void Board::setBoard() {

    // Resizing the board and each row to be size 8 in length
    theBoard.resize(boardSize);
    for (int i = 0; i < boardSize; i++) {
        theBoard[i].resize(boardSize);
    }

    bool whiteFirst = true;;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            theBoard[i][j].setCoords(i, j);

            if (j % 2 == 0 && whiteFirst) {
                theBoard[i][j].setColour(Colour::White);
            } else if (j % 2 != 0 && whiteFirst) {
                theBoard[i][j].setColour(Colour::Black);
            } else if (j % 2 == 0 && !whiteFirst) {
                theBoard[i][j].setColour(Colour::Black);
            } else {
                theBoard[i][j].setColour(Colour::White);
            }

        
        }
        whiteFirst = !whiteFirst;
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



