#include "point.h"

point::point(int f, int s) :
  first(f), second(s)
{
}

bool point::operator==(const point& other) const
{
  return first == other.first && second == other.second;
}

bool point::operator !=(const point& other) const
{
  return !(first == other.first && second == other.second);
}

bool point::operator <(const point& other) const
{
  return first < other.first || second < other.second;
}
