#include <iostream>
#include "Pacman.h"

using namespace std;

Pacman::Pacman (int inY, int inX) {
  coords.x = nextCoords.x = spawn.x = inX;
  coords.y = nextCoords.y = spawn.y = inY;
}

Pacman::Pacman () { }

void Pacman::setCoords (Coord a) {
  coords = nextCoords = spawn = a;
}

bool Pacman::readInput (string &out) {
  string tmp;
  bool success = false;

  //Get user input: w, s, a, d => everything else is invalid
  while (!success) {
    cin >> tmp;
    if (tmp == "w" || tmp == "s" || tmp == "a" || tmp == "d") success = true;
    else {
      if (cin.eof()) return false;
      cout << "Inccorect input, try again: " << endl;
    }
  }
  out = tmp;
  return true;
}

bool Pacman::move () {
  string userInput;
  if(!(*this).readInput(userInput)) return false;

  if (userInput == "w") nextCoords.y--;
  else if (userInput == "s") nextCoords.y++;
  else if (userInput == "a") nextCoords.x--;
  else if (userInput == "d") nextCoords.x++;

  return true;

}