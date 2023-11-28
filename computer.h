#include <vector>
#include <iostream>
#include <string>
#include "move.h"
using namespace std;
//The Computer Class is an abstract superclass that will allow for subclasses for computer levels to be generated.
class Computer {
Board* current;
public:
Computer(Board* board); 
virtual Move generateMove() = 0;
};