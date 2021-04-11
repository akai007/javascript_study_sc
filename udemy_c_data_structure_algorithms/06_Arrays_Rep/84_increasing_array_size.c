#include <stdio.h>
#include <stdlib.h>

void printArray(char *name, int *arr, int len)
{
  printf("%s : ", name);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int *arr;
  arr = (int *)malloc(5*sizeof(int));
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 1;
  arr[4] = 1;

  int * increase;
  increase = (int *)malloc(10*sizeof(int));
  // copy
  for (int i = 0; i < 5; i++)
  {
    increase[i] = arr[i];
  }

  free(arr);
  arr = increase;
  increase = NULL;

  arr[5] = 2;
  arr[6] = 2;
  arr[7] = 2;
  arr[8] = 2;
  arr[9] = 2;
  printArray("arr after creasing \t", arr, 10);

  return 0;
}
