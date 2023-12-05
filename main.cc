#include <iostream>
#include "board.h"
#include "controller.h"
#include "computer.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "window.h"

using namespace std;

int main() {    


    Board b;


    b.setEmptyBoard();

    
    b.setPieceOnBoard(new King(Colour::Black), 0, 0);
    b.setPieceOnBoard(new King(Colour::White), 4, 7);

    // b.setPieceOnBoard(new King(Colour::Black), 7, 0);
    // b.setPieceOnBoard(new King(Colour::White), 0, 7);
    b.setPieceOnBoard(new Rook(Colour::White), 0, 7);

    cout << b << endl;

    cout << b.checked(Colour::Black) << endl;
    cout << b.checked(Colour::White) << endl;

    // b.clearLegalMoves();
    // // b.calculateAllLegalMoves();
    // cout << b.stalemated() << endl;

    // whitePieceCells[0].getChessPiece()

    b.activateMove(b.getCell(4,7), b.getCell(2,7));
    cout << b << endl;
    b.clearLegalMoves();
    b.printWhitePieceCells();
    b.calculateAllLegalMoves();
    b.printWhiteLegalMoves();
    b.printBlackLegalMoves();
    // b.promotePawn(Piece::Queen);
    // cout << b << endl;
    // b.clearLegalMoves();
    // b.calculateAllLegalMoves();
    // b.printBlackLegalMoves();
    // b.printWhiteLegalMoves();

    
    // Controller * c = new Controller{&b};
    // c->playGame(cin, cout);

    cout << "Final Score:" << endl;
    cout << "White: " <<  c->getScore1() << endl;
    cout << "Black: " << c->getScore2() << endl;

    return 0;




    // //Xwindow xw;
    // //while (true) {
        
        
    //     xw.fillRectangle(0,0,500,500,xw.White);
    //     xw.drawString(250,250, "QUACK");
    // }
    
    // Computer* whiteC = new level1(&b, Colour::White);
    // Computer* blackC = new level1(&b, Colour::Black);

    // b.setDefaultBoard();
    // cout << b << endl;

    // Move whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // cout << b << endl;

    // Move blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // cout << b << endl;

   
    // b.setDefaultBoard();
    // cout << b << endl;
    
    // whiteMove = whiteC->generateMove(); //SEG fault here, because getChessPiece() returns nullptr.
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // cout << b << endl;

    // blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // cout << b << endl;

    //Controller c {&b};
    //c.playGame(cin, cout);

    // b.setDefaultBoard();

    // Computer* whiteC = new level3(&b, Colour::White);
    // Computer* blackC = new level3(&b, Colour::Black);

    // Move whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;

    // Move blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;

    // whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;
    // blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;

    // whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;
    // blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;

    // whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;
    // blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;

    // whiteMove = whiteC->generateMove();
    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;
    // blackMove = blackC->generateMove();
    // b.activateMove(b.getCell(blackMove.getStart().getX(), blackMove.getStart().getY()), b.getCell(blackMove.getDest().getX(), blackMove.getDest().getY()));
    // b.calculateAllLegalMoves();
    // cout << b << endl;
    
    // b.setDefaultBoard();
    // cout << b << endl;


    // Computer * whiteC = new level2(&b, Colour::White);

    // Move whiteMove = whiteC->generateMove();

    // b.activateMove(b.getCell(whiteMove.getStart().getX(), whiteMove.getStart().getY()), b.getCell(whiteMove.getDest().getX(), whiteMove.getDest().getY()));
    // b.calculateAllLegalMoves();

    // cout << b << endl;

    
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
