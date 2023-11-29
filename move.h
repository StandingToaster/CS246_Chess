#ifndef __MOVE_H__
#define __MOVE_H__
#include "cell.h"



class Move {

    Cell & start;
    Cell & dest;

public:
//Determines whether the ending cell of the move has a piece in it, if so, it is an enemy and therefore will return true.
    Move(Cell & start, Cell & dest);
    Move(const Move& other);
    ~Move();
    bool hasEnemyPresence();
};







#endif


