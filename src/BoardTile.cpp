#include <iostream>
#include "BoardTile.h"
#include "Pacman.h"

using namespace std;

BoardTile::BoardTile(shared_ptr<Effect> object, int gh, bool pc, bool walk) 
  : obj(object), ghost(gh), pacman(pc), walkable(walk) { }

BoardTile::~BoardTile() { }

bool BoardTile::checkCollision () {
  if (pacman && ghost > 0) return true;
  return false;
}

bool BoardTile::checkPacman () {
  return pacman;
}

bool BoardTile::canWalk () {
  return walkable;
}

void BoardTile::changeState (GameState &state) {
  if (obj != nullptr) obj->activate(state);
}

void BoardTile::setPac (bool x) {
  pacman = x;
}

void BoardTile::addGhost () {
  ghost++;
}

void BoardTile::delGhost () {
  ghost--;
}

void BoardTile::printTile (GameState &state) {
  if (ghost != 0) {
    if (state.powerup) cout << 'U';
    else cout << 'A';
  } else if (pacman) cout << 'O';
  else obj->printObject();
}