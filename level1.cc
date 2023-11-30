#include "level1.h"

using namespace std;

Move level1::generateMove() {
    //Retrieves board.
    Board* p = this->getPointer();
    //Determines whether the computer is black/white side.
    if (Colour::Black == this->getColour()) {
        //Creates a temp. vector of all legal moves for that colour.
        vector<Move> temp = p->getLegalMoves(this->getColour());
        //Retrieves vector size.
        int N = temp.size();
        //Generates random number between 0 and N-1 (Upper bound of vector).
        int random = rand() % N;
        //Returns the move chosen by computer.
        return temp[random];
    }
    else {
        //Repeat but only if the computer is playing white side instead.
       vector<Move> temp = p->getLegalMoves(this->getColour());
        int N = temp.size();
        int random = rand() % N;
        return temp[random]; 
    }
}
