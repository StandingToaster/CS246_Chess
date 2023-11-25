#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>

using namespace std;

enum class Colour { White, Black };

class Cell {

    int x;
    int y;
    Colour colour; // useful when implementing a graphical display
    // ChessPiece * chessP = nullptr

    public:
    Cell(); // default ctor
    ~Cell();
    int getX();
    int getY();
    void setCoords(int x, int y);
    void setColour(Colour c);

    // ChessPiece & getChessPiece();

    // void promotePawn(char display);

    friend ostream& operator<<(ostream &out, const Cell &c);

};





#endif

