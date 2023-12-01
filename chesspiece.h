#ifndef __CHESSPIECE_H__
#define _CHESSPIECE_H_
#include <iostream>


using namespace std;

class Cell;

class Board;

enum class Colour;

enum class Piece;

class ChessPiece {

    protected:
    Colour colour;
    Piece piece;
    char display;
    
    public:
        ChessPiece(Colour colour, Piece piece, char display);
        ChessPiece(const ChessPiece& other);
        ChessPiece& operator=(const ChessPiece& other);

        virtual ~ChessPiece();
        
        Colour getColour();
        Piece getPiece();
        // moves a piece based on the type of piece and its associated rules.
        virtual bool movePiece(Cell & start, Cell & destination, Board & b) = 0; // pure virtual

        // Determines simply if a piece on the start cell can attack a piece on the destination cell.
        virtual bool canAttack(Cell & start, Cell & destination, Board & b) = 0; // pure virtual

        // Determines all legal moves for a piece located on the start cell and adds them to the list
        // of 
        virtual void determineLegalMoves(Cell & start, Board & b) = 0; // pure virtual

        friend ostream& operator<<(ostream &out, const ChessPiece &cp);

};

class Pawn : public ChessPiece {

    int numMoves = 0;

    public:
    Pawn(Colour colour);
    Pawn(const Pawn& other);
    Pawn& operator=(const Pawn& other);
    ~Pawn();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
    
};

class Rook : public ChessPiece {
    int numMoves = 0;
    public:
    Rook(Colour colour);
    Rook(const Rook& other);
    Rook& operator=(const Rook& other);
    ~Rook();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
};

class Knight : public ChessPiece {

    public:
    Knight(Colour colour);
    Knight(const Knight& other);
    Knight& operator=(const Knight& other);
    ~Knight();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
};

class Bishop : public ChessPiece {

    public:
    Bishop(Colour colour);
    Bishop(const Bishop& other);
    Bishop& operator=(const Bishop& other);
    ~Bishop();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
};

class Queen : public ChessPiece {

    public:
    Queen(Colour colour);
    Queen(const Queen& other);
    Queen& operator=(const Queen& other);
    ~Queen();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
};

class King : public ChessPiece {

    int numMoves = 0;

    public:
    King(Colour colour);
    King(const King& other);
    King& operator=(const King& other);
    ~King();

    bool movePiece(Cell & start, Cell & destination, Board & b) override;
    bool canAttack(Cell & start, Cell & destination, Board & b) override;
    void determineLegalMoves(Cell & start, Board & b) override;
};



#endif
