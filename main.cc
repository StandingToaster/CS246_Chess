#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new King(Colour::White), 4, 7);
    b.setPieceOnBoard(new King(Colour::Black), 3, 4);
    cout << b << endl << endl;

    b.activateMove(b.getCell(3,4), b.getCell(3,5));
    b.activateMove(b.getCell(3,5), b.getCell(3,6));
    b.activateMove(b.getCell(4,7), b.getCell(3,6));
    b.activateMove(b.getCell(3,6), b.getCell(4,5));
    b.activateMove(b.getCell(4,5), b.getCell(5,6));
    b.activateMove(b.getCell(5,6), b.getCell(4,7));
    b.activateMove(b.getCell(4,7), b.getCell(5,7));
    b.activateMove(b.getCell(5,7), b.getCell(5,6));
    b.activateMove(b.getCell(5,6), b.getCell(5,7));
    b.activateMove(b.getCell(5,7), b.getCell(4,7));
    b.activateMove(b.getCell(4,7), b.getCell(3,6));
    cout << b << endl;
   
}
