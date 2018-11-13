#pragma once
#include <windows.h>

class color
{
public:
  color(double r = 0.0, double g = 0.0, double b = 0.0);

  double get_red() const;
  double get_green() const;
  double get_blue() const;

  void set_red(double value);
  void set_green(double value);
  void set_blue(double value);

  bool operator==(const color& other) const;

  COLORREF get_color_ref() const;
  double get_luminance() const;

private:
  double red;
  double green;
  double blue;
};
