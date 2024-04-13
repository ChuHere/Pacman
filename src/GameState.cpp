#include <iostream>
#include "GameState.h"

using namespace std;

GameState::GameState() : score(0), lives(3), powerup(false), duration(0), turnCounter(0), pointsAvailable(0) { }

// GameState::~GameState() { }

int GameState::getScore () {
  return score;
}

int GameState::getLives () {
  return lives;
}

void GameState::setPac (shared_ptr<Pacman> &p) {
  pac = p;
}

void GameState::initDuration () {
  turnCounter = duration;
}

void GameState::printState () {
  cout << "PowerupTurns" << turnCounter << endl;
  cout << "ToCollect:" << pointsAvailable << endl;
  cout << "Score: " << score << endl;
  cout << "Lives: " << lives << endl;
}