#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "computer.h"

using namespace std;

class level1 : public Computer {
    public:
    level1(Board* in, Colour cur);
    Move generateMove() override;
};

#endif