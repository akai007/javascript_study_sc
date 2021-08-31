#include <iostream>

using namespace std;

// inline function
inline int square(int x)
{
  return x*x;
}

int main(int argc, char const *argv[])
{
  int m = 3;
  cout << square(m) << endl;
  return 0;
}
