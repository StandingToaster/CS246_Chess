#include "controller.h"

using namespace std;

Controller::Controller(Board* init, Computer* p1, Computer* p2): currentBoard{init}, player1{p1}, player2{p2} {}

Controller::~Controller() {
    delete currentBoard;
    delete player1;
    delete player2;
}

bool Controller::playGame(istream &in) {
    
}