#include "array.h"
#include <exception>
#include <stdexcept>

array::array() :
  p(nullptr), n(0)
{
}

array::array(const int size, const double value)
{
  if (size > 0)
  {
    n = size;
    p = new double[size];

    for (int i = 0; i < size; ++i)
    {
      p[i] = value;
    }
  }
  else
  {
    n = 0;
    p = nullptr;
  }
}

array::array(const array& other) :
  p(nullptr), n(0)
{
  n = other.n;

  if (n > 0)
  {
    p = new double[n];

    for (int i = 0; i < n; ++i)
    {
      p[i] = other.p[i];
    }
  }
}

array::array(array&& other) noexcept :
  p(nullptr), n(0)
{
  std::swap(p, other.p);
  std::swap(n, other.n);
}

array::~array()
{
  if (p)
  {
    delete[] p;
    p = nullptr;
  }
}

int array::size() const
{
  return n;
}

double array::at(const int index) const
{
  if (index < 0 || index >= n)
  {
    throw std::out_of_range("index is out of range");
  }

  return p[index];
}

array& array::operator=(array other)
{
  std::swap(p, other.p);
  std::swap(n, other.n);

  return *this;
}
