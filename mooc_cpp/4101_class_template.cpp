#include <iostream>

using namespace std;

template <class T>
class Point {
  T x, y;
public:
  Point() : x(0), y(0) {} // 默认构造函数
  Point(const T a, const T b) : x(a), y(b) {}

  void set(const T a, const T b);
  void dispay() {
    cout << "Dispaly: " << "x=" << x << ", y=" << y << endl;
  }
};

int main(int argc, char const *argv[])
{
  Point <int> a, b; // 调用默认构造函数
  a.dispay();
  b.dispay();

  Point <double> m(1.1, 2.2), n(3.3, 4.4); // 定义类模板对象
  m.dispay();
  n.dispay();
  return 0;
}
