#include <iostream>

using namespace std;

class Matrix
{
private:
  int *A;
  int n;
  /* data */
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
  A = new int[(n+1)*n/2];
}
Matrix::~Matrix()
{
  delete [] A;
}
void Matrix::set(int i, int j, int x)
{
  if (i >= j) {
    int index = i*(i-1)/2 + j-1;
    A[index] = x;
  }
}

int Matrix::get(int i, int j)
{
  if (j < i) return 0;

  int index = i*(i-1)/2 + j-1;
  return A[index];
}
void Matrix::toString()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i >= j)
      {
        printf("%d\t\t", A[i*(i-1)/2 + j-1]);
      } else {
        printf("0\t\t");
      }
      
    }
    printf("\n");
    
  }
}

int main(int argc, char const *argv[])
{
  Matrix *m = new Matrix(4);
  
  m->set(1, 1, 3);
  m->set(2, 2, 6);
  m->set(3, 3, 9);
  m->set(4, 1, 7);
  m->set(4, 2, 7);
  m->set(4, 3, 7);
  m->set(4, 4, 7);

  cout<<m->get(2, 1)<<endl;
  cout<<m->get(3, 3)<<endl;
  cout<<m->get(4, 3)<<endl;

  m->toString();
  
  return 0;
}
