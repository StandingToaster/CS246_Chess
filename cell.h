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
    ~Cell();
    int getX();
    int getY();
    ChessPiece * getChessPiece();
    // bool compareCells(Cell & c1, Cell & c2);
    void setCoords(int x, int y);
    void setColour(Colour c);
    void addChessPiece(ChessPiece * piece);
    void removeChessPiece();
    void deleteChessPiece();


    // ChessPiece & getChessPiece();

    // void promotePawn(char display);

    friend ostream& operator<<(ostream &out, const Cell &c);

};





#endif

