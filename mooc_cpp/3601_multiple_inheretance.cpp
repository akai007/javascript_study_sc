#include <iostream>

using namespace std;

enum Color {Red, Yellow, Green, White}; // 颜色枚举类型

class Circle {
    float radius;
public:
    Circle(float r): radius(r) { cout << "Circle initialized!" << endl; }
    ~Circle() { cout << "Circle destroyed!" << endl; }
    float getArea() { return 3.14 * radius * radius; }
};

class Table {
    float height;
public: 
    Table(float h) { cout << "Table initialized!" << endl; }
    ~Table() { cout << "Table destoryed!" << endl; }
    float getHeight() { return height; }
};

class RoundTable: public Table, public Circle {
    Color color;
public:
    RoundTable(float h, float r, Color c): Table(h), Circle(r), color(c) {
        cout << "RoundTable initialized!" << endl;
    };
    int getColor() { return color; }
    ~RoundTable() { cout << "RoundTable destroyed!" << endl; }
};

int main() {
    RoundTable rT(15, 2, Yellow);
    cout << "The table properties are: " << endl;
    cout << "Height = " << rT.getHeight() << endl;
    cout << "Area = " << rT.getArea() << endl;
    cout << "Color = " << rT.getColor() << endl;

    return 0;
}