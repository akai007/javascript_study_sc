#include <iostream>

using namespace std;

class Cuboid {
public:
    Cuboid (); // 如没有任何构造函数，编译器会自动生成空构造函数
    // Cuboid (int l = 0, int w = 0, int h = 0) {} // 注意：如所有参数都有默认值 则会
    Cuboid (int l, int w, int h): length(l), width(w), height(h){}
    Cuboid (int size) { // 可以重载
        length = width = height = size;
    }
    int volumn() { return length * width * height; }
private:
    int length, width, height;
};

Cuboid::Cuboid() {
    cout << "def constructor" << endl;
}

