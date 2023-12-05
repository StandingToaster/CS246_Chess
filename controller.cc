#include "controller.h"
#include <sstream>
using namespace std;

Controller::Controller(Board* init): currentBoard{init}, player1{nullptr}, player2{nullptr}, score1{0}, score2{0} {}

// Controller::~Controller() {
//     delete currentBoard;
//     delete player1;
//     delete player2;
// }


bool Controller::isItOccupied(int & Wking, int & Bking, int & Pawn, int x, int y) {
    if(!currentBoard->cellEmpty(x, y)) {
        if (currentBoard->getCell(x, y).getChessPiece()->getPiece() == Piece::King && currentBoard->getCell(x, y).getChessPiece()->getColour() == Colour::Black) {
            --Bking;
        }
        if (currentBoard->getCell(x, y).getChessPiece()->getPiece() == Piece::King && currentBoard->getCell(x, y).getChessPiece()->getColour() == Colour::White) {
            --Wking;
        }
        if (currentBoard->getCell(x, y).getChessPiece()->getPiece() == Piece::Pawn && (y == 0 || y == 7)) {
            --Pawn;
        }
        currentBoard->removePieceFromBoard(x, y);
        return true;
    }
    else {
        return false;
    }
}

float Controller::getScore1() {
    return this->score1;
}

float Controller::getScore2() {
    return this->score2;
}

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
        //TO BE MOVED
        if (!gameEnd && currentBoard->stalemated()) {
            gameEnd = true;
             out << "____________________________" << endl << endl;
            out << "Stalemate!" << endl;
            score1 += 0.5;
            score2 += 0.5;
           out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
             out << "____________________________" << endl << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue; 
        }
        string temp;
        istringstream iss {cmd};
        iss >> temp;
        if (temp == "resign" && !gameEnd) {
            //Increment score, output resign message based on colour.
            //If the current player is white and a human
            if (player1 == nullptr && currentPlayer == 1) {
                gameEnd = true;
                 out << "____________________________" << endl << endl;
                out << "White resigns." << endl;
                out << "Black Wins!" << endl;
                out << "Current score: \n";
                ++score2;
                out << "Black: " << score2 << endl;
                out << "White: " << score1 << endl;
                 out << "____________________________" << endl << endl;
                currentBoard->setEmptyBoard();
                currentPlayer = 0;
                //Add play again message or quit.
                continue;
            }
            //If the current player is black and a human
            else if (player2 == nullptr && currentPlayer == 2) {
                gameEnd = true;
                 out << "____________________________" << endl << endl;
                out << "Black resigns." << endl;
                out << "White Wins!" << endl;
                out << "Current score: \n";
                ++score1;
                out << "Black: " << score2 << endl;
                out << "White: " << score1 << endl;
                 out << "____________________________" << endl << endl;
                currentBoard->setEmptyBoard();
                currentPlayer = 0;
                //Add play again message or quit.
                continue;
            }
            else {
                //If computer is asked to resign
                if (player1 != nullptr && player2 != nullptr) {
                    //If the computer is white.
                    if (currentPlayer == 1) {
                        gameEnd = true;
                         out << "____________________________" << endl << endl;
                        out << "CPU White resigns." << endl;
                        out << "CPU Black wins!" << endl;
                        out << "Current score: \n";
                         ++score2;
                        out << "Black: " << score2 << endl;
                         out << "White: " << score1 << endl;
                          out << "____________________________" << endl << endl;
                            currentBoard->setEmptyBoard();
                            currentPlayer = 0;
                            continue;
                             }
                             //if the computer is black.
                             else if (currentPlayer == 2) {
                               gameEnd = true;
                         out << "____________________________" << endl << endl;
                        out << "CPU Black resigns." << endl;
                        out << "CPU White wins!" << endl;
                        out << "Current score: \n";
                         ++score1;
                        out << "Black: " << score2 << endl;
                         out << "White: " << score1 << endl;
                          out << "____________________________" << endl << endl;
                            currentBoard->setEmptyBoard();
                            currentPlayer = 0;
                            continue; 
                             }
                }
                //Error handling.
                gameEnd = false;
                 out << "____________________________" << endl << endl;
                out << "You cannot resign yet!" << endl;
                out << "Type -help for a list of commands" << endl;
                 out << "____________________________" << endl << endl;
                continue;
            }
        }
        //Begin to setup game.
        else if (temp == "game" && gameEnd) {
            string p1;
            string p2;
            //Read in White-Player
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
                     out << "____________________________" << endl << endl;
                    out << "Please input human or computer[1-4]" << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
            }
            //Read in Black-Player
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
                     out << "____________________________" << endl << endl;
                    out << "Please input human or computer[1-4]" << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
            }

            if (p2 == "") {
                 out << "____________________________" << endl << endl;
                out << "Please input human or computer[1-4]" << endl;
                 out << "____________________________" << endl << endl;
                    continue; 
            }

            // Create new game, follow specifications
            currentBoard->setDefaultBoard();
            out << *currentBoard << endl;
                gameEnd = false;
                currentPlayer = 1;
            
        }
        //Move a piece
        else if (temp == "move" && !gameEnd) {
            //Accomadate for both cpu and humans
            string m1;
            string m2;
            int sx;
            int sy;
            int dx;
            int dy;
            //If the current player is white.
            if (currentPlayer == 1) {
                //If the player is human.
            if (player1 == nullptr && iss >> m1 && iss >> m2) {
                //handle pawn promotion
                string m3;
                convertCoordinates(sx, sy, m1);
                convertCoordinates(dx, dy, m2);
                if (sx == -1 || sy == -1 || dx == -1 || dy == -1) {
                     out << "____________________________" << endl << endl;
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
                bool notFailBit = currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                //If move succeeded.
                if (notFailBit) {
                     if (iss >> m3) {
                    if (m3 == "Q" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Queen);
                    }
                    else if (m3 == "B" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Bishop);
                    }
                    else if (m3 == "N" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Knight);
                    }
                    else if (m3 == "R" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Rook);
                    }
                    else {
                         out << "____________________________" << endl << endl;
                        out << "Pawn promotion failed! Try again." << endl;
                        out << *currentBoard << endl;
                         out << "____________________________" << endl << endl;
                         continue;
                    }
                }
                    //Check for checkmate.
                     if (currentBoard->checkMated(Colour::Black)) {
            gameEnd = true;
             out << "____________________________" << endl << endl;
            out << "Checkmate! White wins!" << endl;
            score1++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
             out << "____________________________" << endl << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
                    //Check for checked.
                     if (currentPlayer == 1 && currentBoard->checked(Colour::Black)) {
                         out << "____________________________" << endl << endl;
            out << "Black is in check." << endl;
             out << "____________________________" << endl << endl;
                     }
                     currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                currentPlayer = 2;
                 out << "____________________________" << endl << endl;
                out << *currentBoard << endl;
                out << "Black's turn." << endl;
                 out << "____________________________" << endl << endl;
                }
                else {
                     out << "____________________________" << endl << endl;
                    out << "This move is invalid. Try again!" << endl << "-help for list of commands" << endl;
                     out << "____________________________" << endl << endl;
                }
                continue;
            }
            //Error handling.
            else {
                if (player1 == nullptr) {
                     out << "____________________________" << endl << endl;
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                     out << "____________________________" << endl << endl;
                    continue; 
                }
                //AI Moves for white player
                Move temp = player1->generateMove();
                sx = temp.getStart().getX();
                sy = temp.getStart().getY();
                dx = temp.getDest().getX();
                dy = temp.getDest().getY();
                currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                currentBoard->promotePawn(Piece::Queen);
                 currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                //Check for checkmate.
                 if (currentBoard->checkMated(Colour::Black)) {
            gameEnd = true;
             out << "____________________________" << endl << endl;
            out << "Checkmate! White wins!" << endl;
            score1++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
             out << "____________________________" << endl << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
                //Check for check.
                 if (currentBoard->checked(Colour::Black)) {
                     out << "____________________________" << endl << endl;
            out << "Black is in check." << endl;
             out << "____________________________" << endl << endl;
                     }
                currentPlayer = 2;
                 out << "____________________________" << endl << endl;
                out << *currentBoard << endl;
                out << "Black's turn." << endl;
                 out << "____________________________" << endl << endl;
                continue;
            }
            }
            else {
                //Move for black. If the player is a human.
               if (player2 == nullptr && iss >> m1 && iss >> m2) {
                string m3;
                convertCoordinates(sx, sy, m1);
                convertCoordinates(dx, dy, m2);
                if (sx == -1 || sy == -1 || dx == -1 || dy == -1) {
                     out << "____________________________" << endl << endl;
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
                bool notFailBit = currentBoard->activateMove(currentBoard->getCell(sx, sy), currentBoard->getCell(dx, dy));
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                //Checks for checkmate.
                if (notFailBit) {
                      if (iss >> m3) {
                    if (m3 == "q" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Queen);
                    }
                    else if (m3 == "b" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Bishop);
                    }
                    else if (m3 == "n" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Knight);
                    }
                    else if (m3 == "r" && (dy == 0 || dy == 7)) {
                        currentBoard->promotePawn(Piece::Rook);
                    }
                    else {
                         out << "____________________________" << endl << endl;
                        out << "Pawn promotion failed! Try again." << endl;
                         out << "____________________________" << endl << endl;
                        out << *currentBoard << endl;
                         out << "____________________________" << endl << endl;
                         continue;
                    }
                }
                    if (currentBoard->checkMated(Colour::White)) {
            gameEnd = true;
             out << "____________________________" << endl << endl;
            out << "Checkmate! Black wins!" << endl;
            score2++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
             out << "____________________________" << endl << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
        //Check for check.
        if (currentBoard->checked(Colour::White)) {
             out << "____________________________" << endl << endl;
            out << "White is in check." << endl;
             out << "____________________________" << endl << endl;
        }
        currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                currentPlayer = 1;
                 out << "____________________________" << endl << endl;
                out << *currentBoard << endl;
                out << "White's turn." << endl;
                 out << "____________________________" << endl << endl;
                }
                else {
                     out << "____________________________" << endl << endl;
                    out << "This move is invalid. Try again!" << endl << "-help for list of commands" << endl;
                     out << "____________________________" << endl << endl;
                }
                continue;
            }
            //AI is Black.
            else {
                if (player2 == nullptr) {
                     out << "____________________________" << endl << endl;
                    out << "Please input valid coordinates: [a-h][1-7]" << endl;
                     out << "____________________________" << endl << endl;
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
                currentBoard->promotePawn(Piece::Queen);
                currentBoard->clearLegalMoves();
                currentBoard->calculateAllLegalMoves();
                if (currentBoard->checkMated(Colour::White)) {
            gameEnd = true;
             out << "____________________________" << endl << endl;
            out << "Checkmate! Black wins!" << endl;
            score2++;
            out << "Current score: \n";
            out << "Black: " << score2 << endl;
            out << "White: " << score1 << endl;
             out << "____________________________" << endl << endl;
            currentBoard->setEmptyBoard();
            currentPlayer = 0;
            continue;
        }
        if (currentBoard->checked(Colour::White)) {
             out << "____________________________" << endl << endl;
            out << "White is in check." << endl;
             out << "____________________________" << endl << endl;
                  }
                currentPlayer = 1;
                 out << "____________________________" << endl << endl;
                out << *currentBoard << endl;
                out << "White's turn." << endl;
                 out << "____________________________" << endl << endl;
                continue;
            }
            }
        }
            //Displays status.
        else if (temp == "status") {
            string play1 = "";
            string play2 = "";
            if (player1 == nullptr) {
                play1 = "human";
            }
            else {
                play1 = "computer";
            }
            if (player2 == nullptr) {
                play2 = "human";
            }
            else {
                play2 = "computer";
            }
             out << "____________________________" << endl << endl;
            out << "White: The current score is " << score1 << " and is currently a " << play1 << "." << endl;
            out << "Black: The current score is " << score2 << " and is currently a " << play2 <<  "." << endl;
             out << "____________________________" << endl << endl;
        }
        //SETUP
        else if (temp == "setup" && gameEnd) {
            //Sets up game as per specifications
            currentBoard->setEmptyBoard();
            currentBoard->clearLegalMoves();
            //input bit
            string SetupTemp;
            //Tracks no. Kings on the Board.
            int numWhiteKings = 0;
            int numBlackKings = 0;
            //Tracks no. of illegal pawn placements.
            int pawnAtEnd = 0;
            //Pulls line by line
            while (getline(in, SetupTemp)) {    
                istringstream iiss {SetupTemp};
                string cmd;
                iiss >> cmd;
                //If add new piece
                if (cmd == "+") {
                    string piece;
                    int dx;
                    int dy;
                    string coord;
                    if (iiss >> piece && iiss >> coord) {
                        this->convertCoordinates(dx, dy, coord);
                        if (dx == -1 || dy == -1) {
                             out << "____________________________" << endl << endl;
                            out << "Incorrect coordinates! Type -help for a list of commands." << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        if (piece == "K") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new King{Colour::White}, dx, dy);
                            ++numWhiteKings;
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "k") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new King{Colour::Black}, dx, dy);
                            ++numBlackKings;
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "Q") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Queen{Colour::White}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "q") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Queen{Colour::Black}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "N") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Knight{Colour::White}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "n") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Knight{Colour::Black}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "B") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Bishop{Colour::White}, dx ,dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "b") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Bishop{Colour::Black}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "R") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Rook{Colour::White}, dx, dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "r") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Rook{Colour::Black}, dx ,dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                        else if (piece == "P") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Pawn{Colour::White}, dx ,dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            if (dy == 0 || dy == 7) {
                                ++pawnAtEnd;
                            }
                            continue;
                        }
                        else if (piece == "p") {
                            isItOccupied(numWhiteKings, numBlackKings, pawnAtEnd, dx, dy);
                            currentBoard->setPieceOnBoard(new Pawn{Colour::Black}, dx , dy);
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            if (dy == 0 || dy == 7) {
                                ++pawnAtEnd;
                            }
                            continue;
                        }
                        else {
                            out << "____________________________" << endl << endl;
                            out << "Incorrect piece type." << endl;
                            out << "[P, B, R, N, Q, K] for White-Player" << endl;
                            out << "[p, b, r, n, q, k] for Black-Player" << endl;
                            out << "Type -help for a list of commands." << endl;
                            out << "____________________________" << endl << endl;
                            continue;
                        }
                    }
                    else {
                        out << "____________________________" << endl << endl;
                        out << "Unknown input. Try again." << endl;
                        out << "____________________________" << endl << endl;
                        continue;
                    }
                }
                //If remove a piece.
                else if (cmd == "-") {
                    string coord;
                    int dx;
                    int dy;
                    if (iiss >> coord) {
                        this->convertCoordinates(dx, dy, coord);
                        if (dx == -1 || dy == -1) {
                             out << "____________________________" << endl << endl;
                           out << "Incorrect coordinates! Type -help for a list of commands." << endl;
                            out << "____________________________" << endl << endl;
                            continue; 
                        }
                        else if (currentBoard->cellEmpty(dx, dy)) {
                             out << "____________________________" << endl << endl;
                            out << "This cell is empty! Try again." << endl;
                             out << "____________________________" << endl << endl;
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
                             out << "____________________________" << endl << endl;
                            out <<*currentBoard << endl;
                             out << "____________________________" << endl << endl;
                            
                            continue;
                        }
                    }
                    else {
                         out << "____________________________" << endl << endl;
                        out << "Incorrect format to remove a piece. Follow - [letter][number]" << endl;
                        out << "Type -help for a list of commands." << endl;
                         out << "____________________________" << endl << endl;
                        continue;
                    }
                }
                else if (cmd == "-help") {
                    //add help.
                     out << "____________________________" << endl << endl;
                    out << "*Welcome to the Setup Mode Manual*" << endl;
                    out << " + [piece] [coordinate] : Adds a piece to the board." << endl;
                    out << " - [coordinate] : Removes a piece from the board." << endl;
                    out << " = [colour] : Set the current player to its appropriate colour." << endl;
                    out << "done : Exits setup mode." << endl;
                    out << "*END OF SETUP HELP*" << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
                //If set current player.
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
                             out << "____________________________" << endl << endl;
                            out << "Incorrect colour. Input black or white." << endl;
                             out << "____________________________" << endl << endl;
                            continue;
                        }
                    }
                    else {
                         out << "____________________________" << endl << endl;
                        out << "Incorect format to set current player. Follow = [colour]" << endl;
                        out << "Type -help for a list of commands." << endl;
                         out << "____________________________" << endl << endl;
                        continue;
                    }
                }
                //DONE IS CAUSING ERRORS
                //Break out of setup
                else if (cmd == "done") {
                    // currentBoard->clearLegalMoves();
                    // currentBoard->calculateAllLegalMoves();


                    //REVIEW THESE CHECKS
                    if (!(numBlackKings == 1 && numWhiteKings == 1) || pawnAtEnd > 0 || currentBoard->checked(Colour::White) || currentBoard->checked(Colour::Black)) {
                         out << "____________________________" << endl << endl;
                        out << "Conditions not satisfied to begin game. The board will be reset." << endl;
                        out << "Type -help for a list of commands." << endl;
                         out << "____________________________" << endl << endl;
                        currentBoard->setEmptyBoard();
                         out << "____________________________" << endl << endl;
                        out <<*currentBoard << endl;
                         out << "____________________________" << endl << endl;
                        pawnAtEnd = 0;
                        numBlackKings = 0;
                        numWhiteKings = 0;
                        currentBoard->clearLegalMoves();
                        continue;
                    }
                    else {
                         out << "____________________________" << endl << endl;
                        cout << "SUCCESSFUL" << endl;
                         out << "____________________________" << endl << endl;
                        out <<*currentBoard << endl;
                         out << "____________________________" << endl << endl;
                        gameEnd = false;
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        }
                        player1 = nullptr;
                        player2 = nullptr;
                        break;
                    }
                }
                //ERROR HANDLING
                else {
                     out << "____________________________" << endl << endl;
                    out << "Invalid input! Type -help for a list of commands." << endl;
                     out << "____________________________" << endl << endl;
                    continue;
                }
            }

        }
        else if (temp == "-help") {
            //help specifications
            out << "____________________________" << endl << endl;
            out << "**Welcome to the CS246 Chess Project Manual**" << endl;
            out << "Created by Harsimran Kalsi, Hirav Thakur, Jinil Panawala." << endl;
            out << "Game is as is! It will have no more releases." << endl;
            out << "game [player1] [player2] : Creates a default game between White-Player and Black-Player." << endl;
            out << "player[1-2] can be human or computer[1-4]." << endl;
            out << "move [start coordinate] [end coordinate] : Moves a piece for humans." << endl;
            out << "move : Moves a piece for Computer." << endl;
            out << "setup : Enters setup mode." << endl;
            out << "status : Check the game's status." << endl;
            out << "**END OF HELP**" << endl;
            out << "____________________________" << endl << endl;
            continue;
        }
        else {
            out << "____________________________" << endl << endl;
            out << "Invalid input! type -help for a list of commands." << endl;
             out << "____________________________" << endl << endl;
            continue;
        }
    }
}
