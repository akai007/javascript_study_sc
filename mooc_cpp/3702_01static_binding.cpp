#include <iostream>

using namespace std;

class Point {
    double x, y;
public:
    Point(double x1 = 0, double y1 = 0): x(x1), y(y1) {} 
    double area() { return 0; }
};

class Circle: public Point {
    double r;
public:
    Circle(double x, double y, double r1): Point(x, y), r(r1) {}
    double area() { return 3.14 * r*r; }
};

int main() {
    Point a(2, 2);
    Circle c(2, 2, 1);
    cout << "Point area = " << a.area() << endl; // 基类对象调用
    cout << "Point area = " << c.area() << endl; // 派生类调用

    Point *pc = &c;
    Point &rc = c;
    cout << "Point area = " << pc->area() << endl; // 静态联编 基类调用
    cout << "Point area = " << rc.area() << endl; // 静态联编 基类调用

    return 0;
}