#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int arr[3];
  int arrB[] = {2, 4, 6, 8, 10};
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;


  printf("start \n");
  cout<<sizeof(arr)<<endl;
  cout<<sizeof(arr[1])<<endl;
  cout<<sizeof(arrB)<<endl;

  printf("loop arrB \n");
  int n;
  cout<<"Enter Size";
  cin>>n;

  for (int i = 0; i < n; i++)
  {
    cout<<arrB[i]<<endl;
  }
  // for (int b:arr)
  // {
  //   cout<<b<<endl;
  // }
  

  return 0;
}
