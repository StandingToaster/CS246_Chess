#ifndef __LEVEL1_H__
#define __LEVEL1_H__
#include "computer.h"

using namespace std;

class level1 : public Computer {
    public:
    Move generateMove() override;
};

#endif