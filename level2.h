#ifndef __LEVEL2_H__
#define __LEVEL2_H__
#include "computer.h"

using namespace std;


class level2 : public Computer {
    public:
    //level 2 will generate will output a capturing/check move if possible and
    //a random move otherwise
    Move generateMove() override;
};

#endif
