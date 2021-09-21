#include <iostream>

using namespace std;

class A {
  int k; // private by default
public:
  int i;
protected:
  void f2();
  int j;
};


class B : public A { // public inheritance
  int m;
public:
  void f3();
protected:
  void f4();
};

class C : protected A { // protected inheritance
  int n;
public:
  void f5();
};

/**
 *      i      f2      j       k
 * A    公      保      保       
 * 
 */

int main()
{
  return 0;
}
