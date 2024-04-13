#pragma once

#include <iostream>
#include <memory>
#include "GameState.h"
#include "Pacman.h"

/**
 * @class Effect
 * @brief The Effect class represents a game effect.
 *
 * This class provides an interface for different game effects. It is a parent class.
 */
class Effect {
public:
  /**
   * @brief Constructs an Effect object.
   */
  Effect();

  /**
   * @brief Destroys the Effect object.
   */
  ~Effect() = default;

  /**
   * @brief Clones the Effect object.
   *
   * This is an abstract function. The children call this to create a shared pointer of Effect object
   * in order to be able to use polymorphic calling.
   *
   * @return A shared pointer to a new Effect object.
   */
  virtual std::shared_ptr<Effect> clone() const = 0;

  /**
   * @brief Activates the effect. 
   * 
   * This is an abstract function. It activates an Effect of the special game objects.
   * It modifies the game state (like score, powerup...).
   *
   * @param state The current state of the game.
   */
  virtual void activate(GameState& state) = 0;

  /**
   * @brief Prints the effect object.
   *
   * This is an abstract function. It prints the representation of the effect object.
   */
  virtual void printObject() const = 0;

protected:
  bool taken;
};