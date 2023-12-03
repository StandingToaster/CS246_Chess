#include "controller.h"
#include <sstream>
using namespace std;

Controller::Controller(Board* init, Computer* p1, Computer* p2): currentBoard{init}, player1{p1}, player2{p2}, score1{0}, score2{0} {}

// Controller::~Controller() {
//     delete currentBoard;
//     delete player1;
//     delete player2;
// }

void Controller::convertCoordinates(int &X, int &Y, string input) {
    //Handles the logic for the 'letter' part of the coordinate, sets it to error code -1 if conditions not met.
    if (input[0] == 'a') {
        X = 0;
    }
    else if (input[0] == 'b') {
        X = 1;
    }
    else if (input[0] == 'c') {
        X = 2;
    }
    else if (input[0] == 'd') {
        X = 3;
    }
    else if (input[0] == 'e') {
        X = 4;
    }
    else if (input[0] == 'f') {
        X = 5;
    }
    else if (input[0] == 'g') {
        X = 6;
    }
    else if (input[0] == 'h') {
        X = 7;
    }
    else {
        X = -1;
    }

//Handles the logic for the 'number' part of the coordinate, sets it to error code -1 if conditions not met.
if (input[1] == '8') {
        Y = 0;
    }
    else if (input[1] == '7') {
        Y = 1;
    }
    else if (input[1] == '6') {
        Y = 2;
    }
    else if (input[1] == '5') {
        Y = 3;
    }
    else if (input[1] == '4') {
        Y = 4;
    }
    else if (input[1] == '3') {
        Y = 5;
    }
    else if (input[1] == '2') {
        Y = 6;
    }
    else if (input[1] == '1') {
        Y = 7;
    }
    else {
        Y = -1;
    }

    return;
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
            while (in >> p1) {
                if (p1 == "human") {
                    delete player1;
                    player1 = nullptr;
                    break;
                }

                else if (p1 == "computer1") {
                    delete player1;
                    player1 = new level1(currentBoard, Colour::White);
                    break;
                }

                else if (p1 == "computer2") {
                    delete player1;
                    player1 = new level2(currentBoard, Colour::White);
                    break;
                }

                else if (p1 == "computer3") {
                    delete player1;
                    player1 = new level3(currentBoard, Colour::White);
                    break;
                }

                else if (p1 == "computer4") {
                    delete player1;
                    //player1 = new level4(currentBoard, Colour::White);
                    break;
                }

                else {
                    out << "Please input human or computer[1-4]" << endl;
                }

            }

            while (in >> p2) {
                if (p2 == "human") {
                    delete player2;
                    player2 = nullptr;
                    break;
                }

                else if (p2 == "computer1") {
                      delete player2;
                    player2 = new level1(currentBoard, Colour::Black);
                    break;
                }

                else if (p2 == "computer2") {
                      delete player2;
                    player2 = new level2(currentBoard, Colour::Black);
                    break;
                }

                else if (p2 == "computer3") {
                    delete player2;
                    player2 = new level3(currentBoard, Colour::Black);
                    break;
                }

                else if (p2 == "computer4") {
                      delete player2;
                    //player2 = new level4(currentBoard, Colour::Black);
                    break;
                }

                else {
                    out << "Please input human or computer[1-4]" << endl;
                    continue;
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
            string m1;
            string m2;
            int sx;
            int sy;
            int dx;
            int dy;
            if (currentPlayer == 1) {
            if (player1 == nullptr) {
                cin >> m1;
                cin >> m2;
                convertCoordinates(sx, sy, m1);
                convertCoordinates(dx, dy, m2);
                if (sx == -1 || sy == -1 || dx == -1 || dy == -1) {
                    cout << "Please input valid coordinates: [lowercase letter][1-7]" << endl;
                    continue;
                }
                
            }
            }
        }
        else if (cmd == "setup") {
            //Sets up game as per specifications
        }
        else if (cmd == "-help") {
            //help specifications
        }
        else {
            out << "Invalid input! type -help for a list of commands." << endl;
            continue;
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