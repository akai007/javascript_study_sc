#include <iostream>
#include <string>

using namespace std;

class Point {
public:
    Point(int a, int b): x(a), y(b){};
    ~Point() {
        cout << "destruct function is been called" << endl; //
    }
    void show() {
        cout << "x: " << x << "; y: " << y << endl;
    }
private:
    int x, y;
};

int main(int argc, char const *argv[])
{
    Point pt(1, 2);
    pt.show();
    return 0;
}
