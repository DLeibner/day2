#pragma once

class point
{
public:
  point(int f = 0, int s = 0);

  bool operator==(const point& other) const;
  bool operator !=(const point& other) const;
  bool operator <(const point& other) const;

private:
  int first;
  int second;
};