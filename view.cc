#include "view.h"

using namespace std;

View::View(int boardSize):boardSize{boardSize} {
    xw.fillRectangle(0,0,500,500,xw.Black);
}

