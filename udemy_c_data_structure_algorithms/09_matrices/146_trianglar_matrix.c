#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void setMatrix(struct Matrix *m, int i, int j, int x)
{
  if (i >= j) {
    int index = i*(i-1)/2 + j-1;
    m->A[index] = x;
  }
}

int getMatrix(struct Matrix *m, int i, int j)
{
  if (j < i) return 0;

  int index = i*(i-1)/2 + j-1;
  return m->A[index];
}


void printMatrix(struct Matrix *m)
{
  for (int i = 1; i <= m->n; i++)
  {
    for (int j = 1; j <= m->n; j++)
    {
      if (i >= j)
      {
        printf("%d\t\t", m->A[i*(i-1)/2 + j-1]);
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
  m.A = (int *)malloc(m.n*(m.n-1)*2 * sizeof(int)); // default 0
  
  setMatrix(&m, 1, 1, 3);
  setMatrix(&m, 2, 2, 6);
  setMatrix(&m, 3, 3, 9);
  setMatrix(&m, 4, 1, 7);
  setMatrix(&m, 4, 4, 7);

  printf("%d \n", getMatrix(&m, 2, 1));
  printf("%d \n", getMatrix(&m, 3, 3));
  printf("%d \n", getMatrix(&m, 4, 3));

  printMatrix(&m);
  
  return 0;
}
