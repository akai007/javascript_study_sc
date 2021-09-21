#include <iostream>

using namespace std;

class Base { // 基类
private:
  int bNumber;
public:
  Base(int i = 0) : bNumber(i) {}
  int getNumber() {
    return bNumber;
  }
  void print() {
    cout << bNumber << endl;
  }
};

class Derived : public Base { // 派生类
private:
  int dNumber; // 派生类增加的数据成员
public:
  Derived(int i, int j) : Base(i), dNumber(j) {}; // 派生类 构造函数
  void print() {
    cout << getNumber() << "  "; // 派生类继承的成员函数
    cout << dNumber << endl;
  }
};

int main() {
  Base a(2);
  Derived b(3, 4);

  cout << "a is "; a.print();
  cout << "b is "; b.print();
  cout << "base part of b is ";
  b.Base::print();
  
  return 0;
}