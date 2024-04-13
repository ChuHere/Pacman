#include <iostream>
#include <fstream>
#include <string>
#include "Application.h"

using namespace std;



bool Application::start () {
  while (true) {
    cout << "\033[2J\033[;H";
    cout << "Menu:" << endl;
    cout << "[1] Play" << endl;
    cout << "[2] Leadboard" << endl;
    cout << "[3] Exit" << endl;

    string number;
    
    //Get user input and what he wants to do
    cin >> number;
    if (cin.eof()) return false;

    if (number == "1") return true;
    else if (number == "2") {
      (*this).printLeaderboard();
      if (cin.eof()) return false;
    }
    else if (number == "3") return false;
  }
}

bool Application::initApp () {
  if (!gamePac.initGame()) {
    cout << "Initialisation unsuccessful" << endl;
    return false;
  }

  return true;
}

void Application::run () {
  while (true) {
    gamePac.run();
    if (!gamePac.checkGame()) {
      gamePac.addLeaderboard();
      break;
    }
    if (cin.eof()) break;
  }
}

void Application::printLeaderboard () const {
  //Print the current leaderboard
  ifstream file("examples/leaderboard.utf8");

  if (!file.is_open()) {
    cout << "Cannot open leaderboard." << endl;
    return;
  }

  string username, score, lives;

  while((file >> username >> score >> lives)) {
    cout << username << ": " << score << " " << lives << endl;
  }

  while (true) {
    string input;
    cout << "Enter any key to return" << endl;
    cin >> input;
    break;
  }
}