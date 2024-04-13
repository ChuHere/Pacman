#pragma once

/**
 * @struct Coord
 * @brief The Coord struct represents a coordinate in 2D space.
 *
 * This struct stores the x and y coordinates of an object in 2D space.
 */
struct Coord {
  int x;
  int y;

  /**
   * @brief Less-than comparison operator for Coord objects.
   *
   * This operator compares two Coord objects based on their x and y coordinates.
   *
   * @param left The left-hand side Coord object.
   * @param right The right-hand side Coord object.
   * @return True if left is less than right, false otherwise.
   */
  friend bool operator<(const Coord& left, const Coord& right);

  /**
   * @brief Equality comparison operator for Coord objects.
   *
   * This operator compares two Coord objects based on their x and y coordinates for equality.
   *
   * @param left The left-hand side Coord object.
   * @param right The right-hand side Coord object.
   * @return True if left is equal to right, false otherwise.
   */
  friend bool operator==(const Coord& left, const Coord& right);

  /**
   * @brief Inequality comparison operator for Coord objects.
   *
   * This operator compares two Coord objects based on their x and y coordinates for inequality.
   *
   * @param left The left-hand side Coord object.
   * @param right The right-hand side Coord object.
   * @return True if left is not equal to right, false otherwise.
   */
  friend bool operator!=(const Coord& left, const Coord& right);
};