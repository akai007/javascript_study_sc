#include <stdio.h>


void printArray(char nameFlag, int *arr, int len)
{
  printf("%c : ", nameFlag);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


int main(int argc, char const *argv[])
{
  

  int A[5];
  printArray('A', A, 5);

  int B[5] = {1, 2, 3, 4, 5};
  printArray('B', B, 5);

  int C[10] =  {2, 4, 6};
  printArray('C', C, 10);

  int D[5] = {-1};
  printArray('D', D, 5);

  int E[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printArray('E', E, 10);

  return 0;
}
