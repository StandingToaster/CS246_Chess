#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();

    b.setPieceOnBoard(new King(Colour::White), 4, 5);
    b.setPieceOnBoard(new King(Colour::Black), 5, 6);
    cout << b << endl;
    
    cout << b.attackPossible(b.getCell(4,5), b.getCell(5,6)) << endl;
    // b.printBlackPieceCells();
    // b.printWhitePieceCells();

    // b.activateMove(b.getCell(1,7), b.getCell(2,5));
    // cout << b << endl;
    // b.printBlackPieceCells();
    // b.printWhitePieceCells();

    // b.setPieceOnBoard(new King(Colour::White), 4, 7);
    // b.setPieceOnBoard(new King(Colour::Black), 3, 4);
    // cout << b << endl;;
    // b.printWhitePieceCells();
    // b.printBlackPieceCells();

    // b.activateMove(b.getCell(4,7), b.getCell(5,6));
    // b.activateMove(b.getCell(3,4), b.getCell(4,5));
    // cout << b << endl;
    // b.printWhitePieceCells();
    // b.printBlackPieceCells();

    // b.activateMove(b.getCell(5,6), b.getCell(4,5));
    // cout << b << endl;
    // b.printWhitePieceCells();
    // b.printBlackPieceCells();
}
