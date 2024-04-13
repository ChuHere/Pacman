#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include "Zombie.h"

using namespace std;

Zombie::Zombie (int inY, int inX) : Ghost(inY, inX), vision(false), lastState(false) {
  target.y = inY;
  target.x = inX;
}

shared_ptr<Ghost> Zombie::clone () const {
  return make_shared<Zombie>(*this);
}

void Zombie::respawn (Board &gameboard) {
  gameboard.boardMap[coords.y][coords.x].delGhost();
  coords.x = target.x = spawn.x;
  coords.y = target.y = spawn.y;
  gameboard.boardMap[coords.y][coords.x].addGhost();
  vision = false;
  path.clear();
}

void Zombie::checkPrey (Board &gameboard) {
  vector<Coord> moveKeys = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for (Coord move : moveKeys) {
    Coord curr = {coords.x, coords.y};
    while (!gameboard.boardMap[curr.y][curr.x].checkPacman() && gameboard.boardMap[curr.y][curr.x].canWalk()) {
      curr.x += move.x;
      curr.y += move.y;

      if (curr.y >= (int)gameboard.boardMap.size() || curr.y < 0 
      || curr.x >= (int)gameboard.boardMap[curr.y].size() || curr.x < 0) {
        break;
      }
    }

    if (gameboard.boardMap[curr.y][curr.x].checkPacman()) {
      vision = true;
      dir = move;
    }
  }
}

void Zombie::findPath (Board &gameboard) {
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

    if (curr.y == target.y && curr.x == target.x) {
      break;
    }

    for (Coord move : moveKeys) {
      Coord tmp = {curr.x, curr.y};
      tmp.x += move.x;
      tmp.y += move.y;

      if (tmp.y < (int)gameboard.boardMap.size() && tmp.y >= 0 
      && tmp.x < (int)gameboard.boardMap[tmp.y].size() && tmp.x >= 0) {
        if (gameboard.boardMap[tmp.y][tmp.x].canWalk() && visitedTiles.insert(tmp).second) {
          movePaths.push(tmp);
          moveParent[tmp] = curr;
        }
      }
    }
  }

  path = moveParent;
}

void Zombie::move (Board &gameboard, GameState &state) {
  if ((*this).checkPac(gameboard, state)) return;
  
  //Checks if Pacman is seen
  if (!state.powerup) checkPrey(gameboard);
  else vision = false;

  //If the Pacman was spotted, we continue in that direction
  if (vision && !state.powerup) {
    if (gameboard.boardMap[coords.y + dir.y][coords.x + dir.x].canWalk()) {
      gameboard.boardMap[coords.y][coords.x].delGhost();
      coords.x += dir.x;
      coords.y += dir.y;
      gameboard.boardMap[coords.y][coords.x].addGhost();
    } else {
      vision = false;
      target.x = coords.x;
      target.y = coords.y;
      path.clear();
    }
  }
  
  //If the pacman is not seen, we choose a random spot and go towards it.
  if (!vision) {
    if (coords == target || !lastState) {
      int randomY = (rand() % ((int)gameboard.boardMap.size()));
      int randomX = (rand() % ((int)gameboard.boardMap[randomY].size()));
      while (!gameboard.boardMap[randomY][randomX].canWalk()) {
        randomY = (rand() % ((int)gameboard.boardMap.size()));
        randomX = (rand() % ((int)gameboard.boardMap[randomY].size()));
      }

      target.y = randomY;
      target.x = randomX;
      (*this).findPath(gameboard);
    }


    //Get the first move
    Coord nextMove = target;
    Coord tile = path[nextMove];
    int count = (int)path.size();

    while (tile != coords) {
      nextMove = tile;
      tile = path[nextMove];
      count--;
      if (count < 0) {
        path.clear();
        nextMove == coords;
        break;
      }
    }

    gameboard.boardMap[coords.y][coords.x].delGhost();
    gameboard.boardMap[nextMove.y][nextMove.x].addGhost();
    coords.y = nextMove.y;
    coords.x = nextMove.x;
  }

  if (!state.powerup) checkPrey(gameboard);
  lastState = state.powerup;
}