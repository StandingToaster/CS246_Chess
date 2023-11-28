#include <vector>
#include <iostream>
#include <string>
#include "move.h"
using namespace std;
//The Computer Class is an abstract superclass that will allow for subclasses for computer levels to be generated.
class Computer {
Board* current;
public:
virtual Move generateMove(Board * b) = 0;
virtual ~Computer() = 0;
};