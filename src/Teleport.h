#pragma once

#include <memory>
#include "Effect.h"
#include "Pacman.h"

/**
 * @class Teleport
 * @brief The Teleport class represents a teleport effect in the game.
 *
 * This class inherits from the Effect class and teleports player from left to the right side.
 */
class Teleport : public Effect {
public:
  /**
   * @brief Constructs a Teleport object. Parameters are for teleporting to the designated location.
   *
   * @param height The height of the game board.
   * @param width The width of the game board.
   */
  Teleport(int height, int width);

  /**
   * @brief Clones the teleport effect.
   *
   * This function creates a shared pointer of Effect to a new Teleport object 
   * that is a copy of the current instance. Used for polymorphic calling of functions.
   *
   * @return A shared pointer to the cloned teleport effect.
   */
  std::shared_ptr<Effect> clone() const override;

  /**
   * @brief Activates the teleport effect.
   *
   * This function activates the teleport effect. It takes Pacman from one edge of the board to the other.
   *
   * @param state The game state.
   */
  void activate(GameState& state) override;

  /**
   * @brief Prints the teleport object. It is represented by the letter T.
   */
  void printObject() const override;

protected:
  int maxHeight;
  int maxWidth;
};