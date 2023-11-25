#ifndef _PAWN_H_
#define _PAWN_H_
#include "chesspiece.h"

using namespace std;

class Pawn : public ChessPiece {

    char display;
    // bool firstMove = true // initially always true

    public:
    Pawn(Colour colour);
    ~Pawn();

    bool movePiece (Cell & start, Cell & destination) override;


};



#endif
