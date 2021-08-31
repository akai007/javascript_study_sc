#include <iostream>

using namespace std;
int max(int a, int b);
int add1(int a = 1, int b = 2);
int add2(int a, int b = 2);
// int add2(int a, int b = 2){} // error 不能重复声明
// int add3(int a = 1, int b); // error 默认参数右边不能为空
int add3(int a, int b = max(2, 3));

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
