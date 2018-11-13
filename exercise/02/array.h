#pragma once
// do not use standard container as member or base class
class array
{
public:
  array();
  array(int size, double value = 0);
  array(const array& other);
  array(array&& other) noexcept;
  ~array();

  int size() const;
  double at(int index) const;

  array& operator=(array other);

private:
  double* p;
  int n;
};
