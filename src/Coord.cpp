#include "Coord.h"

bool operator< (const Coord &left, const Coord &right) {
  if (left.x == right.x) return left.y < right.y;
  return left.x < right.x;
}

bool operator== (const Coord &left, const Coord &right) {
  if (left.x == right.x && left.y == right.y) return true;
  return false;
}

bool operator!= (const Coord &left, const Coord &right) {
  return !(left == right);
}