#include <iostream>
#include "board.h"



using namespace std;

int main() {
    

    Board b;
    b.setEmptyBoard();


    b.setPieceOnBoard(new King(Colour::White), 4,6);
    b.setPieceOnBoard(new King(Colour::Black), 5,7);
    cout << b << endl;

    b.calculateLegalMoves(b.getCell(5,7));
    b.printBlackLegalMoves();


    // b.clearLegalMoves();

    // b.setPieceOnBoard(new Knight(Colour::White), 4,5);
    // b.setPieceOnBoard(new Knight(Colour::Black), 4,6);
    // cout << b << endl;
    // b.calculateLegalMoves(b.getCell(4,6));
    // b.printWhiteLegalMoves();
    // b.printBlackLegalMoves();

    // Board c = b;
    // cout << c << endl;
    // c.printWhiteLegalMoves();
    // c.printBlackLegalMoves();



    // b.setPieceOnBoard(new Rook(Colour::White), 0,0);
    // cout << b << endl;
    // b.calculateLegalMoves(b.getCell(0,0));
    // b.printWhiteLegalMoves();
    // b.printBlackLegalMoves();
    // c.setPieceOnBoard(new Rook(Colour::White), 7,7);
    // cout << c << endl;
    // c.calculateLegalMoves(c.getCell(7,7));
    // c.printWhiteLegalMoves();
    // c.printBlackLegalMoves();
    
    // Cell c1;
    // c1.setCoords(1,2);
    // c1.setColour(Colour::Black);
    // c1.addChessPiece(new Pawn(Colour::Black));

    // Cell c2;
    // c2.setCoords(3,4);
    // c2.setColour(Colour::White);
    // c2.addChessPiece(new Pawn(Colour::White));

    // c1 = c2;

    // cout << c1.getX() << endl;
    // cout << c1.getX() << endl;
    // cout << c1.getY() << endl;
    // cout << c1.getY() << endl;
    // cout << c1.getChessPiece() << endl;
    // cout << c2.getChessPiece() << endl;
    // cout << c1 << endl;
    // cout << c2 << endl;

    // b.setPieceOnBoard(new King(Colour::White), 4, 4);
    // b.setPieceOnBoard(new King(Colour::Black), 5, 6);
    // b.setPieceOnBoard(new Queen(Colour::White), 4, 1);
    // cout << b << endl;
    
    // cout << b.checked(Colour::Black) << endl;



}
