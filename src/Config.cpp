#include <iostream>
#include <fstream>
#include <sstream>
#include "Config.h"

using namespace std;


Config::Config() : powerupDur(0), mapHeight(0), mapWidth(0) { }

bool Config::loadConfig (const string &file) {
  ifstream fileC(file);
  string input;
  int count = 0;

  if (!fileC.is_open()) {
    return false;
  }

  while (getline(fileC, input) && fileC.is_open()) {
    if (input.size() == 0) continue;

    istringstream iss(input);
    string value;
    iss >> value;

    if (value == "Map:") {
      iss >> mapDiff;
      count++;
    } else if (value == "Powerup:") {
      iss >> powerupDur;
      if (powerupDur <= 0) return false;
      count ++;
    }
  }

  if (count < 2) return false;

  return true;
}

bool Config::checkMap (const string &file) {
  ifstream fileC(file);
  string input;
  string tmp;

  if (!fileC.is_open()) return false;

  bool start = true;
  bool pacmanExists = false;
  while (getline(fileC, input) && fileC.is_open()) {
    if (start) {
      mapWidth = input.size()-1;

      //Check if the top border is all walls
      for (char c : input) {
        if (c != '#' && c != '\n' && c != '\r') return false;
      }
      start = false;
    }

    if (mapWidth != input.size()-1) {
      return false;
    }

    if (input.size() == 0) continue;

    //Check if the border is a wall or teleport
    if ((input[0] != '#' && input[0] != 'T') || (input[mapWidth-1] != '#' && input[mapWidth-1] != 'T')) return false;
 
    //Check if there is a teleport on both sides
    if ((input[0] == 'T' && input[mapWidth-1] != 'T') || (input[0] != 'T' && input[mapWidth-1] == 'T')) return false;

    //Check if the teleports aren't blocked
    if ((input[0] == 'T' && input[1] == '#') || (input[mapWidth-1] == 'T' && input[mapWidth-2] == '#')) return false;


    for (char c : input) {
      if (!(c != '1' || c != '2' || c != '3' || c != 'O' || c != '.' 
          || c != 'g' || c != '#' || c != '\n' || c != '\r')) return false;
      if (c == 'O') {
        if (pacmanExists) return false;
        pacmanExists = true;
      }
    }
    tmp = input;
    mapHeight++;
  }
  //Check if the bottom border is all walls
  for (char c : tmp) {
    if (c != '#' && c != '\n' && c != '\r') return false;
  }
  if (!pacmanExists) return false;
  return true;
}