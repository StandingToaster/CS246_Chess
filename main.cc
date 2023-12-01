#include <iostream>
#include "board.h"
#include "computer.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

using namespace std;

int main() {    

    Board b;
    b.setDefaultBoard();

    // b.setPieceOnBoard(new Queen(Colour::Black), 1, 3);
    // b.setPieceOnBoard(new King(Colour::Black), 0, 0);

    // b.setPieceOnBoard(new King(Colour::White), 7, 7);
    // b.setPieceOnBoard(new Queen(Colour::White), 1, 1);

    cout << b << endl;
    

    b.calculateAllLegalMoves();
    b.printBlackLegalMoves();
    // cout << b.checkMated(Colour::Black);
    // cout << b.activateMove(b.getCell(1,3), b.getCell(0,4)) << endl << endl;
    
    

    // cout << b << endl;
    // b.printBlackPieceCells();
    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();
    // cout << b.activateMove(b.getCell(2,2), b.getCell(2,0)) << endl << endl;
    // cout  << b << endl;



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
