#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include "chesspiece.h"

using namespace std;


enum class Colour { White, Black };
enum class Piece {Pawn, Rook, Knight, Bishop, Queen, King};

class Cell {
    
    int x;
    int y;
    Colour colour; // useful when implementing a graphical display
    ChessPiece * piece = nullptr;

    public:
    Cell(); // default ctor
    Cell(const Cell& other); // copy ctor
    Cell& operator=(const Cell& other); // copy assignment
    ~Cell();
    int getX();
    int getY();
    ChessPiece * getChessPiece();
    void setCoords(int x, int y); // sets x, y coordinates of this cell
    void setColour(Colour c); 
    void addChessPiece(ChessPiece * piece); // adds a chess piece to this cell, deletes the currently residing chess piece.
    void removeChessPiece(); // simply sets piece to nullptr
    void deleteChessPiece(); // deletes piece

    friend ostream& operator<<(ostream &out, const Cell &c); // outputs the display of the chess piece, or " " if colour is white, and "_" if colour is black 

};





#endif

