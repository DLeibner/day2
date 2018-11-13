#include "stdafx.h"
#include "color.h"
#include <algorithm>

const double color_min = 0.0;
const double color_max = 1.0;

color::color(double r, double g, double b) :
    red(std::clamp(r, color_min, color_max)),
    green(std::clamp(g, color_min, color_max)),
    blue(std::clamp(b, color_min, color_max))
{ }

double color::get_red() const
{
  return red;
}

double color::get_green() const
{
  return green;
}

double color::get_blue() const
{
  return blue;
}

void color::set_red(const double value)
{
  red = std::clamp(value, color_min, color_max);
}

void color::set_green(const double value)
{
  green = std::clamp(value, color_min, color_max);
}

void color::set_blue(const double value)
{
  blue = std::clamp(value, color_min, color_max);
}

bool color::operator==(const color& other) const
{
  return red == other.red && green == other.green && blue == other.blue;
}

COLORREF color::get_color_ref() const
{
  return RGB(static_cast<BYTE> (red * 255),
    static_cast<BYTE> (green * 255),
    static_cast<BYTE> (blue * 255));
}

double color::get_luminance() const
{
  return 0.2126 * red + 0.7152 * green + 0.0722* blue;
}
