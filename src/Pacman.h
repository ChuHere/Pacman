#pragma once

#include <string>
#include "Coord.h"
// #include "Board.h"

/**
 * @class Pacman
 * @brief The Pacman class represents the player character in the game.
 *
 * This class provides functionalities and properties for the Pacman character, such as position and movement.
 */
class Pacman {
public:
  /**
   * @brief Constructs a Pacman object with the specified initial coordinates.
   *
   * Sets the default spawn point as well.
   * 
   * @param inY The initial Y-coordinate of Pacman.
   * @param inX The initial X-coordinate of Pacman.
   */
  Pacman(int inY, int inX);

  /**
   * @brief Constructs a default Pacman object.
   */
  Pacman();

  /**
   * @brief Sets the coordinates of Pacman.
   *
   * @param a The coordinates to set.
   */
  void setCoords(Coord a);

  /**
   * @brief Reads the input for Pacman's movement.
   *
   * This function reads the user's input for Pacman's movement and returns true if a valid input was read,
   * or false otherwise.
   *
   * @param out The output string to store the input.
   * @return True if a valid input was read, false otherwise.
   */
  bool readInput(std::string& out);

  /**
   * @brief Moves Pacman on the game board.
   *
   * This function moves Pacman on the game board based on the current input and returns true if the movement
   * was successful, or false otherwise.
   *
   * @return True if the movement was successful, false otherwise.
   */
  bool move();


  Coord coords;
  Coord nextCoords;
  Coord spawn;
};