#pragma once

#include <string>
#include <vector>
#include <memory>
#include "GameState.h"
#include "BoardTile.h"
#include "Coord.h"

/**
 * @class Board
 * @brief The Board class represents the game board.
 *
 * This class manages the game board, including its dimensions, tiles, and coordinates of the Pacman.
 */
class Board {
public:
  size_t height;
  size_t width;
  std::vector<std::vector<BoardTile>> boardMap;
  Coord pacmanCoords;

  /**
   * @brief Constructs a Board object.
   *
   * This is the default constructor for the Board class.
   */
  Board() = default;

  /**
   * @brief Destroys the Board object.
   *
   * This is the default destructor for the Board class.
   */
  ~Board() = default;

  /**
   * @brief Prints the game board.
   *
   * This function prints the current state of the game board.
   *
   * @param state The GameState object representing the current state of the game.
   */
  void printBoard(GameState& state);

  /**
   * @brief Sets the coordinates of the Pacman.
   *
   * This function sets the coordinates of the Pacman on the game board.
   *
   * @param a The coordinates of the Pacman.
   */
  void setPacmanCoords(Coord a);

  /**
   * @brief Checks for collision.
   *
   * This function checks if there was a collison between the player and a ghost.
   *
   * @return True if there is a collision, false otherwise.
   */
  bool checkCollision();
};