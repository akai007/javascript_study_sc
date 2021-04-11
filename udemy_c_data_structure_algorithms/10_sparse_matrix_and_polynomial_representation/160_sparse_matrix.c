#include <stdio.h>
#include <stdlib.h>

struct Element
{
  int i;
  int j;
  int x;
};

struct SparseMatrix
{
  int m;
  int n;
  int num;
  struct Element *eList;
};

void printSparseMatrix(struct SparseMatrix * sm)
{
  for (int m = 0; m < sm->num; m++)
  {
    struct Element item = sm->eList[m];
    printf("%d, %d, %d \n", item.i, item.j, item.x);
  }
  int k = 0;
  for (int i = 0; i < sm->m; i++)
  {
    for (int j = 0; j < sm->n; j++)
    {
      if (sm->eList[k].i == i && sm->eList[k].j == j)
      {
        printf("%d ", sm->eList[k].x);
        ++k;
      } else {
        printf("0 ");
      }
      
    }

    printf("\n");
    
  }
  
}

void create(struct SparseMatrix *sm)
{
  printf("please enter row size: ");
  scanf("%d", &(sm->m));
  printf("please enter col size: ");
  scanf("%d", &(sm->n));
  printf("How many non-zero number do you have: ");
  scanf("%d", &(sm->num));

  sm->eList = (struct Element *)malloc(sm->num * sizeof(struct Element));
  
  printf("Please enter all non-zero numbers: ");

  for (int i = 0; i < sm->num; i++)
  {
    printf("please enter %dth number i: ", i+1);
    scanf("%d", &(sm->eList[i].i));
    printf("enter %dth number j: ", i+1);
    scanf("%d", &(sm->eList[i].j));
    printf("enter %dth number x: ", i+1);
    scanf("%d", &(sm->eList[i].x));
  }
}


int main(int argc, char const *argv[])
{
  struct SparseMatrix s1, s2, s3;
  printf("Num1 \n");
  create(&s1);
  printSparseMatrix(&s1);
  printf("Num2 \n");
  create(&s2);
  printSparseMatrix(&s2);


  return 0;
}
