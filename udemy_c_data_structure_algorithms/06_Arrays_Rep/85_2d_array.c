#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
  int row = 3;
  int col = 4;
  int i, j;
  
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {0}};
  
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }

  int * arrB[3];
  arrB[0] = (int *)malloc(col * sizeof(int));
  arrB[1] = (int *)malloc(col * sizeof(int));
  arrB[2] = (int *)malloc(col * sizeof(int));
  
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
      printf("%d ", arrB[i][j]);
    printf("\n");
  }

  int ** arrBD;
  arrBD = (int **)malloc(row * sizeof(int *));
  arrBD[0] = (int *)malloc(col * sizeof(int));
  arrBD[1] = (int *)malloc(col * sizeof(int));
  arrBD[2] = (int *)malloc(col * sizeof(int));
  
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
      printf("%d ", arrBD[i][j]);
    printf("\n");
  }

  return 0;
}
