#include <stdio.h>

int main(int argc, char const *argv[])
{
  char cStr[] = {'H', 'E', 'L', 'L', 'O', 'W', '\0'};
  char cStr2[] = "WORLD";
  printf("%s %s", cStr, cStr2);
  return 0;
}
