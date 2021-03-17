#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fibR(int n)
{
  if (n <= 1)
    return n;

  return fibR(n - 2) + fibR(n - 1);
}

int fibRX(int n)
{
  static bool flag = false;
  static int *store;
  if (!flag) {
    store = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
      store[i] = -1;
    flag = true;
  }
  
  if (n <= 1)
  {
    store[n] = n;
    return n;
  }

  if (store[n-2] == -1)
    store[n-2] = fibRX(n-2);
  
  if (store[n-1] == -1)
    store[n-1] = fibRX(n-1);

  return store[n-2] + store[n-1];
}

int fibL(int n)
{
  if (n <= 1)
    return n;

  int sum = 0;
  int t0 = 0;
  int t1 = 1;

  for (int i = 2; i <= n; i++)
  {
    sum = t0 + t1;
    t0 = t1;
    t1 = sum;
  }

  return sum;
}

int main(int argc, char const *argv[])
{
  printf("fibL \t\t %d \n", fibL(6));
  printf("fibR \t\t %d \n", fibR(6));
  printf("fibRX \t %d \n", fibRX(6));

  return 0;
}
