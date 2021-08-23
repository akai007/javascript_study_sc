#include <iostream>

using namespace std;

int isPrime(int x) {
  if (x == 1) return 0;
  for (int i = 2; i < x; i++)
  {
    if (x%i == 0) return 0;
  }
  return 1;
}

int main(int argc, char const *argv[])
{

  int x;
  cout << "please enter a number: ";
  cin >> x;

  if ( isPrime(x) ) {
    cout << "Is a prime number!" << endl;
  } else {
    cout << "Is not a prime number!" << endl;
  }
  
  return 0;
}
