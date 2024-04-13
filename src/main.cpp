#include <iostream>
#include "Application.h"

using namespace std;



int main (void) {
  try {
    Application pac;

    if(pac.start()) {
      if (pac.initApp()) {
        pac.run();
      }
    }
    cout << "Ending the game" << endl;
  } catch (...) {
    cout << "Exception has been thrown." << endl;
  }
  
  return EXIT_SUCCESS;
}