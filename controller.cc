#include "controller.h"
#include <sstream>
using namespace std;

Controller::Controller(Board* init): currentBoard{init}, player1{nullptr}, player2{nullptr}, score1{0}, score2{0} {}

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
    bool gameEnd = true;
    string cmd;
    int currentPlayer = 0;
    while (getline(in, cmd)) {
        if (!gameEnd && currentBoard->stalemated()) {
            gameEnd = true;
            out << "Stalemate!" << endl;
            score1 += 0.5;
            score2 += 0.5;
           out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue; 
        }
        if (currentPlayer == 1 && currentBoard->checkMated(Colour::White) && !gameEnd) {
            gameEnd = true;
            out << "Checkmate! Black wins!" << endl;
            score2++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
        if (currentPlayer == 2 && currentBoard->checkMated(Colour::Black) && !gameEnd) {
            gameEnd = true;
            out << "Checkmate! White wins!" << endl;
            score1++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
        string temp;
        istringstream iss {cmd};
        iss >> temp;
        if (temp == "resign" && !gameEnd) {
            //Increment score, output resign message based on colour.
            if (player1 == nullptr && currentPlayer == 1) {
                gameEnd = true;
                out << "White resigns." << endl;
                out << "Black Wins!" << endl;
                out << "Current score: \n";
                ++score2;
                out << "Black: " << score2 << endl;
                out << "White: " << score1 << endl;
                currentBoard->setEmptyBoard();
                currentPlayer = 0;
                //Add play again message or quit.
                continue;
            }
            else if (player2 == nullptr && currentPlayer == 2) {
                gameEnd = true;
                out << "Black resigns." << endl;
                out << "White Wins!" << endl;
                out << "Current score: \n";
                ++score1;
                out << "Black: " << score2 << endl;
                out << "White: " << score1 << endl;
                currentBoard->setEmptyBoard();
                currentPlayer = 0;
                //Add play again message or quit.
                continue;
            }
            else {
                if (player1 != nullptr && player2 != nullptr) {
                    if (currentPlayer == 1) {
                        gameEnd = true;
                        out << "CPU White resigns." << endl;
                        out << "CPU Black wins!" << endl;
                        out << "Current score: \n";
                         ++score2;
                        out << "Black: " << score2 << endl;
                         out << "White: " << score1 << endl;
                            currentBoard->setEmptyBoard();
                            currentPlayer = 0;
                            continue;
                             }
                             else if (currentPlayer == 2) {
                               gameEnd = true;
                        out << "CPU Black resigns." << endl;
                        out << "CPU White wins!" << endl;
                        out << "Current score: \n";
                         ++score1;
                        out << "Black: " << score2 << endl;
                         out << "White: " << score1 << endl;
                            currentBoard->setEmptyBoard();
                            currentPlayer = 0;
                            continue; 
                             }
                }
                gameEnd = false;
                out << "You cannot resign yet!" << endl;
                out << "Type -help for a list of commands" << endl;
                continue;
            }
        }
        else if (temp == "game" && gameEnd) {
            string p1;
            string p2;
            if (iss >> p1) {
                if (p1 == "human") {
                    //delete player1;
                    player1 = nullptr;
                }

                else if (p1 == "computer1") {
                   // delete player1;
                    player1 = new level1(currentBoard, Colour::White);
                }

                else if (p1 == "computer2") {
                   //delete player1;
                    player1 = new level2(currentBoard, Colour::White);
                }

                else if (p1 == "computer3") {
                    //delete player1;
                    player1 = new level3(currentBoard, Colour::White);
                }

                else if (p1 == "computer4") {
                    //delete player1;
                    //player1 = new level4(currentBoard, Colour::White);
                }
                else {
                    out << "Please input human or computer[1-4]" << endl;
                    continue;
                }
            }
            if (iss >> p2) {
                if (p2 == "human") {
                    //delete player2;
                    player2 = nullptr;
                }

                else if (p2 == "computer1") {
                      //delete player2;
                    player2 = new level1(currentBoard, Colour::Black);
                }

                else if (p2 == "computer2") {
                      //delete player2;
                    player2 = new level2(currentBoard, Colour::Black);
                }

                else if (p2 == "computer3") {
                   // delete player2;
                    player2 = new level3(currentBoard, Colour::Black);
                }

                else if (p2 == "computer4") {
                      //delete player2;
                    //player2 = new level4(currentBoard, Colour::Black);
                }

                else {
                    out << "Please input human or computer[1-4]" << endl;
                    continue;
                }
            }

            if (p2 == "") {
                out << "Please input human or computer[1-4]" << endl;
                    continue; 
            }

            // Create new game, follow specifications
            currentBoard->setDefaultBoard();
            out << *currentBoard << endl;
                gameEnd = false;
                currentPlayer = 1;
            if (p1 == "human" && p2 == "human") {
                humanVsHuman(in, out);
            }
            
        }
        else if (temp == "move" && !gameEnd) {
            //Accomadate for both cpu and humans
            string m1;
            string m2;
            int sx;
            int sy;
            int dx;
            int dy;
            if (currentPlayer == 1) {
            if (player1 == nullptr && iss >> m1 && iss >> m2) {
                convertCoordinates(sx, sy, m1);
                convertCoordinates(dx, dy, m2);
                if (sx == -1 || sy == -1 || dx == -1 || dy == -1) {
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                    continue;
                }
                bool notFailBit = currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                if (notFailBit) {
                     if (currentPlayer == 1 && currentBoard->checked(Colour::White) && !gameEnd) {
            out << "White is in check." << endl;
                     }
                currentPlayer = 2;
                out << *currentBoard << endl;
                }
                else {
                    out << "This move is invalid. Try again!" << endl << "-help for list of commands" << endl;
                }
                continue;
            }
            else {
                if (player1 == nullptr) {
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                    continue; 
                }
                Move temp = player1->generateMove();
                sx = temp.getStart().getX();
                sy = temp.getStart().getY();
                dx = temp.getDest().getX();
                dy = temp.getDest().getY();
                currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                 if (currentPlayer == 1 && currentBoard->checked(Colour::White) && !gameEnd) {
            out << "White is in check." << endl;
                     }
                currentPlayer = 2;
                out << *currentBoard << endl;
                continue;
            }
            }
            else {
               if (player2 == nullptr && iss >> m1 && iss >> m2) {
                convertCoordinates(sx, sy, m1);
                convertCoordinates(dx, dy, m2);
                if (sx == -1 || sy == -1 || dx == -1 || dy == -1) {
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                    continue;
                }
                bool notFailBit = currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                if (notFailBit) {
        if (currentPlayer == 2 && currentBoard->checked(Colour::Black) && !gameEnd) {
            out << "Black is in check." << endl;
        }
                currentPlayer = 1;
                out << *currentBoard << endl;
                }
                else {
                    out << "This move is invalid. Try again!" << endl << "-help for list of commands" << endl;
                }
                continue;
            }
            else {
                if (player2 == nullptr) {
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                    continue; 
                }
                Move temp = player2->generateMove();
                sx = temp.getStart().getX();
                sy = temp.getStart().getY();
                dx = temp.getDest().getX();
                dy = temp.getDest().getY();
                currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
        if (currentPlayer == 2 && currentBoard->checked(Colour::Black) && !gameEnd) {
            out << "Black is in check." << endl;
                  }
                currentPlayer = 1;
                out << *currentBoard << endl;
                continue;
            }
            }
        }
        else if (temp == "setup" && gameEnd) {
            //Sets up game as per specifications
            currentBoard->setEmptyBoard();
            currentBoard->clearLegalMoves();
            string SetupTemp;
            int numWhiteKings;
            int numBlackKings;
            int pawnAtEnd;
            while (getline(in, SetupTemp)) {    
                istringstream iiss {SetupTemp};
                string cmd;
                iiss >> cmd;
                if (cmd == "+") {
                    string piece;
                    int dx;
                    int dy;
                    string coord;
                    if (iiss >> piece && iiss >> coord) {
                        this->convertCoordinates(dx, dy, coord);
                        if (dx == -1 || dy == -1) {
                            out << "Incorrect coordinates! Type -help for a list of commands." << endl;
                            continue;
                        }
                        if (piece == "K") {
                            currentBoard->setPieceOnBoard(new King{Colour::White}, dx, dy);
                            ++numWhiteKings;
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "k") {
                            currentBoard->setPieceOnBoard(new King{Colour::Black}, dx, dy);
                            ++numBlackKings;
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "Q") {
                            currentBoard->setPieceOnBoard(new Queen{Colour::White}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "q") {
                            currentBoard->setPieceOnBoard(new Queen{Colour::Black}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "N") {
                            currentBoard->setPieceOnBoard(new Knight{Colour::White}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "n") {
                            currentBoard->setPieceOnBoard(new Knight{Colour::Black}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "B") {
                            currentBoard->setPieceOnBoard(new Bishop{Colour::White}, dx ,dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "b") {
                            currentBoard->setPieceOnBoard(new Bishop{Colour::Black}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "R") {
                            currentBoard->setPieceOnBoard(new Rook{Colour::White}, dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "r") {
                            currentBoard->setPieceOnBoard(new Rook{Colour::Black}, dx ,dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                        else if (piece == "P") {
                            currentBoard->setPieceOnBoard(new Pawn{Colour::White}, dx ,dy);
                            out <<*currentBoard << endl;
                            if (dy == 0 || dy == 7) {
                                ++pawnAtEnd;
                            }
                            continue;
                        }
                        else if (piece == "p") {
                            currentBoard->setPieceOnBoard(new Pawn{Colour::Black}, dx , dy);
                            out <<*currentBoard << endl;
                            if (dy == 0 || dy == 7) {
                                ++pawnAtEnd;
                            }
                            continue;
                        }
                        else {
                            out << "Incorrect piece type." << endl;
                            out << "[P, B, R, N, Q, K] for White-Player" << endl;
                            out << "[p, b, r, n, q, k] for Black-Player" << endl;
                            out << "Type -help for a list of commands." << endl;
                            continue;
                        }
                    }
                    else {
                        out << "Unknown input. Try again." << endl;
                        continue;
                    }
                }
                else if (cmd == "-") {
                    string coord;
                    int dx;
                    int dy;
                    if (iiss >> coord) {
                        this->convertCoordinates(dx, dy, coord);
                        if (dx == -1 || dy == -1) {
                           out << "Incorrect coordinates! Type -help for a list of commands." << endl;
                            continue; 
                        }
                        else if (currentBoard->cellEmpty(dx, dy)) {
                            out << "This cell is empty! Try again." << endl;
                            continue;
                        }
                        else {
                            if (currentBoard->getCell(dx, dy).getChessPiece()->getPiece() == Piece::King && currentBoard->getCell(dx, dy).getChessPiece()->getColour() == Colour::Black) {
                                --numBlackKings;
                            }
                            if (currentBoard->getCell(dx, dy).getChessPiece()->getPiece() == Piece::King && currentBoard->getCell(dx, dy).getChessPiece()->getColour() == Colour::White) {
                                --numWhiteKings;
                            }
                            if ((dy == 0 || dy == 7) && currentBoard->getCell(dx,dy).getChessPiece()->getPiece() == Piece::Pawn) {
                                --pawnAtEnd;
                            }
                            currentBoard->removePieceFromBoard(dx, dy);
                            out <<*currentBoard << endl;
                            continue;
                        }
                    }
                    else {
                        out << "Incorrect format to remove a piece. Follow - [letter][number]" << endl;
                        out << "Type -help for a list of commands." << endl;
                        continue;
                    }
                }
                else if (cmd == "-help") {
                    //add help.
                }
                else if (cmd == "=") {
                    string colour;
                    if (iss >> colour) {
                        if (colour == "black") {
                            currentPlayer = 2;
                            continue;
                        }
                        else if (colour == "white") {
                            currentPlayer = 1;
                            continue;
                        }
                        else {
                            out << "Incorrect colour. Input black or white." << endl;
                            continue;
                        }
                    }
                    else {
                        out << "Incorect format to set current player. Follow = [colour]" << endl;
                        out << "Type -help for a list of commands." << endl;
                        continue;
                    }
                }
                else if (cmd == "done") {
                    currentBoard->clearLegalMoves();
                    currentBoard->calculateAllLegalMoves();
                    if (!(numBlackKings == 1 && numWhiteKings == 1) || pawnAtEnd > 0 || currentBoard->checked(Colour::White) || currentBoard->checked(Colour::Black)) {
                        out << "Conditions not satisfied to begin game. The board will be reset." << endl;
                        out << "Type -help for a list of commands." << endl;
                        currentBoard->setEmptyBoard();
                        out <<*currentBoard << endl;
                        pawnAtEnd = 0;
                        numBlackKings = 0;
                        numWhiteKings = 0;
                        currentBoard->clearLegalMoves();
                        continue;
                    }
                    else {
                        out <<*currentBoard << endl;
                        gameEnd = false;
                        break;
                    }
                }
                else {
                    out << "Invalid input! Type -help for a list of commands." << endl;
                    continue;
                }
            }
            
        }
        else if (temp == "-help") {
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