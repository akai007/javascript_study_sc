#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
  int length;
  int breadth;
};


int getArea(struct Rectangle r)
{
  int area = r.length * r.breadth;
  return area;
}

int getAreaPointer(struct Rectangle *r)
{
  int area = (*r).length * r->breadth;
  return area;
}

void setLengthWorng(struct Rectangle r, int length)
{
  r.length = length;
}

void setLength(struct Rectangle *r, int length)
{
  r->length = length;
}

int main(int argc, char const *argv[])
{
  struct Rectangle r = {3, 6};
  struct Rectangle *rP = (struct Rectangle *)malloc(sizeof(struct Rectangle));
  (*rP).breadth = 2;
  rP->length = 4;

  printf("area: %d \n", getAreaPointer(rP));

  printf("before area: %d \n", getArea(r));
  setLengthWorng(r, 2);
  printf("after  area: %d \n", getArea(r));

  printf("before area: %d \n", getArea(r));
  setLength(&r, 2);
  printf("after  area: %d \n", getArea(r));

  return 0;
}

