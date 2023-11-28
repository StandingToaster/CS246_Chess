#include "computer.h"

using namespace std;

class level1 : public Computer {
    public:
    Move generateMove() override;
};