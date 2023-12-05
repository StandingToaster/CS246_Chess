#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include "board.h"
#include "computer.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <sstream>
using namespace std;

class Controller {
Board* currentBoard;
Computer* player1;
Computer* player2;
float score1, score2;

public:
Controller(Board* init);

//Manages the entire game for its duration. Returns true if the game is quit or ends.
void playGame(istream &in, ostream &out);


// ~Controller();

//Converts a string coordinate into integer values.
void convertCoordinates(int &X, int &Y, string input);

//Retrieves White score.
float getScore1();

//Retrieves Black score.
float getScore2();

//Checks whether the cell is occupied, if it is, delete it!.
bool isItOccupied(int & Wking, int & Bking, int & Pawn, int x, int y);

};

#endif

