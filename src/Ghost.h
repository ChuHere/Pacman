#pragma once

#include <list>
#include "Board.h"
#include "GameState.h"

/**
 * @class Ghost
 * @brief The Ghost class represents a ghost in the game.
 *
 * This class represents the parent class of ghosts. Includes abstract methods.
 */
class Ghost {
public:
  /**
   * @brief Constructs a Ghost object with the specified initial coordinates.
   *
   *  Sets default spawn point as well.
   * 
   * @param inY The initial Y-coordinate of the ghost.
   * @param inX The initial X-coordinate of the ghost.
   */
  Ghost(int inY, int inX);

  /**
   * @brief Destroys the Ghost object.
   */
  ~Ghost();

  /**
   * @brief Checks if the ghost is with Pacman.
   *
   * This function checks if the ghost is on the same coordinates as Pacman.
   *
   * @param gameboard The game board.
   * @param state The game state.
   * @return True if the ghost is on Pacman's coordinates, false otherwise.
   */
  bool checkPac(Board& gameboard, GameState& state);

  /**
   * @brief Clones the ghost.
   *
   * This is an abstract method.
   * This function creates a new instance of the ghost and returns it as a shared pointer.
   *
   * @return A shared pointer to the cloned ghost.
   */
  virtual std::shared_ptr<Ghost> clone() const = 0;

  /**
   * @brief Moves the ghost on the game board.
   *
   * This is an abstract method.
   * This function moves the ghost on the specified game board and game state.
   *
   * @param gameboard The game board.
   * @param state The game state.
   */
  virtual void move(Board& gameboard, GameState& state) = 0;

  /**
   * @brief Respawns the ghost on the game board.
   *
   * This is an abstract method.
   * This function respawns the ghost on the specified game board.
   *
   * @param gameboard The game board.
   */
  virtual void respawn(Board& gameboard) = 0;

protected:
  Coord coords;
  Coord spawn;
};