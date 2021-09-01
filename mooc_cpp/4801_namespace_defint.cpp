#include <iostream>
using namespace std;

int i = 10;

namespace { // 匿名命名空间
  int x = 1;
  void output(){ cout << ::i; }; // ::全局作用域
}

namespace A {
  int i, j; // 变量

  namespace { // 匿名命名空间
    int x = 2;
  }

  const double PI = 3.1415926; // 常量
  string str("Hello");
  typedef int ElemType;
  ElemType min(ElemType x, ElemType y);
  int max(int x, int y) {return x>y? x:y;}
  template<typename T> T add(T x, T y);
  
  namespace B {
    int i, j;
  }
}

void printA() {
  cout << A::i;
}

namespace A {
  int extraI;
}

A::ElemType A::min(A::ElemType a, A::ElemType b)
{
  return a<b? a:b;
}

int main(int argc, char const *argv[])
{

  return 0;
}

