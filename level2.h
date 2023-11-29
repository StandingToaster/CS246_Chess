#include "computer.h"

using namespace std;


class level2 : public Computer {
     vector<Move> checkForKill();
    public:
    Move generateMove() override;
};
