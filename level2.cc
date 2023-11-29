#include "level2.h"

using namespace std;

bool level2::checkForKill(Move input) {
   return input.hasEnemyPresence();
}

