#ifndef __CHESSPIECE_H__
#define _CHESSPIECE_H_
#include <iostream>


using namespace std;

class Cell;

class Board;

enum class Colour;

class ChessPiece {

    protected:
    Colour colour;
    char display;

    public:
        ChessPiece(Colour colour, char display);
        virtual ~ChessPiece();
        
        virtual bool movePiece(Cell & start, Cell & destination, Board & b) = 0; // pure virtual

        friend ostream& operator<<(ostream &out, const ChessPiece &cp);

};

class Pawn : public ChessPiece {

    int numMoves = 0;

    public:
    Pawn(Colour colour);
    ~Pawn();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

    
};

class Rook : public ChessPiece {

    public:
    Rook(Colour colour);
    ~Rook();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

};

class Knight : public ChessPiece {

    public:
    Knight(Colour colour);
    ~Knight();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

};

class Bishop : public ChessPiece {

    public:
    Bishop(Colour colour);
    ~Bishop();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

};

class Queen : public ChessPiece {

    public:
    Queen(Colour colour);
    ~Queen();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

};

class King : public ChessPiece {

    bool checked = false;

    public:
    King(Colour colour);
    ~King();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;

};



#endif
