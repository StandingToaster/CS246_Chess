#include "computer.h"

using namespace std;


class level2 : public Computer {
    //Determines whether the given move will result in a kill or not.
     bool checkForKill(Move input);
    public:
    Move generateMove() override;
};
