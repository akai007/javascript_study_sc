#include <stdio.h>

int recursionSum(int n) 
{
  if (n <= 0) return 0;

  return recursionSum(n - 1) + n;
}

int loopSum(int n)
{
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum = sum + i;
  
  return sum;
}

int formulaSum(int n)
{
  return n * (n + 1) / 2;
}

int main(int argc, char const *argv[])
{
  printf("formulaSum \t\t %d \n", formulaSum(100));
  printf("loopSum \t\t\t %d \n", loopSum(100));
  printf("recursionSum \t %d \n", recursionSum(100));

  return 0;
}
