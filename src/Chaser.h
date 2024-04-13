#pragma once

#include <map>
#include "Ghost.h"
#include "Coord.h"

/**
 * @class Chaser
 * @brief The Chaser class represents a type of ghost that chases the Pacman.
 *
 * This class inherits from the Ghost class and implements specific behaviors for a chasing ghost.
 */
class Chaser : public Ghost {
public:
  /**
   * @brief Constructs a Chaser object.
   * 
   * Sets default spawn as well.
   *
   * @param inY The initial Y-coordinate of the Chaser.
   * @param inX The initial X-coordinate of the Chaser.
   */
  Chaser(int inY, int inX);

  /**
   * @brief Clones the Chaser object.
   *
   * This function creates a shared pointer of Ghost to a new Chaser object 
   * that is a copy of the current instance. Used for polymorphic calling of methods.
   *
   * @return A shared pointer to a Ghost object.
   */
  std::shared_ptr<Ghost> clone() const override;

  /**
   * @brief Respawns the Chaser.
   *
   * This function respawns the Chaser on the game board in his set spawnpoint.
   *
   * @param gameboard The game board.
   */
  void respawn(Board& gameboard);

  /**
   * @brief Finds the path to the target.
   *
   * This function finds the path from the Chaser to the target location on the game board.
   * It uses the BFS algorithm
   *
   * @param gameboard The game board.
   * @param target The target coordinates.
   */
  void findPath(Board& gameboard, Coord& target);

  /**
   * @brief Moves to the target location.
   *
   * This function moves to the target location of the chased target.
   *
   * @param gameboard The game board.
   * @param target The target coordinates.
   */
  void moveTarget(Board& gameboard, Coord& target);

  /**
   * @brief Calls the rest of the moving mechanisms.
   *
   * This function uses the rest of the Chaser functions to move the ghost. Keeps track of the state of the game
   * and decides on its behaviour based on that.
   *
   * @param gameboard The game board.
   * @param state The current state of the game.
   */
  void move(Board& gameboard, GameState& state) override;

private:
  Coord targetRun;
  bool lastState;
  std::map<Coord, Coord> path;
};