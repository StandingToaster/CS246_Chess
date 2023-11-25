#include "board.h"

using namespace std;


Board::Board() {}

Board::~Board() {}

void Board::setBoard() {

    // Resizing the board and each row to be size 8 in length
    board.resize(boardSize);
    for (int i = 0; i < boardSize; i++) {
        board[i].resize(boardSize);
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j].setCoords(i, j);

            if (j % 2 == 0) {
                board[i][j].setColour(Colour::White);
            } else {
                board[i][j].setColour(Colour::Black);
            }
        }
    }


}

ostream& operator<<(ostream &out, const Board &b) {

    for (int i = 0; i < b.boardSize; i++) {
        for (int j = 0; j < b.boardSize; j++) {

            out << b.board[i][j];


        }
        
        out << endl;
    }

    return out;
}



