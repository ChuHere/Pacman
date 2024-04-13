#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "Config.h"
#include "Board.h"
#include "GameState.h"
#include "Pacman.h"
#include "Ghost.h"

/**
 * @class Game
 * @brief The Game class represents the game.
 *
 * This class manages the game logic and provides functions for initializing and running the game.
 */
class Game {
public:
  /**
   * @brief Constructs a Game object.
   */
  Game() = default;

  /**
   * @brief Destroys the Game object.
   */
  ~Game() = default;

  /**
   * @brief Checks if the game configuration is valid.
   *
   * This function checks if the game configuration is valid. It checks the config and the map.
   *
   * @return True if the game configuration is valid, false otherwise.
   */
  bool checkValid();

  /**
   * @brief Loads the game board from a file.
   *
   * This function loads the game board from the specified file.
   *
   * @param file The file to load the game board from.
   */
  void loadBoard(std::string file);

  /**
   * @brief Initializes the game.
   *
   * This function mainly initializes Pacman position.
   *
   * @return True if the game was successfully initialized, false otherwise.
   */
  bool initGame();

  /**
   * @brief Respawns the Pacman.
   *
   * This function respawns the Pacman on the game board in his default spawn point.
   */
  void respawnPac();

  /**
   * @brief Respawns the figures (Ghosts and Pacman).
   *
   * This function respawns all of the figures on the game board.
   */
  void respawnFigures();

  /**
   * @brief Moves the Pacman.
   *
   * This function moves the Pacman on the game board.
   */
  void pacMove();

  /**
   * @brief Runs the game.
   *
   * This function runs the game, handling the main game loop. This function represents one
   * turn of Pacman (optionally two).
   */
  void run();

  /**
   * @brief Checks the game status.
   *
   * This function checks the game status to determine if the game is over.
   *
   * @return True if the game is over, false otherwise.
   */
  bool checkGame();

  /**
   * @brief Adds the player's information to the leaderboard.
   *
   * This function adds the player's information (username, score, lives) to the leaderboard.
   */
  void addLeaderboard();

  /**
   * @struct PlayerInfo
   * @brief The PlayerInfo struct represents the information of a player.
   */
  struct PlayerInfo {
    std::string username;
    int score;
    int lives;
  };

private:
  Config conf;
  Board gameBoard;
  GameState state;
  std::vector<std::shared_ptr<Ghost>> ghosts;
  std::shared_ptr<Pacman> pac = std::make_shared<Pacman>();
};