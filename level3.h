#ifndef __LEVEL3_H__
#define __LEVEL3_H__
#include "computer.h"

using namespace std;


class level3 : public Computer {
    public:
    level3(Board* in, Colour cur);
    Move generateMove() override;
};

#endif

