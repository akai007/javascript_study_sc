#include <iostream>

using namespace std;

class A {
public:
    int n;
    A(int _n = 10): n(_n) {
        cout << "A("<< n <<")构造\t";
    }
    ~A() {
        cout << "A("<< n <<")析构\t";
    }
};

class B {
public:
    int n;
    B(int _n = 20): n(_n), a(_n) {
        cout << "B("<< n <<")构造\t";
    }
    ~B() {
        cout << "B("<< n <<")析构\t";
    }
    A a;
};

B *gp, gb(30); // 全局对象

void fun4() {
    static B b41(41); // 静态局部对象
    B b42(42); // 局部对象
    gp = new B(43); // 自由存储对象
}

void fun5() {
    static B b51(51); // 静态局部对象
    B b52(52); // 局部对象
}

B fun6(B b61) {
    delete gp; // 释放自由存储对象
    return b61;
}

int main()
{
    cout << "-------------- main start --------------" << endl;

    fun4(); cout << endl << "----- fun4 end -----" << endl;
    fun5(); cout << endl << "----- fun5 end -----" << endl;

    B b71(71), b72(72); // 局部对象
    b72 = fun6(b71);

    cout << "-------------- main end --------------" << endl;
    return 0;
}

