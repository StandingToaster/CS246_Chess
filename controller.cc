#include "controller.h"
#include <sstream>
using namespace std;

Controller::Controller(Board* init, Computer* p1, Computer* p2): currentBoard{init}, player1{p1}, player2{p2}, score1{0}, score2{0} {}

// Controller::~Controller() {
//     delete currentBoard;
//     delete player1;
//     delete player2;
// }

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
            while (in >> p1) {
                if (p1 == "human") {
                    break;
                }

                else if (p1 == "computer1") {
                    break;
                }

                else if (p1 == "computer2") {
                    break;
                }

                else if (p1 == "computer3") {
                    break;
                }

                else if (p1 == "computer3") {
                    break;
                }

                else {
                    out << "Please input human or computer[1-4]" << endl;
                }

            }

            while (in >> p2) {
                if (p2 == "human") {
                    break;
                }

                else if (p2 == "computer1") {
                    break;
                }

                else if (p2 == "computer2") {
                    break;
                }

                else if (p2 == "computer3") {
                    break;
                }

                else if (p2 == "computer3") {
                    break;
                }

                else {
                    out << "Please input human or computer[1-4]" << endl;
                }

            }
            
            // Create new game, follow specifications
            currentBoard->setDefaultBoard();
            cout << *currentBoard << endl;

            if (p1 == "human" && p2 == "human") {
                humanVsHuman(cin, cout);
            }
            
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
            out << "Invalid input! type -help for a list of commands." << endl;
        }
    }
}




void Controller::humanVsHuman(istream & in, ostream & out) {

    string line;
    Colour currentPlayer = Colour::White; // white always goes first

    while (getline(in, line)) {

        istringstream iss(line);

        string cmd = "";
        string start = "";
        string dest = "";
        string promoteTo = ""; // optional, for pawn promotion
        Piece toPromote;

        iss >> cmd >> start >> dest >> promoteTo;

        if (cmd == "resign") {
            if (currentPlayer == Colour::White) { // white player resigned, black wins
                score2++;
            } else { // black player resigned, white wins
                score1++;
            }
            break;
        }

        else if (cmd == "move") {
            
            // To convert start/dest coordinates to ints, perhaps a <map> could work?
                // Ensure start coordinates are proper, and convert them to integers
                // Ensure dest coordinates are proper, and conver them to integers

            // Ensure promoteTo string is valid with, and convert it into the Piece toPromote. 
            
            out << start << endl;
            out << dest << endl;
            out << promoteTo << endl;

            break;

            

        }
        
        else { // cmd not found
            cout << "Please input a valid command to play the game" << endl;
        }

    }

}