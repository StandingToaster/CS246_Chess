#include <iostream>
#include "board.h"



using namespace std;

int main() {
    

    Board b;
    b.setEmptyBoard();

    b.setPieceOnBoard(new King(Colour::Black), 4, 1);
    b.setPieceOnBoard(new Queen(Colour::Black), 3, 0);
    b.setPieceOnBoard(new Bishop(Colour::Black), 5, 0);
    b.setPieceOnBoard(new Pawn(Colour::Black), 3, 2);

    b.setPieceOnBoard(new Bishop(Colour::White), 5, 1);
    b.setPieceOnBoard(new Knight(Colour::White), 3, 3);
    b.setPieceOnBoard(new Knight(Colour::White), 4, 3);
    b.setPieceOnBoard(new King(Colour::White), 4, 7);

    cout << b << endl;
    cout << b.checkMated(Colour::White) << endl;




}
