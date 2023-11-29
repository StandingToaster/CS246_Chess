#include "controller.h"

using namespace std;

Controller::Controller(Board* init, Computer* p1, Computer* p2): currentBoard{init}, player1{p1}, player2{p2}, score1{0}, score2{0} {}

Controller::~Controller() {
    delete currentBoard;
    delete player1;
    delete player2;
}

void Controller::playGame(istream &in, ostream &out) {
    string cmd;
    int currentPlayer = 1;
    while (in >> cmd) {
        if (cmd == "resign" && currentPlayer == 1) {
            //Increment score, output resign message based on colour.
        }
        else if (cmd == "game") {
            string p1;
            string p2;
            in >> p1;
            in >> p2;
            // Create new game, follow specifications
        }
        else if (cmd == "move") {
            //Accomadate for both cpu and humans
        }
        else if (cmd == "setup") {
            //Sets up game as per specifications
        }
        else if (cmd == "-help") {
            //help specifications
        }
        else {
            out << "Invalid input! type -help for a list of commands.";
        }
    }
}