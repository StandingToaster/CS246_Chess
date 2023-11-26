#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Queen(Colour::White), 4, 7);
    b.setPieceOnBoard(new Queen(Colour::Black), 3, 4);
    cout << b << endl << endl;

    b.activateMove(b.getCell(3,4), b.getCell(3,7));
    b.activateMove(b.getCell(3,7), b.getCell(4,7));
    b.activateMove(b.getCell(4,7), b.getCell(0,0));
    b.activateMove(b.getCell(4,7), b.getCell(1,4));
    b.activateMove(b.getCell(1,4), b.getCell(4,1));
    b.activateMove(b.getCell(4,1), b.getCell(7,4));
    b.activateMove(b.getCell(7,4), b.getCell(4,7));
    b.activateMove(b.getCell(4,7), b.getCell(4,0));
    b.activateMove(b.getCell(4,0), b.getCell(0,0));
    b.activateMove(b.getCell(0,0), b.getCell(7,0));
    cout << b << endl;
   
}
