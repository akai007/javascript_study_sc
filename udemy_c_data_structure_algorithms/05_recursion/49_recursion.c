#include <stdio.h>

void fun(int n)
{
  if (n > 0)
  {
    printf("asc %d \n", n);
    fun(n-1);
    printf("desc %d \n", n);
  }
}

int main(int argc, char const *argv[])
{
  int x = 3;
  fun(x);

  return 0;
}
