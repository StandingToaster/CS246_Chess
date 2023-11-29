#ifndef __COMPUTER_H__
#define __COMPUTER_H__
#include <vector>
#include <iostream>
#include <string>
#include "move.h"
#include "cell.h"
#include "board.h"
#include <cstdlib> 

using namespace std;
//The Computer Class is an abstract superclass that will allow for subclasses for computer levels to be generated.
class Computer {
Board* current;
Colour currentColour;
public:
Computer(Board* board, Colour cur); 
//generates the next legal move for the computer system.
virtual Move generateMove() = 0;
//Accesses the colour field.
Colour getColour();
//Accesses the pointer pointing to the current board field.
Board* getPointer();


};

#endif