#include <iostream>

using namespace std;

class Test {
public:
    Test() { sum++; }
    ~Test() { sum--; }

    static void output() { cout << sum << endl; }
private:
    static int sum ;
};

int Test::sum = 0;
int main() {

    Test t;
    t.output();

    return 0;
}