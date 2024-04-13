#include <iostream>
#include <fstream>
#include <algorithm>
#include "Game.h"
#include "Coin.h"
#include "Cherry.h"
#include "Teleport.h"
#include "Dumb.h"
#include "Chaser.h"
#include "Zombie.h"

using namespace std;


bool Game::checkValid () {
  //Check if the config can be read properly
  if (!conf.loadConfig("examples/config.utf8")) return false;
  
  //Based on the config, we choose difficulty and the map.
  //Check if the map is valid and can be therefore loaded.
  if (conf.mapDiff == "Easy") {
    state.difficulty = 1;
    if(!conf.checkMap("examples/easyMap.utf8")) return false;
    (*this).loadBoard("examples/easyMap.utf8");
  } else if (conf.mapDiff == "Medium") {
    state.difficulty = 2;
    if(!conf.checkMap("examples/mediumMap.utf8")) return false;
    (*this).loadBoard("examples/mediumMap.utf8");
  } else if (conf.mapDiff == "Hard") {
    state.difficulty = 3;
    if(!conf.checkMap("examples/hardMap.utf8")) return false;
    (*this).loadBoard("examples/hardMap.utf8");
  } else {
    return false;
  }

  return true;
}

void Game::loadBoard (string file) {
  //loadBoard
  ifstream boardFile(file);

  if (!boardFile.is_open()) {
    throw runtime_error("Cannot open a board file.");
  }

  gameBoard.boardMap.resize(conf.mapHeight);

  Pacman player;
  char c;

  
  //Read every character of the map from the files and assign appropriate objects.
  for (size_t i = 0; i < conf.mapHeight; i++) {
    for (size_t e = 0; e < conf.mapWidth; e++) {
      if (!(boardFile >> c)) throw runtime_error("Error while reading a board file.");

      if (c == '#') {
        BoardTile tile(nullptr, 0, false, false);
        gameBoard.boardMap[i].push_back(tile);
      } else if (c == '.') {
        Coin tmp;
        BoardTile tile(tmp.clone(), 0, false, true);
        gameBoard.boardMap[i].push_back(tile);
        state.pointsAvailable++;
      } else if (c == 'g') {
        Cherry tmp;
        BoardTile tile(tmp.clone(), 0, false, true);
        gameBoard.boardMap[i].push_back(tile);
        state.pointsAvailable++;
      } else if (c == 'T') {
        Teleport tmp((int)conf.mapHeight, (int)conf.mapWidth);
        BoardTile tile(tmp.clone(), 0, false, true);
        gameBoard.boardMap[i].push_back(tile);
      } else if (c == '1' || c == '2' || c == '3') {
        Coin tmp;
        BoardTile tile(tmp.clone(), 1, false, true);
        gameBoard.boardMap[i].push_back(tile);
        state.pointsAvailable++;
        if (c == '1') {
          Chaser tmpGhost(i, e);
          ghosts.push_back(tmpGhost.clone());
        } else if (c == '2') {
          Zombie tmpGhost(i, e);
          ghosts.push_back(tmpGhost.clone());
        } else {
          Dumb tmpGhost(i, e);
          ghosts.push_back(tmpGhost.clone());
        }
      } else if (c == 'O') {
        Coin tmp;
        BoardTile tile(tmp.clone(), 0, true, true);
        gameBoard.boardMap[i].push_back(tile);
        Coord pacPos = {(int)e, (int)i};
        gameBoard.setPacmanCoords(pacPos);
        pac->setCoords(pacPos);
        state.pointsAvailable++;
      } else {
        throw runtime_error("Incorrect entity in the board.");
      }
    }
  }

  boardFile.close();
}

bool Game::initGame () {
  if (!(*this).checkValid()) return false;
  state.setPac(pac);
  state.duration = conf.powerupDur;

  return true;
}

void Game::respawnPac () {
  gameBoard.boardMap[pac->coords.y][pac->coords.x].setPac(false);
  pac->coords = pac->nextCoords = pac->spawn;
  gameBoard.boardMap[pac->coords.y][pac->coords.x].setPac(true);
}

void Game::respawnFigures () {
  gameBoard.printBoard(state);
  state.printState();
  (*this).respawnPac();
  for (vector<shared_ptr<Ghost>>::iterator it = ghosts.begin(); it != ghosts.end(); it++) {
    (*it)->respawn(gameBoard);
  }

  state.lives--;
}

void Game::pacMove () {
  pac->move();
  if (cin.eof()) return;
  if (gameBoard.boardMap[pac->nextCoords.y][pac->nextCoords.x].canWalk()) {
    gameBoard.boardMap[pac->coords.y][pac->coords.x].setPac(false);
    pac->coords = pac->nextCoords;
    gameBoard.boardMap[pac->coords.y][pac->coords.x].changeState(state);
    gameBoard.boardMap[pac->coords.y][pac->coords.x].setPac(true);
    gameBoard.setPacmanCoords(pac->coords);
  } else {
    pac->nextCoords = pac->coords;
  }
}

void Game::run () {
  gameBoard.printBoard(state);
  state.printState();

  if (state.powerup) {
    (*this).pacMove();
    if (cin.eof()) return;
    gameBoard.printBoard(state);
    state.printState();
    for (vector<shared_ptr<Ghost>>::iterator it = ghosts.begin(); it != ghosts.end(); it++) {
      (*it)->checkPac(gameBoard, state);
    }
    state.turnCounter -= 2;

    if (state.turnCounter <= 0) state.powerup = false;
  }

  (*this).pacMove();
  if (cin.eof()) return;
  for (vector<shared_ptr<Ghost>>::iterator it = ghosts.begin(); it != ghosts.end(); it++) {
    (*it)->move(gameBoard, state);
  }

  if(gameBoard.checkCollision()) {
    if (state.powerup) {
      for (vector<shared_ptr<Ghost>>::iterator it = ghosts.begin(); it != ghosts.end(); it++) {
        (*it)->checkPac(gameBoard, state);
      }
    } else {
      (*this).respawnFigures();
    }
  }
}

bool Game::checkGame () {
  if (state.lives <= 0) {
    gameBoard.printBoard(state);
    state.printState();
    cout << "Unlucky, you have lost all your lives" << endl;
    return false;
  } else if (state.pointsAvailable <= 0) {
    gameBoard.printBoard(state);
    state.printState();
    cout << "Congratulations!!! You have collected everything!" << endl;
    return false;
  }
  return true;
}

void Game::addLeaderboard () {
  ifstream file("examples/leaderboard.utf8");

  if (!file.is_open()) return;
  
  vector<PlayerInfo> leaderboard;
  PlayerInfo tmp;

  cout << "Choose your username: " << endl;
  string name;
  
  //Add current session and read from leaderboard
  cin >> name;
  if (cin.eof()) return;
  tmp.username = name;
  tmp.score = state.score;
  tmp.lives = state.lives;

  leaderboard.push_back(tmp);
  while((file >> tmp.username >> tmp.score >> tmp.lives)) {
    leaderboard.push_back(tmp);
  }

  file.close();

  //Sort by score desc, username desc and lives asc
  sort(leaderboard.begin(), leaderboard.end(), [](const PlayerInfo &left, const PlayerInfo &right) {
    if (left.score == right.score) {
      if (left.lives == right.lives) {
        return left.username < right.username;
      }

      return left.lives > right.lives;
    }
    return left.score > right.score;
  });

  ofstream fileW("examples/leaderboard.utf8");

  if(!fileW.is_open()) return;
  cout << "Leaderboard:" << endl;
  for (PlayerInfo x : leaderboard) {
    fileW << x.username << " " << x.score << " " << x.lives << endl;
    cout << x.username << ": " << x.score << " " << x.lives << endl;
  }

  fileW.close();
}