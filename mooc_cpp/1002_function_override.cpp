#include <iostream>

using namespace std;

int max(int a, int b) { cout << " int max fun "; return a > b ? a : b; }
int max(double a, double b) { cout << " double max fun "; return a > b ? a : b; }
int max(int a, int b, int c) { cout << " treble int max fun "; return max(max(a,b),c); }
int max(double a, double b, int c) { cout << " double double and one int max fun "; return max(max(a,b),c); }

int main(int argc, char const *argv[])
{
  cout << max(1, 2) << endl;
  cout << max(1.2, 2.0) << endl;
  cout << max(1, 2, 3) << endl;
  cout << max(1.2, 4.4, 3) << endl;
  return 0;
}
