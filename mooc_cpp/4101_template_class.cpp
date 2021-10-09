#include <iostream>

using namespace std;

template <class T, int N>
class Sequence {
    T list [N];
public:
    void Set(int index, T value );
    void Display() {
        for (int i = 0; i < N; i++) cout << list[i] << ", ";
        cout << endl;
    }
};

template <class T, int N>
void Sequence<T,N>::Set(int index, T value) {
    list[index] = value;
}

int main(int argc, char const *argv[])
{
    Sequence<int, 10> intList;
    for (int i = 0; i < 10; i++) {
        intList.Set(i, i+1);
    }
    intList.Display();

    Sequence<double, 10> doubleList;
    for (int i = 0; i < 10; i++) {
        doubleList.Set(i, i*3.14);
    }
    doubleList.Display();

    return 0;
}
