#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();
    b.setPieceOnBoard(new Pawn(Colour::Black), 0, 0);

    cout << b << endl << endl;

    b.activateMove(b.getCell(0, 0), b.getCell(0,1));
    b.activateMove(b.getCell(2,0), b.getCell(2,1));
    cout << b << endl;

   
}
