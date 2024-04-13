#pragma once

#include "Effect.h"

/**
 * @class Coin
 * @brief The Coin class represents a coin effect.
 *
 * This class inherits from the Effect class and increases the score of Pacman.
 */
class Coin : public Effect {
public:
  /**
   * @brief Constructs a Coin object.
   */
  Coin();

  /**
   * @brief Clones the Coin object.
   *
   * This function creates a shared pointer of Effect to a new Coin object 
   * that is a copy of the current instance. Used for polymorphic calling of functions.
   *
   * @return A shared pointer to a new Coin object.
   */
  std::shared_ptr<Effect> clone() const override;

  /**
   * @brief Activates the coin effect.
   *
   * This function activates the coin effect and increases the score if it hasn't been used yet.
   *
   * @param state The current state of the game.
   */
  void activate(GameState& state) override;

  /**
   * @brief Prints the coin object.
   *
   * This function prints the representation of the coin object, which is a dot.
   */
  void printObject() const override;
};