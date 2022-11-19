0001 #include <iostream>
0002 
0003 using namespace std;
0004 
0005 class Point {
0006     double x, y;
0007 public:
0008     Point(double x1 = 0, double y1 = 0): x(x1), y(y1) {} 
0009     virtual double area() { return 0; }
0010 };
0011 
0012 class Circle: public Point {
0013     double r;
0014 public:
0015     Circle(double x, double y, double r1): Point(x, y), r(r1) {}
0016     double area() { return 3.14 * r*r; }
0017 };
0018 
0019 int main() {
0020     Point a(2, 2);
0021     Circle c(2, 2, 1);
0022     cout << "Point area = " << a.area() << endl; // 基类对象调用
0023     cout << "Point area = " << c.area() << endl; // 派生类调用
0024 
0025     Point *pc = &a; // 基类 指向 基类
0026     cout << "Point area = " << pc->area() << endl;
0027     pc = &c; // 基类指针 指向 派生类对象
0028     cout << "Point area = " << pc->area() << endl; // 动态联编 调用派生类
0029     cout << "Point area = " << pc->Point::area() << endl; // 手动 "静态联编" 调用基类
0030 
0031     return 0;
0032 }
