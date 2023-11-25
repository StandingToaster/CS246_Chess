#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_
#include "cell.h"

using namespace std;

class ChessPiece {

    protected:
        Colour colour;
    
    public:
        ChessPiece(Colour colour);
        ~ChessPiece();
        
        virtual bool movePiece(Cell & start, Cell & destination) = 0; // pure virtual


};



#endif
