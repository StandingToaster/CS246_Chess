#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Pawn(Colour::White), 4, 7);
    b.setPieceOnBoard(new Pawn(Colour::Black), 3, 4);
    cout << b << endl << endl;

    b.activateMove(b.getCell(4,7), b.getCell(4,5));
    b.setPieceOnBoard(new Pawn(Colour::Black), 5, 4);



    b.activateMove(b.getCell(4,5), b.getCell(5,4));
    b.activateMove(b.getCell(5,4), b.getCell(6,3));
    b.activateMove(b.getCell(5,4), b.getCell(5,3));
    b.activateMove(b.getCell(5,3), b.getCell(5,2));
    b.activateMove(b.getCell(5,2), b.getCell(5,1));
    b.activateMove(b.getCell(5,1), b.getCell(5,0));
    b.activateMove(b.getCell(5,0), b.getCell(5,1));

    b.activateMove(b.getCell(3,4), b.getCell(3,5));
    b.activateMove(b.getCell(3,5), b.getCell(3,4));
    cout << b << endl;
   
}
