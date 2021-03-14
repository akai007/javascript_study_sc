#include <iostream>

using namespace std;

template <class T>
class Arithetic
{
private:
    T a;
    T b;
public:
    Arithetic(T a, T b);
    ~Arithetic();
    T add();
    T sub();
};

template <class T>
Arithetic<T>::Arithetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithetic<T>::sub()
{
    return a - b;
}

template <class T>
Arithetic<T>::~Arithetic()
{
}

int main(int argc, char const *argv[])
{
    Arithetic<int> ar(10, 3);
    Arithetic<float> arF(12.34, 3.14);

    cout<<"Add int:\t"<<ar.add()<<endl;
    cout<<"Sub int:\t"<<ar.sub()<<endl;
    
    cout<<"Add float:\t"<<arF.add()<<endl;
    cout<<"Sub float:\t"<<arF.sub()<<endl;

    return 0;
}

