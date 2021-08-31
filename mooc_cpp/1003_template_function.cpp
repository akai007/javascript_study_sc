#include <iostream>

using namespace std;

template <typename T> T add(T a, T b)
{
  return a + b;
}

int main()
{
  cout << "int add: " << add(1, 2) << endl;
  cout << "double add: " << add(1.2, 2.2) << endl;

  return 0;
}
