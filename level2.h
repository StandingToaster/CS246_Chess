#include "computer.h"

using namespace std;


class level2 : public Computer {
    //Creates a vector of all possible moves that will result in a kill.
     vector<Move> checkForKill();
    public:
    Move generateMove() override;
};
