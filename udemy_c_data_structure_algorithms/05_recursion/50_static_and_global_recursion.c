#include <stdio.h>

int fun(int n)
{
  if (n > 0)
  {
    return fun(n - 1) + n;
  }
  return 0;
}

int funStatic(int n)
{
  static int x = 0;
  if (n > 0)
  {
    x++;
    return fun(n - 1) + x;
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  printf("finally fun \t\t\t\tresult: %d \n", fun(8));
  printf("finally funStatic \tresult: %d \n", funStatic(8));
  return 0;
}
