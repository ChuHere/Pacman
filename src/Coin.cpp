#include "Coin.h"

using namespace std;

Coin::Coin() : Effect() { }
// Coin::~Coin() : ~Effect() { }

shared_ptr<Effect> Coin::clone () const {
  return make_shared<Coin>(*this);
}

void Coin::activate (GameState &state) {
  //Increase the score
  if (!taken) {
    taken = true;
    state.score += (10*state.difficulty);
    state.pointsAvailable--;
  }
}

void Coin::printObject() const {
  if (taken) cout << ' ';
  else cout << '.';
}