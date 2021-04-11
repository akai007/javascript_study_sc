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

struct SparseMatrix * addSparseMatrix(struct SparseMatrix *sm1, struct SparseMatrix *sm2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    struct SparseMatrix *sumSm;
    sumSm = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    sumSm->eList = (struct Element *)malloc((sm1->num + sm2->num)* sizeof(struct Element));

    while (i < sm1->num && j < sm2->num)
    {
        if (sm1->eList[i].i < sm2->eList[j].i)
        {
            sumSm->eList[k] = sm1->eList[i];
            k++, i++;
        }
        else if (sm1->eList[i].i > sm2->eList[j].i)
        {
            sumSm->eList[k] = sm1->eList[j];
            k++, j++;
        } else {

            if (sm1->eList[i].j < sm2->eList[j].j)
            {
                sumSm->eList[k] = sm1->eList[i];
                k++, i++;
            }
            else if (sm1->eList[i].j > sm2->eList[j].j)
            {
                sumSm->eList[k] = sm1->eList[j];
                k++, j++;
            } else {
                sumSm->eList[k] = sm1->eList[i];
                sumSm->eList[k].x = sm1->eList[i].x + sm2->eList[j].x;
                k++, i++, j++;
            }

        }
    }
    for (; i < sm1->num; i++)
    {
      sumSm->eList[k] = sm1->eList[i];
      k++;
    }
    for (; j < sm1->num; j++)
    {
      sumSm->eList[k] = sm2->eList[j];
      k++;
    }
    sumSm->m = sm1->m;
    sumSm->n = sm1->n;
    sumSm->num = k;
    
    return sumSm;
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
  struct SparseMatrix s1, s2, *s3;
  s3 = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));

  printf("Num1 \n");
  create(&s1);
  printSparseMatrix(&s1);
  printf("Num2 \n");
  create(&s2);
  printSparseMatrix(&s2);

  printf("Num3 start \n");
  s3 = addSparseMatrix(&s1, &s2);
  printf("Num3 start \n");
  printSparseMatrix(s3);
  printf("Num3 end \n");

  return 0;
}
