#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Rook(Colour::White), 4, 7);
    b.setPieceOnBoard(new Rook(Colour::Black), 3, 4);
    cout << b << endl << endl;

    b.activateMove(b.getCell(3,4), b.getCell(0,4));
    b.activateMove(b.getCell(4,7), b.getCell(0,7));
    b.activateMove(b.getCell(0,7), b.getCell(0,5));
    b.activateMove(b.getCell(0,4), b.getCell(0,5));
    cout << b << endl;
   
}
