#include "Cherry.h"

using namespace std;

Cherry::Cherry() : Effect() { }

shared_ptr<Effect> Cherry::clone () const {
  return make_shared<Cherry>(*this);
}

void Cherry::activate (GameState &state) {
  //Allow ghost hunting and increase the score
  if (!taken) {
    taken = true;
    state.score += (50*state.difficulty);
    state.powerup = true;
    state.pointsAvailable--;
    state.initDuration();
  }
}

void Cherry::printObject() const {
  if (taken) cout << ' ';
  else cout << 'g';
}