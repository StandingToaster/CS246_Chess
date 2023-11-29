#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include <vector>
#include <iostream>
#include "computer.h"

using namespace std;

class Board {

    friend class Cell;

    // Computer c;
    
    const int boardSize = 8;
    vector<vector<Cell>> theBoard; // the actual chess board

    vector<Cell*> blackPieceCells; // at most 16, cells which hold black pieces
    vector<Cell*> whitePieceCells; // at most 16, cells which hold white pieces

    // a vector of all valid Black moves
    vector<Move> allBlackLegalMoves;
    // a vector of all valid White moves
    vector<Move> allWhiteLegalMoves;
    

    public:
    Board();
    Board(const Board& other);
    ~Board();

    // !!!!!!!      ENSURE IN HARNESS THAT 0 <= X,Y < boardSize      !!!!!!!
    Cell & getCell(int x, int y); 
    int getBoardSize();
    bool cellEmpty(int x, int y); // Empty (true) if there is no chesspiece on it or coordinates are out of bounds

    void setEmptyBoard(); // prepares the board (no chess piece on it yet)
    void setDefaultBoard(); // prepares board with a standard game start

    void setPieceOnBoard(ChessPiece * piece, int x, int y); // Places a chess piece on a specific square of the board.
    void removePieceFromBoard(int x, int y); // Removes chess piece from the specified square 

    void addBlackOrWhitePieceCell(Cell * hasPiece); // adds a cell with a black or white piece to blackPieceCells or whitePieceCells respectively. 
    void removeBlackOrWhitePieceCell(); // removes a cell from blackPieceCells or whitePieceCells if they are no longer carrying a piece.
    void printBlackPieceCells(); // will be removed at the end, used for testing purposes
    void printWhitePieceCells(); // will be removed at the end, used for testign purposes

    void addBlackOrWhiteLegalMove(Move move); // Adds a potential move with a black or white piece to allBlackLegalMoves or allWhiteLegalMoves respectively. 
    void calculateAllLegalMoves(); // gets potential legal moves of all black and white pieces and adds it to their respective vector.
    void clearLegalMoves(); // Clears the vectors for allBlackLegalMoves and allWhiteLegalMoves. Cleared each turn.
    void printBlackLegalMoves(); // will be removed at the end, used for testing purposes
    void printWhiteLegalMoves(); // will be removed at the end, used for testing purposes


    bool activateMove(Cell & start, Cell & destination);
    bool attackPossible(Cell & start, Cell & destination);

    bool checked(Colour kingColour);
    bool checkMated(Colour kingColour);

    vector<Move> getLegalMoves(Colour colour);

    friend ostream& operator<<(ostream &out, const Board &b);

};







#endif


