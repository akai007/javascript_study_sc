#include <iostream>

using namespace std;

// define function prototype
int gcd(int m, int n);

int main(int argc, char const *argv[])
{
  int m,n;
  cout << "Please enter two numbers: (separate by space)" << endl;
  cin >> m >> n;
  cout << gcd(m, n) << endl;
  return 0;
}

int gcd(int m, int n)
{
  int r = 1;

  while (r != 0)
  {
    r = m % n;
    m = n;
    n = r;
  }

  return m;
}