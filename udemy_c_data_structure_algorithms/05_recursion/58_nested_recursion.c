#include <stdio.h>

int fun(int n)
{
  if(n > 100) return n - 10;
  
  return fun( fun(n + 11) );
}

int main(int argc, char const *argv[])
{
  printf("%d ", fun(20));
  printf("%d ", fun(90));
  printf("%d ", fun(100));
  printf("%d ", fun(110));
  return 0;
}
