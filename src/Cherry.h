#pragma once

#include "Effect.h"

/**
 * @class Cherry
 * @brief The Cherry class represents a cherry effect.
 *
 * This class inherits from the Effect class and allows Pacman to hunt ghosts along with increasing score.
 */
class Cherry : public Effect {
public:
  /**
   * @brief Constructs a Cherry object.
   */
  Cherry();

  /**
   * @brief Clones the Cherry object.
   *
   * This function creates a shared pointer of Effect to a new Cherry object 
   * that is a copy of the current instance. Used for polymorphic calling of functions.
   * 
   * @return A shared pointer to a new Effect object.
   */
  std::shared_ptr<Effect> clone() const override;

  /**
   * @brief Activates the cherry effect.
   *
   * This function activates the cherry effect, modifying the game state. It allows the Pacman to hunt down
   * the ghosts and overpower them. It powerups Pacman only once.
   *
   * @param state The current state of the game.
   */
  void activate(GameState& state) override;

  /**
   * @brief Prints the cherry object.
   *
   * This function prints the representation of the cherry object, which is a small 'g'.
   */
  void printObject() const override;
};