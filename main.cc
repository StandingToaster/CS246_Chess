#include <iostream>
#include "board.h"



using namespace std;

int main() {


    Board b;
    b.setEmptyBoard();

    b.setPieceOnBoard(new King(Colour::White), 4, 4);
    b.setPieceOnBoard(new King(Colour::Black), 5, 6);
    b.setPieceOnBoard(new Queen(Colour::White), 4, 1);
    cout << b << endl;
    
    cout << b.checked(Colour::Black) << endl;



}
