#include <stdio.h>

void insert(int A[], int n)
{
  int temp, i = n;
  temp = A[n];

  while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
      A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
      i = i % 2 == 0 ? (i/2)-1 : i/2;
  }
  A[i] = temp;

}

void createHeap(int A[], int n)
{
  for (int i = 2; i <= n; i++)
  {
    insert(A, i);
  }
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
  int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
  createHeap(A, 8);
  printArray(A, 8);

  return 0;
}
