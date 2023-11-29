#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include "board.h"
#include "computer.h"

using namespace std;

class Controller {
Board* currentBoard;
Computer* player1;
Computer* player2;
int score1, score2;

public:
Controller(Board* init, Computer* p1, Computer* p2);

//Manages the entire game for its duration. Returns true if the game is quit or ends.
void playGame(istream &in, ostream &out);

~Controller();

};

#endif

