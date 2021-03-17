#include <stdio.h>

double e(int x, int n) {
  static double pow = 1, factor = 1;

  double sum;
  if (n==0) return 1;

  sum = e(x, n - 1);
  pow = pow * x;
  factor = factor * n;

  return sum + pow / factor;
}

double loopE(int x, int n)
{
  double sum = 1;
  double pow = 1;
  double factor = 1;

  for (int i = 1; i <= n; i++)
  {
    pow = pow * x;
    factor = factor * i;
    sum = sum + pow / factor;
  }

  return sum;
}

int main(int argc, char const *argv[])
{
  printf("%lf \n", e(1, 10));
  printf("%lf \n", loopE(1, 10));
  return 0;
}
