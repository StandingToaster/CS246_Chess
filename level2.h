#include "computer.h"

using namespace std;


class level2 : public Computer {
    //Determines whether the given move will result in a kill or not.
     bool checkForKill(Move input);
    public:
    //level 2 will generate will output a capturing/check move if possible and
    //a random move otherwise
    Move generateMove() override;
};
