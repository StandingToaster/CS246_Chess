#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include <vector>
#include <iostream>
#include "computer.h"
#include "window.h"

using namespace std;

class Board {

    friend class Cell;
    
    const int boardSize = 8;

    Xwindow xw;

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

    void setEmptyBoard(); // prepares the board (no chess piece on it yet), or resets it to empty
    void setDefaultBoard(); // prepares board with a standard game start
    void setComputerLevel(int level);

    void setPieceOnBoard(ChessPiece * piece, int x, int y); // Places a chess piece on a specific square of the board.
    void removePieceFromBoard(int x, int y); // Removes chess piece from the specified square 

    void addBlackOrWhitePieceCell(Cell * hasPiece); // adds a cell with a black or white piece to blackPieceCells or whitePieceCells respectively. 
    void removeBlackOrWhitePieceCell(); // removes a cell from blackPieceCells or whitePieceCells if they are no longer carrying a piece.
    void printBlackPieceCells(); // Used for testing purposes
    void printWhitePieceCells(); // Used for testing purposes

    void addBlackOrWhiteLegalMove(Move move); // Adds a potential move with a black or white piece to allBlackLegalMoves or allWhiteLegalMoves respectively. 
    void calculateAllLegalMoves(); // gets potential legal moves of all black and white pieces and adds it to their respective vector.
    void clearLegalMoves(); // Clears the vectors for allBlackLegalMoves and allWhiteLegalMoves. Cleared each turn.
    void printBlackLegalMoves(); // Used for testing purposes
    void printWhiteLegalMoves(); // Used for testing purposes


    bool activateMove(Cell & start, Cell & destination);
    bool attackPossible(Cell & start, Cell & destination);
    void promotePawn(Piece promoteTo);

    bool checked(Colour kingColour);
    bool checkMated(Colour kingColour);
    bool stalemated();

    vector<Move> getLegalMoves(Colour colour);
    vector<Cell*> getOccupiedCells(Colour colour);

    friend ostream& operator<<(ostream &out, const Board &b);

};







#endif


