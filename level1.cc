#include "level1.h"

using namespace std;

Move level1::generateMove() {
    Board* p = this->getPointer();
    if (Colour::Black == this->getColour()) {
        vector<Move> temp = p->getLegalMoves(this->getColour());
        int N = temp.size();
        int random = rand() % N;
        return temp[random];
    }
    else {
       vector<Move> temp = p->getLegalMoves(this->getColour());
        int N = temp.size();
        int random = rand() % N;
        return temp[random]; 
    }
}