#ifndef BASIC_H
#define BASIC_H
#include <iostream>
#include <memory>

class A {
public:
  A(int val) : m_value{val} { std::cout << "A()\n"; }
  ~A() { std::cout << "~A()\n"; }

  int operator+(int val) {
    m_value += val;
    return m_value;
  }
  int operator+=(int val) { return operator+(val); }
  int operator*() { return m_value; }
  int value() const { return m_value; }

private:
  int m_value;
};

#endif // BASIC_H