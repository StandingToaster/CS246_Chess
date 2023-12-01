#include <iostream>
#include "board.h"
#include "computer.h"
#include "level1.h"
#include "level2.h"

using namespace std;

int main() {
    // srand((unsigned) time(NULL));
    // int N = 100;

    // for (int i = 0; i < 25; ++i) {
    //     int random = rand() % N;
    //     cout << random << endl;
    // }
    

    Board b;
    b.setEmptyBoard();

    b.setPieceOnBoard(new Rook(Colour::Black), 4, 7);
    b.setPieceOnBoard(new King(Colour::Black), 1, 0);

    b.setPieceOnBoard(new King(Colour::White), 7, 7);
    b.setPieceOnBoard(new Queen(Colour::White), 1, 1);

    cout << b << endl;
    
    // b.calculateAllLegalMoves();
    // // b.printWhiteLegalMoves();

    // Computer * c = new level2(&b, Colour::White);
    // Move test = c->generateMove();

    // cout << test.getStart() << endl;
    // cout << test.getDest() << endl;

    // int sx = test.getStart().getX();
    // int sy = test.getStart().getY();
    // int dx = test.getDest().getX();
    // int dy = test.getDest().getY();

    // cout << "Start: " << "(" << sx << "," << sy << ")" << endl;
    // cout << "Dest: " << "(" << dx << "," << dy << ")" << endl;
    





}
