#include "Ghost.h"

using namespace std;

Ghost::Ghost(int inY, int inX) {
  coords.x = inX;
  coords.y = inY;

  spawn.x = inX;
  spawn.y = inY;
}

Ghost::~Ghost () { }

bool Ghost::checkPac (Board &gameboard, GameState &state) {
  if (coords == gameboard.pacmanCoords) {
    if (state.powerup) {
      state.score += (100*state.difficulty);
    }
    (*this).respawn(gameboard);
    return true;
  }

  return false;
} 