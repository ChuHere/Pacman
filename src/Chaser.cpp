#include <set>
#include <map>
#include <queue>
#include "Chaser.h"
#include "Coord.h"

using namespace std;

Chaser::Chaser (int inY, int inX) : Ghost(inY, inX), lastState(false) { }

shared_ptr<Ghost> Chaser::clone () const {
  return make_shared<Chaser>(*this);
}

void Chaser::respawn (Board &gameboard) {
  gameboard.boardMap[coords.y][coords.x].delGhost();
  coords.x = targetRun.x = spawn.x;
  coords.y = targetRun.y = spawn.y;
  gameboard.boardMap[coords.y][coords.x].addGhost();
  lastState = false;
  path.clear();
}

void Chaser::findPath (Board &gameboard, Coord &target) {
  path.clear();
  //Queue of potential coordinates to go to
  queue<Coord> movePaths;

  //left, right, up, down
  vector<Coord> moveKeys = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  map<Coord, Coord> moveParent;
  //Visited tiles
  set<Coord> visitedTiles;

  //We use the BFS algorithm, travel to every tile if it hasn't been visited and stop when
  //we get on the target coordinates => we have found the shortest path to him
  movePaths.push(coords);
  visitedTiles.insert(coords);

  while (!movePaths.empty()) {
    Coord curr = movePaths.front();
    movePaths.pop();

    if (coords == target) {
      break;
    }

    for (Coord move : moveKeys) {
      Coord tmp = {curr.x, curr.y};
      tmp.x += move.x;
      tmp.y += move.y;
      if (tmp.y < (int)gameboard.boardMap.size() && tmp.y >= 0 
      && tmp.x < (int)gameboard.boardMap[curr.y].size() && tmp.x >= 0) {
        if (gameboard.boardMap[tmp.y][tmp.x].canWalk() && visitedTiles.insert(tmp).second) {
          movePaths.push(tmp);
          moveParent[tmp] = curr;
        }
      }
    }
  }

  path = moveParent;
}

void Chaser::moveTarget (Board &gameboard, Coord &target) {
  if (coords == target || path.empty()) return;
  
  //Get the first move and move towards the target
  Coord updated;
  updated.x = target.x;
  updated.y = target.y;
  Coord tile = path[updated];
  while (tile != coords) {
    updated = tile;
    tile = path[updated];
  }

  gameboard.boardMap[coords.y][coords.x].delGhost();
  gameboard.boardMap[updated.y][updated.x].addGhost();
  coords.y = updated.y;
  coords.x = updated.x;
}

void Chaser::move (Board &gameboard, GameState &state) {
  if ((*this).checkPac(gameboard, state)) return;

  //If Pacman has a powerup. Choose random spot to go to.
  //Otherwise chase down Pacman.
  if (state.powerup) {
    if (!lastState || coords == targetRun) {
      int randomY = (rand() % ((int)gameboard.boardMap.size()));
      int randomX = (rand() % ((int)gameboard.boardMap[randomY].size()));
      while (!gameboard.boardMap[randomY][randomX].canWalk()) {
        randomY = (rand() % ((int)gameboard.boardMap.size()));
        randomX = (rand() % ((int)gameboard.boardMap[randomY].size()));
      }
      targetRun.y = randomY;
      targetRun.x = randomX;
      (*this).findPath(gameboard, targetRun);
    }
    (*this).moveTarget(gameboard, targetRun);
  } else {
    if (!(*this).checkPac(gameboard, state)) {
      (*this).findPath(gameboard, gameboard.pacmanCoords);
      (*this).moveTarget(gameboard, gameboard.pacmanCoords);
    }
  }

  lastState = state.powerup;
}