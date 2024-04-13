#pragma once

#include <memory>
#include "Pacman.h"

/**
 * @class GameState
 * @brief The GameState class represents the state of the game.
 *
 * This class stores the current state of the game, including the score, lives, powerup status,
 * duration of the powerup, difficulty, turncounter of powerup, available points, and Pacman object.
 */
class GameState {
public:
  int score;
  int lives;
  bool powerup;
  int duration; /**< The duration of a powerup. */
  int difficulty;
  int turnCounter; /**< The remaining duration of the powerup. */
  int pointsAvailable;
  std::shared_ptr<Pacman> pac;

  /**
   * @brief Constructs a GameState object.
   */
  GameState();

  /**
   * @brief Destroys the GameState object.
   */
  ~GameState() = default;

  /**
   * @brief Gets the current score.
   *
   * @return The current score.
   */
  int getScore();

  /**
   * @brief Gets the remaining lives.
   *
   * @return The remaining lives.
   */
  int getLives();

  /**
   * @brief Sets the Pacman object. Assigns it the variable pac.
   *
   * @param p The Pacman object to set.
   */
  void setPac(std::shared_ptr<Pacman>& p);

  /**
   * @brief Initializes the turnCounter to the duration of a powerup.
   */
  void initDuration();

  /**
   * @brief Prints the state of the game (turnCounter, pointsAvailable, score, lives). 
   */
  void printState();
};