#ifndef __MOVE_H__
#define __MOVE_H__
#include "cell.h"



class Move {

    Cell start;
    Cell dest;

public:
    Move();
    Move(Cell & start, Cell & dest);
    Move(const Move& other);
    Move& operator=(const Move& other);
    ~Move();



    //Determines whether the ending cell of the move has a piece in it, if so, it is an enemy and therefore will return true.
    bool hasEnemyPresence();


};







#endif


