#include <iostream>
#include "board.h"



using namespace std;

int main() {
    

    Board b;
    b.setEmptyBoard();

    Cell c1;
    c1.setCoords(1,2);
    c1.setColour(Colour::Black);
    c1.addChessPiece(new Pawn(Colour::Black));

    Cell c2 = c1;

    cout << c1.getY() << endl;
    cout << c2.getY() << endl;

    // b.setPieceOnBoard(new King(Colour::White), 4, 4);
    // b.setPieceOnBoard(new King(Colour::Black), 5, 6);
    // b.setPieceOnBoard(new Queen(Colour::White), 4, 1);
    // cout << b << endl;
    
    // cout << b.checked(Colour::Black) << endl;



}
