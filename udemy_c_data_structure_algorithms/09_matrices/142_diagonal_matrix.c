#include <stdio.h>

struct Matrix
{
  int A[10];
  int n;
};

void setMatrix(struct Matrix *m, int i, int j, int x)
{
  if (i == j)
    m->A[i-1] = x;
}

int getMatrix(struct Matrix *m, int i, int j)
{
  if (i == j)
    return m->A[i-1];
  return 0;
}

void printMatrix(struct Matrix *m)
{
  for (int i = 0; i < m->n; i++)
  {
    for (int j = 0; j < m->n; j++)
    {
      if (i == j)
      {
        printf("%d\t\t", m->A[i]);
      } else {
        printf("0\t\t");
      }
      
    }
    printf("\n");
    
  }
  
}

int main(int argc, char const *argv[])
{
  struct Matrix m;
  m.n = 4;
  
  setMatrix(&m, 1, 1, 3);
  setMatrix(&m, 2, 2, 6);
  setMatrix(&m, 3, 3, 9);
  setMatrix(&m, 4, 4, 7);
  setMatrix(&m, 4, 8, 2);

  printf("%d \n", getMatrix(&m, 2, 1));
  printf("%d \n", getMatrix(&m, 3, 3));

  printMatrix(&m);

  return 0;
}
