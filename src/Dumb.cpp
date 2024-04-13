#include <cstdlib>
#include "Dumb.h"

using namespace std;

Dumb::Dumb (int inY, int inX) : Ghost(inY, inX) {
  recentDir.x = 0;
  recentDir.y = 0;
}

shared_ptr<Ghost> Dumb::clone () const {
  return make_shared<Dumb>(*this);
}

void Dumb::respawn (Board &gameboard) {
  gameboard.boardMap[coords.y][coords.x].delGhost();
  coords = spawn;
  gameboard.boardMap[coords.y][coords.x].addGhost();
  recentDir.x = 0;
  recentDir.y = 0;
}

bool Dumb::isReverseDir (Coord &checkDir) {
  //Get the reversed direction for the last direction we chose. (w,s);(a,d)
  Coord reverse;
  reverse.x = recentDir.x;
  reverse.y = recentDir.y;
  
  if (recentDir.x == -1 && recentDir.y == 0) {
    reverse.x = 1;
  } else if (recentDir.x == 1 && recentDir.y == 0) {
    reverse.x = -1;
  } else if (recentDir.y == -1 && recentDir.x == 0) {
    reverse.y = 1;
  } else if (recentDir.y == 1 && recentDir.x == 0) {
    reverse.y = -1;
  } else {
    return false;
  }

  return (reverse == checkDir);
}

void Dumb::move (Board &gameboard, GameState &state) {
  if ((*this).checkPac(gameboard, state)) return;

  //Pick a random direction and check if it's valid. If it isn't, pick another.
  int randomNum = (rand() % 4);
  vector<Coord> moveKeys = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  for (int i = 0; i < (int)moveKeys.size(); i++) {
    Coord curr = coords;
    Coord tmp = moveKeys.at(randomNum);
    curr.x += tmp.x;
    curr.y += tmp.y;

    //Check if it is within board boundaries.
    if (curr.y < (int)gameboard.boardMap.size() && curr.y >= 0 
      && curr.x < (int)gameboard.boardMap[curr.y].size() && curr.x >= 0) {
      if (gameboard.boardMap[curr.y][curr.x].canWalk() && !isReverseDir(tmp)) {
        gameboard.boardMap[coords.y][coords.x].delGhost();
        coords = curr;
        gameboard.boardMap[coords.y][coords.x].addGhost();
        recentDir = tmp;
        break;
      } 
    }

    if (randomNum != (int)(moveKeys.size()-1)) {
      randomNum++;        
    } else {
      randomNum = 0;
    }

    if (i == (int)(moveKeys.size()-1)) {
      recentDir.x = 0;
      recentDir.y = 0;
    }
    
  }
}