#include <iostream>

using namespace std;

class complex {
private:
  double real; // 实数部分
  double imag; // 虚部
public:
  complex(double r = 0, double i = 0): real(r), imag(i) {}

  complex operator +(const complex &a);
  friend complex operator -(const complex &a, const complex &b) { // 友元 重载运算符 效果一样
    complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
  }

  // 自增 自减
  complex operator ++() { // 先自增
    complex c;
    real++;
    imag++;
    c.real = real;
    c.imag = imag;

    return c;
  }
  friend complex operator --(const complex &a, int) {
    complex c;
    c.real = a.real;
    c.imag = a.imag;
    c.real--;
    c.imag--;

    return c;
  }
  
};

complex complex::operator + (const complex &a) {
  complex c;
  c.real = a.real + real;
  c.imag = a.imag + imag;
  return c;
}

// TODO 为什么会报错 error: overloaded 'operator-' must be a unary or binary operator (has 3 parameters)
// complex complex::operator - (const complex &a, const complex &b) {
//   complex c;
//   c.real = a.real - b.real;
//   c.imag = a.imag - b.imag;
//   return c;
// }


int main() {
  complex c1(1, 2), c2, c3;
  

}