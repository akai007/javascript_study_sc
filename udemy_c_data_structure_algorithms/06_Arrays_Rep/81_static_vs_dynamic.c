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
  // static array
  int staticArr[5] = {1, 2, 3, 4, 5};
  printArray("staticArr \t", staticArr, 5);

  int *dynamicArr = (int *)malloc(5 * sizeof(int));
  dynamicArr[0] = 2;
  dynamicArr[1] = 4;
  dynamicArr[2] = 6;
  dynamicArr[3] = 8;
  dynamicArr[4] = 10;
  printArray("dynamicArr \t", dynamicArr, 5);

  free(dynamicArr);

  return 0;
}
