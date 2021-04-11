#include <stdio.h>


int fact(int n)
{
  if (n <= 0) return 1;

  return fact(n - 1) * n;
}

int cmbP(int n, int r)
{
    int t1, t2, t3;

    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1 / (t2 * t3);
}

int cmbR(int n, int r)
{
    if (r == 0 || r == n) return 1;

    return cmbR(n-1, r-1) + cmbR(n-1, r);
}

int main(int argc, char const *argv[])
{
    printf("%d \n", cmbP(5, 2));
    printf("%d \n", cmbR(5, 2));
    return 0;
}
