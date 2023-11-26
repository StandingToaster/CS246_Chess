#ifndef __CHESSPIECE_H__
#define _CHESSPIECE_H_
#include <iostream>


using namespace std;

class Cell;

enum class Colour;

class ChessPiece {

    protected:
    Colour colour;
    char display;

    public:
        ChessPiece(Colour colour, char display);
        virtual ~ChessPiece();
        
        virtual bool movePiece(Cell & start, Cell & destination) = 0; // pure virtual

        friend ostream& operator<<(ostream &out, const ChessPiece &cp);

};

class Pawn : public ChessPiece {

    // bool firstMove = true // initially always true

    public:
    Pawn(Colour colour);
    ~Pawn();

    bool movePiece(Cell & start, Cell & destination) override;

    
};




#endif
