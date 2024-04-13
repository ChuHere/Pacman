#pragma once

#include "Ghost.h"
#include "Coord.h"
#include "Board.h"
#include "GameState.h"

/**
 * @class Dumb
 * @brief The Dumb class represents a dumb ghost.
 *
 * This class inherits from the Ghost class and implements specific behaviors for a dumb ghost.
 */
class Dumb : public Ghost {
public:
  /**
   * @brief Constructs a Dumb object.
   *
   * Sets spawn point as well.
   * 
   * @param inY The initial Y-coordinate of the Dumb ghost.
   * @param inX The initial X-coordinate of the Dumb ghost.
   */
  Dumb(int inY, int inX);

  /**
   * @brief Clones the Dumb object.
   *
   * This function creates a shared pointer of Ghost to a new Dumb object 
   * that is a copy of the current instance. Used for polymorphic calling of functions.
   * 
   * @return A shared pointer to a new Dumb object.
   */
  std::shared_ptr<Ghost> clone() const override;

  /**
   * @brief Respawns the Dumb ghost.
   *
   * This function respawns the Dumb ghost on the game board on its default spawn point.
   *
   * @param gameboard The game board.
   */
  void respawn(Board& gameboard) override;

  /**
   * @brief Checks if the direction is the reverse direction of the recent direction.
   *
   * This function checks if the specified direction is the reverse direction of the recent direction.
   * So it isn't going just back and forth.
   *
   * @param checkDir The direction to check.
   * @return True if the direction is the reverse direction, false otherwise.
   */
  bool isReverseDir(Coord& checkDir);

  /**
   * @brief Moves the Dumb ghost.
   *
   * This function moves the Dumb ghost on the game board based on. The Dumb ghost moves completely random
   * at all times.
   *
   * @param gameboard The game board.
   * @param state The current state of the game.
   */
  void move(Board& gameboard, GameState& state) override;

private:
  Coord recentDir;
};