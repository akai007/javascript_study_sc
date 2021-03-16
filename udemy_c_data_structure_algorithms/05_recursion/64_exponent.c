#include <stdio.h>

int recursionPow(int m, int n)
{
  if (n == 1)
    return m * 1;
  
  return recursionPow(m, n-1) * m;
}

int recursionOptimizePow(int m, int n)
{
  if (n == 1)
    return m * 1;
  if (n % 2 == 0)
    return recursionOptimizePow(m * m, n / 2);
  return recursionOptimizePow(m * m, n / 2) * m;
  
}

int loopPow(int m, int n)
{
  int sum = 1;
  for (int i = 0; i < n; i++)
  {
    sum = sum * m;
  }

  return sum;
}

int main(int argc, char const *argv[])
{
  printf("recursionPow \t\t\t\t\t%d \n", recursionPow(2, 9));
  printf("recursionOptimizePow \t%d \n", recursionOptimizePow(2, 9));
  printf("loopPow \t\t\t\t\t\t\t%d \n", loopPow(2, 9));

  return 0;
}
