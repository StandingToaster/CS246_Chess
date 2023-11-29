#include <iostream>
#include "board.h"



using namespace std;

int main() {
    

    Board b;
    b.setEmptyBoard();

    b.setPieceOnBoard(new King(Colour::White), 4, 0);
    b.setPieceOnBoard(new Queen(Colour::White), 5, 1);

    b.setPieceOnBoard(new Rook(Colour::Black), 4, 7);
    b.setPieceOnBoard(new King(Colour::Black), 3, 7);

    cout << b << endl;

    // Board c = b;

    // cout << c << endl;
    // c.activateMove(c.getCell(4,0), c.getCell(5,0));
    // cout << c << endl;
    // cout << c.checked(Colour::White) << endl;


    cout << b.checkMated(Colour::White) << endl;
    // b.printWhiteLegalMoves();


    // Board c;
    // c.setEmptyBoard();
    // c.setPieceOnBoard(new King(Colour::White), 4, 0);
    // c.setPieceOnBoard(new Queen(Colour::White), 4, 1);

    // c.setPieceOnBoard(new Rook(Colour::Black), 4, 7);
    // c.setPieceOnBoard(new King(Colour::Black), 3, 7);

    // cout << c << endl;
    // cout << c.checked(Colour::White) << endl;




}
