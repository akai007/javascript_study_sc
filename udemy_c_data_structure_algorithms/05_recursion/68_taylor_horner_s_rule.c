#include <stdio.h>
// should think more

double hornerE(int x, int n)
{
  static double r = 1;

  if (n == 0)
    return r;

  r = 1 + ((double)x / n * r);

  return hornerE(x, n - 1);
}

double loopHornerE(int x, int n)
{
  double r = 1;
  for (int i = n; i > 0; i--)
  {
    r = 1 + ((double)x / i * r);
  }

  return r;
}

int main(int argc, char const *argv[])
{
  printf("%f \n", loopHornerE(2, 10));
  printf("%f \n", hornerE(2, 10));

  return 0;
}
