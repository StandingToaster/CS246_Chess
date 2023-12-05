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
    
    Controller * c = new Controller{&b};
    cout << "############################" << endl;
    cout << "#     Welcome to Chess     #" << endl;
    cout << "############################" << endl;
    cout << endl << "Created by Harsimran Kalsi, Hirav Thakur, Jinil Panawala." << endl;
    cout << "Use -help for the game manual." << endl;
    cout << "____________________________" << endl << endl;

    c->playGame(cin, cout);

    cout << "Final Score:" << endl;
    cout << "White: " <<  c->getScore1() << endl;
    cout << "Black: " << c->getScore2() << endl;
    cout << "____________________________" << endl;
    cout << "Goodbye!" << endl;

    delete c;

    return 0;
}
