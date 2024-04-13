#include <iostream>
#include <fstream>
#include "Board.h"
#include "Coin.h"

using namespace std;

void Board::printBoard (GameState &state) {
  cout << "\033[2J\033[;H";
  for (int i = 0; i < (int)boardMap.size(); i++) {
    for (int e = 0; e < (int)boardMap[i].size(); e++) {
      if (!boardMap[i][e].canWalk()) cout << "#";
      else {
        boardMap[i][e].printTile(state);
      }
    }
    cout << endl;
  }
}

void Board::setPacmanCoords (Coord a) {
  pacmanCoords.x = a.x;
  pacmanCoords.y = a.y;
}

bool Board::checkCollision () {
  return boardMap[pacmanCoords.y][pacmanCoords.x].checkCollision();
}