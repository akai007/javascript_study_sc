#include <iostream>

using namespace std;

template <class T, int N>
class Sequence {
  T array[N];
public:
  void Set(int i, T value);
  T Get(int i) { return array[i]; }
};

template <class T, int N>
void Sequence<T, N>::Set(int i, T value) {
  array[i] = value;
}

int main(int argc, char const *argv[])
{
  Sequence <int, 5> arr;
  for (int i = 0; i < 5; i++)
  {
    arr.Set(i, i);
  }

  for (int i = 0; i < 5; i++)
  {
    cout << arr.Get(i) << " ";
  }  
  cout << endl;
  
  return 0;
}
