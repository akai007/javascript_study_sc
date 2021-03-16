#include <stdio.h>

double e(int x, int n) {
  static double pow = 1, factor = 1;

  double r;
  if (n==0) return 1;

  r = e(x, n - 1);
  pow = pow * x;
  factor = factor + n;

  return r + pow / factor;
}

int main(int argc, char const *argv[])
{
  printf("%lf", e(3, 10));
  return 0;
}
