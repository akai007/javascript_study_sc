
#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int arr[ ], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}

int * createArray(int size)
{
  int *arr;

  arr = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    arr[i] = i + 1;
  }
  
  return arr;
}

int main()
{
  int size = 5;
  int *arr = createArray(size);

  printArray(arr, size);

  return 0;
}