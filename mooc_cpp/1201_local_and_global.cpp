#include <iostream>

using namespace std;

int x = 3, y = 4;

void swap(int a, int b)
{
  int t = a;
  a = b;
  b = a;
}

void swap()
{
  int t = x;
  x = y;
  y = t;
}

int main(int argc, char const *argv[])
{
  swap();
  cout << "x = " << x << "; y = " << y << endl;

  swap(x, y);
  cout << "x = " << x << "; y = " << y << endl;

  return 0;
}
