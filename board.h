#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Board {

    // Computer c;

    const int boardSize = 8;
    vector<vector<Cell>> theBoard; // the actual chess board

    // vector<Cell> whitePieceCells; // at most 16

    // vector<Cell> blackPieceCells; // at most 16

    // vector<Move> allWhiteLegalMoves;
    // vector<Move> allBlackLegalMoves;

    public:
    Board();
    ~Board();

    void setBoard(); // prepares the board (no chess piece on it yet)
    // void setPieceOnBoard(Colour c, ChessPiece * chessP, int x, int y) // Places a chess piece on a specific square of the board.
    // void removePieceFromBoard(int x, int y); // Removes chess piece from the specified square 

    friend ostream& operator<<(ostream &out, const Board &b);

};



#endif
