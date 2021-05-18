#include <stdio.h>

void insert(int A[], int n)
{
  int temp, i = n;
  temp = A[n];

  while (i > 1 && temp > A[i/2])
  {
    A[i] = A[i/2];
    i = i/2;
  }
  A[i] = temp;

}

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int A[] = {40, 25, 30, 10, 5, 20, 35};

  insert(A, 6);
  printArray(A, 6);

  return 0;
}
