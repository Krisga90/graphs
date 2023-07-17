#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>

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

void depthFirstPrint(const std::map<char, std::vector<char>> &graph,
                     char start);

#endif // BASIC_H