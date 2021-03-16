#include <stdio.h>

int recursionFact(int n)
{
  if (n <= 0) return 1;

  return recursionFact(n - 1) * n;
}

int loopFact(int n) {
  int sum = 1;
  for (int i = 1; i <= n; i++)
  {
    sum = sum * i;
  }

  return sum;
}

int main(int argc, char const *argv[])
{
  printf("recursionFact \t %d \n", recursionFact(6));
  printf("loopFact \t\t\t\t %d \n", loopFact(6));
  return 0;
}
