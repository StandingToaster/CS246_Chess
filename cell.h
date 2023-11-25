#ifndef __CELL_H__
#define __CELL_H__

#include <vector>

enum class Colour { White, Black };

class Cell {

    int x;
    int y;
    Colour colour;
    // ChessPiece * chessP = nullptr

    public:
    Cell(); // default ctor
    ~Cell();
    int getX();
    int getY();
    void setCoords(int x, int y);

    // ChessPiece & getChessPiece();

    // void promotePawn(char display);


};





#endif

