#include <iostream>

using namespace std;

class Arithetic
{
private:
    int a;
    int b;
public:
    Arithetic(int a, int b);
    ~Arithetic();
    int add();
    int sub();
};

Arithetic::Arithetic(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Arithetic::add()
{
    return a + b;
}

int Arithetic::sub()
{
    return a - b;
}

Arithetic::~Arithetic()
{
}

int main(int argc, char const *argv[])
{
    Arithetic ar(10, 3);

    cout<<"Add:\t"<<ar.add()<<endl;
    cout<<"Sub:\t"<<ar.sub()<<endl;

    return 0;
}

