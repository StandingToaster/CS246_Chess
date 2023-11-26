#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Board {

    friend class Cell;


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

    // !!!!!!!      ENSURE IN HARNESS THAT 0 <= X,Y <= 7      !!!!!!!
    Cell & getCell(int x, int y); 
    bool cellEmpty(int x, int y); // Empty (true) if there is no chesspiece on it

    void setEmptyBoard(); // prepares the board (no chess piece on it yet)
    void setDefaultBoard(); // prepares board with a standard game start

    void setPieceOnBoard(ChessPiece * piece, int x, int y); // Places a chess piece on a specific square of the board.
    void removePieceFromBoard(int x, int y); // Removes chess piece from the specified square 

    void activateMove(Cell & start, Cell & destination);


    friend ostream& operator<<(ostream &out, const Board &b);

};



#endif
