#include <iostream>
#include "board.h"
#include "controller.h"
#include "computer.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

using namespace std;

int main() {    


    Board b;
    Controller c {&b};
    c.playGame(cin, cout);

    
    // b.setDefaultBoard();

    // b.setPieceOnBoard(new King(Colour::Black), 0, 7);
    // b.setPieceOnBoard(new Rook(Colour::Black), 2 , 7);
    // // b.setPieceOnBoard(new Queen(Colour::White), 3, 7);
    // b.setPieceOnBoard(new Rook(Colour::White), 0, 0);
    // b.setPieceOnBoard(new King(Colour::White), 4, 0);
    // cout << b << endl;

    // b.activateMove(b.getCell(1,7), b.getCell(0,7));
    // cout << b.activateMove(b.getCell(4,0), b.getCell(2,0)) << endl;
    // b.calculateAllLegalMoves();
    // b.printWhiteLegalMoves();

    // cout << b << endl;

    // b.calculateAllLegalMoves();
    // b.printWhiteLegalMoves();
    // b.printBlackPieceCells();
    // b.printWhitePieceCells();

    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();
    // b.printWhiteLegalMoves();
    // b.setPieceOnBoard(new Pawn(Colour::Black), 0, 0);
    // b.printBlackPieceCells();
    // b.setPieceOnBoard(new Rook(Colour::Black), 6, 0);

    // b.setPieceOnBoard(new King(Colour::White), 6, 7);
    // b.setPieceOnBoard(new Pawn(Colour::White), 6, 1);

    

    // b.activateMove(b.getCell(6,1), b.getCell(6,0));
    // cout << b << endl;

    // b.calculateAllLegalMoves();
    // b.printWhiteLegalMoves();

    
    // // b.activateMove(b.getCell(6,4), b.getCell(6,3));


    // // // b.activateMove(b.getCell(7,4), b.getCell(7,3));
    //b.promotePawn(Piece::Queen);
    

    // b.clearLegalMoves();
    
    
    
    // cout << b.attackPossible(b.getCell(6,3), b.getCell(5,2)) << endl;
    // cout << b << endl;

    // b.clearLegalMoves();
    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();

    // b.printBlackPieceCells();
    // b.activateMove(b.getCell(6,0), b.getCell(0,0));
    // b.activateMove(b.getCell(0,4), b.getCell(-1,5));
    // cout << b << endl;
    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();
    // cout << b.stalemated() << endl;
    // cout << b.checkMated(Colour::Black);
    // cout << b.activateMove(b.getCell(1,3), b.getCell(0,4)) << endl << endl;
    
    

    // cout << b << endl;
    // b.printBlackPieceCells();
    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();
    // cout << b.activateMove(b.getCell(2,2), b.getCell(2,0)) << endl << endl;
    // cout  << b << endl;



    // b.calculateAllLegalMoves();
    // // b.printWhiteLegalMoves();

    // Computer * c = new level2(&b, Colour::White);
    // Move test = c->generateMove();

    // cout << test.getStart() << endl;
    // cout << test.getDest() << endl;

    // int sx = test.getStart().getX();
    // int sy = test.getStart().getY();
    // int dx = test.getDest().getX();
    // int dy = test.getDest().getY();

    // cout << "Start: " << "(" << sx << "," << sy << ")" << endl;
    // cout << "Dest: " << "(" << dx << "," << dy << ")" << endl;
    





}
