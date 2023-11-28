#include <vector>
#include <iostream>
#include <string>
#include "move.h"
#include "cell.h"
using namespace std;
//The Computer Class is an abstract superclass that will allow for subclasses for computer levels to be generated.
class Computer {
Board* current;
Colour currentColour;
public:
Computer(Board* board, Colour cur); 
virtual Move generateMove() = 0;
};