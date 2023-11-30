#include "level1.h"

using namespace std;

level1::level1(Board* in, Colour cur): Computer{in, cur} {}

Move level1::generateMove() {
    //Retrieves board.
    Board* p = this->getPointer();
    //Determines whether the computer is black/white side.
    if (Colour::Black == this->getColour()) {
        this->readyTheBoard(p);
        //Creates a temp. vector of all legal moves for that colour.
        
        vector<Move> temp = p->getLegalMoves(this->getColour());
        //Retrieves vector size.
        int N = temp.size();
        //Specifics for how a C++ generator works, ignore!
        srand((unsigned) time(NULL));
        //Generates random number between 0 and N-1 (Upper bound of vector).
        int random = rand() % N;
        //Returns the move chosen by computer.
        return temp[random];
    }
    else {
        this->readyTheBoard(p);
        //Repeat but only if the computer is playing white side instead.
       vector<Move> temp = p->getLegalMoves(this->getColour());
        int N = temp.size();
        srand((unsigned) time(NULL));
        int random = rand() % N;
        return temp[random]; 
    }
}
