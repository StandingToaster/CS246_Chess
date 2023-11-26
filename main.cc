#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Pawn(Colour::Black), 0, 0);
    b.setPieceOnBoard(new Pawn(Colour::White), 1, 3);
    cout << b << endl << endl;

    b.activateMove(b.getCell(0, 0), b.getCell(0,2));
    b.activateMove(b.getCell(0,2), b.getCell(1,3));

    b.setPieceOnBoard(new Pawn(Colour::White), 0, 4);
    b.setPieceOnBoard(new Pawn(Colour::White), 2, 4);

    b.activateMove(b.getCell(1,3), b.getCell(0,4));
    cout << b << endl;

   
}
