#pragma once

#include <iostream>
#include "Effect.h"
#include "GameState.h"
#include "Coord.h"

/**
 * @class BoardTile
 * @brief The BoardTile class represents a single tile on the game board.
 *
 * This class manages the effect's, pacman's and the ghost's presence on a tile of the game board.
 */
class BoardTile {
public:
  /**
   * @brief Constructs a BoardTile object.
   *
   * @param object A shared pointer to a polymorphic Effect object.
   * @param gh The number of ghosts on the tile.
   * @param pc Indicates Pacman is present on the tile.
   * @param walk Indicates if the tile is walkable.
   */
  BoardTile(std::shared_ptr<Effect> object, int gh, bool pc, bool walk);

  /**
   * @brief Default constructor for the BoardTile class.
   */
  BoardTile() = default;

  /**
   * @brief Destructor for the BoardTile class.
   */
  ~BoardTile();

  /**
   * @brief Checks for collision between the Pacman and ghosts.
   *
   * @return True if there is a collision, false otherwise.
   */
  bool checkCollision();

  /**
   * @brief Checks if the tile contains Pacman.
   *
   * @return True if the tile contains Pacman, false otherwise.
   */
  bool checkPacman();

  /**
   * @brief Checks if the tile is walkable.
   *
   * @return True if the tile is walkable, false otherwise.
   */
  bool canWalk();

  /**
   * @brief Actives the Effect present on the tile (if it hasn't been activated yet) and changes the game state.
   *
   * @param state The GameState object representing the current state of the game.
   */
  void changeState(GameState& state);

  /**
   * @brief Sets the presence of Pacman on the tile.
   *
   * @param x Indicates if Pacman is present on the tile.
   */
  void setPac(bool x);

  /**
   * @brief Adds a ghost to the tile.
   */
  void addGhost();

  /**
   * @brief Removes a ghost from the tile.
   */
  void delGhost();

  /**
   * @brief Prints the tile (Effect) or Pacman/ghost if they are present on the board.
   *
   * \param state The GameState object representing the current state of the game.
   */
  void printTile(GameState& state);

private:
  std::shared_ptr<Effect> obj;
  int ghost;
  bool pacman;
  bool walkable;
};