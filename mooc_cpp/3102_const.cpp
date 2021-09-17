#include <iostream>

using namespace std;

class A {
public:
    int getArea() const {
        return w * h;
    }
    void setSize(int w, int h) {
        this->w = w;
        this->h = h;
    }
private:
    int w, h;
};

int main()
{
    A a; // 普通对象可以不初始化
    a.setSize(3, 9);
    A const b();
    A const c;// 错误 常对象必须在声明时初始化
    b.setSize(3, 7); // 错误 长对象不能调用非 常成员函数

    return 0;
}
