#include "Teleport.h"
#include "Coord.h"

using namespace std;



Teleport::Teleport (int height, int width) : maxHeight(height), maxWidth(width) { }


shared_ptr<Effect> Teleport::clone () const {
  return make_shared<Teleport>(*this);
}

void Teleport::activate (GameState &state) {
  if (state.pac->coords.x == maxWidth-1) state.pac->coords.x = state.pac->nextCoords.x = 1;
  else state.pac->coords.x = state.pac->nextCoords.x = maxWidth-2;
}


void Teleport::printObject() const {
  cout << 'T';
}