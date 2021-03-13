
#include <iostream>
#include <stdio.h>

using namespace std;

void swap(int x, int y) {
  int t;

  x = t;
  x = y;
  y = t;
}

void swapX(int *x, int *y) {
  int t;
  cout<<x<<"\t"<<y<<endl;
  t = *x;
  *x = *y;
  *y = t;
}

void swapS(int &x, int &y) { // will up into main function stack
  int t;

  t = x;
  x = y;
  y = t;
}

int main(int argc, char const *argv[])
{
  int a = 1;
  int b = 3;

  cout<<endl<<"passing value"<<endl;
  cout<<"before swap:\t a:"<<a<<"\t b:"<<b<<endl;
  swap(a, b);
  cout<<"after swap:\t a:"<<a<<"\t b:"<<b<<endl;

  cout<<endl<<"passing pointer"<<endl;
  cout<<"before swapX:\t a:"<<a<<"\t b:"<<b<<endl;
  cout<<&a<<"\t"<<&b<<endl;
  swapX(&a, &b);
  cout<<"after swapX:\t a:"<<a<<"\t b:"<<b<<endl;
  
  cout<<endl<<"alias params(put function into here)"<<endl;
  cout<<"before swapX:\t a:"<<a<<"\t b:"<<b<<endl;
  swapS(a, b);
  cout<<"after swapX:\t a:"<<a<<"\t b:"<<b<<endl;

  return 0;
}
