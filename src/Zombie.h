#pragma once

#include <map>
#include "Ghost.h"
#include "Coord.h"

/**
 * @class Zombie
 * @brief The Zombie class represents a zombie ghost in the game.
 *
 * This class inherits from the Ghost class and provides functionalities and properties for the zombie ghost.
 */
class Zombie : public Ghost {
public:
  /**
   * @brief Constructs a Zombie object with the specified initial coordinates.
   *
   * Sets the default spawn point as well.
   * 
   * @param inY The initial Y-coordinate of the zombie ghost.
   * @param inX The initial X-coordinate of the zombie ghost.
   */
  Zombie(int inY, int inX);

  /**
   * @brief Clones the zombie ghost.
   *
   * This function creates a shared pointer of Ghost to a new Zombie object 
   * that is a copy of the current instance. Used for polymorphic calling of functions.
   *
   * @return A shared pointer to the cloned Zombie ghost.
   */
  std::shared_ptr<Ghost> clone() const override;

  /**
   * @brief Respawns the zombie ghost on the game board.
   *
   * This function respawns the zombie ghost on the specified game board.
   *
   * @param gameboard The game board.
   */
  void respawn(Board& gameboard) override;

  /**
   * @brief Finds the path for the zombie ghost on the game board.
   *
   * This function finds the path for the zombie ghost on the game board. Zombie goes to a random spot.
   *
   * @param gameboard The game board.
   */
  void findPath(Board& gameboard);

  /**
   * @brief Checks for prey near the zombie ghost on the game board.
   *
   * This function checks if the Zombie sees Pacman in his line of sight. If yes, he goes in that direction
   * until he either catches Pacman or hits the wall.
   *
   * @param gameboard The game board.
   */
  void checkPrey(Board& gameboard);

  /**
   * @brief Moves the zombie ghost on the game board.
   *
   * This function moves the zombie ghost on the game board.
   *
   * @param gameboard The game board.
   * @param state The game state.
   */
  void move(Board& gameboard, GameState& state) override;

protected:
  std::map<Coord, Coord> path;
  Coord target;
  bool vision;
  Coord dir;
  bool lastState;
};