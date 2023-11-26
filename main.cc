#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Bishop(Colour::White), 4, 7);
    b.setPieceOnBoard(new Bishop(Colour::Black), 3, 4);
    cout << b << endl << endl;

    b.activateMove(b.getCell(3,4), b.getCell(6,5));
    b.activateMove(b.getCell(4,7), b.getCell(5,6));
    b.activateMove(b.getCell(3,4), b.getCell(5,6));
    b.activateMove(b.getCell(5,6), b.getCell(4,7));
    b.activateMove(b.getCell(4,7), b.getCell(2,5));
    b.activateMove(b.getCell(2,5), b.getCell(0,3));
    b.activateMove(b.getCell(0,3), b.getCell(3,0));
    b.activateMove(b.getCell(3,0), b.getCell(3,0));
    cout << b << endl;
   
}
