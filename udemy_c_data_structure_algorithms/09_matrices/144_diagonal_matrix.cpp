#include <iostream>

using namespace std;

class Matrix
{
private:
  int *A;
  int n;
public:
  Matrix(int n);
  ~Matrix();
  void set(int i, int j, int x);
  int get(int i, int j);
  void toString();
};

Matrix::Matrix(int n)
{
  this->n = n;
  A = new int[n];
}
Matrix::~Matrix()
{
  delete [] A;
}
void Matrix::set(int i, int j, int x)
{
  if (i == j)
    A[i-1] = x;
}

int Matrix::get(int i, int j)
{
  if (i == j)
    return A[i-1];
  return 0;
}
void Matrix::toString()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        cout<<A[i-1]<<" ";
      } else {
        cout<<"0 ";
      }
      
    }
    cout<<endl;
    
  }
}

int main(int argc, char const *argv[])
{
  Matrix *m = new Matrix(4);
  
  m->set(1, 1, 3);
  m->set(2, 2, 6);
  m->set(3, 3, 9);
  m->set(4, 4, 7);
  m->set(4, 8, 2);

  cout<<m->get(2, 1)<<endl;
  cout<<m->get(3, 3)<<endl;

  m->toString();

  return 0;
}
