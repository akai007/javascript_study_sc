#include <iostream>

using namespace std;

class CircularQueue {
private:
  int front;
  int rear;
  int size;
  int *Q;
public:
  CircularQueue(int size);
  ~CircularQueue();
  bool isEmpty();
  bool isFull();
  void enqueue(int x);
  int dequeue();
  void printQueue();
};

CircularQueue::CircularQueue(int size)
{
  this->size = size;
  front = rear = 0;
  Q = new int[size];
}

CircularQueue::~CircularQueue()
{
  delete [] Q;
}

bool CircularQueue::isEmpty()
{
  if (front == rear)
  {
    return true;
  }
  return false;
}

bool CircularQueue::isFull() {
  if ((rear + 1) % size == front) {
    return true;
  }
  return false;
}

void CircularQueue::enqueue(int x) {
  if (isFull()) {
    cout<<"Queue is Full "<<endl;
  } else {
    rear = (rear+1) % size;
    Q[rear] = x;
  }

}

int CircularQueue::dequeue() {
  int x = -1;
  if (isEmpty()) {
    cout<<"Queue is Empty "<<endl;
  } else {
    x = Q[front];
    front = (front+1) % size;
  }
  
  return x;
}

void CircularQueue::printQueue() {
  int i = front + 1;

  do {
    cout<<Q[i]<<" ";
    i = (i+1) % size;
  } while (i!= (rear+1) % size);

  cout<<endl; 
}

int main(int argc, char const *argv[]) {
  CircularQueue *q = new CircularQueue(6);

  q->enqueue(2);
  q->enqueue(3);
  q->enqueue(5);
  q->enqueue(7);
  q->printQueue();

  q->dequeue();
  q->printQueue();
  return 0;
}
