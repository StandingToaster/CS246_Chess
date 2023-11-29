#ifndef __LEVEL4_H__
#define __LEVEL4_H__
#include "computer.h"

using namespace std;


class level4 : public Computer {
    public:
    Move generateMove() override;
};

#endif
