#include <iostream>

using namespace std;

int main()
{
  int a = 10;
  int &refA = a;
  // int &refA;  error: reference must to init

  int b = a;
  a = 25;
  

  cout<<"a:"<<a<<"\t"<<"b:"<<b<<"\t"<<"refA:"<<refA<<endl;

}