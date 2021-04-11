#include <iostream>

using namespace std;

class Queue {
private:
  int size;
  int front;
  int rear;
  int *Q;

public:
  Queue(int size);
  ~Queue();
  bool isFull();
  bool isEmpty();
  void enqueue(int x);
  int dequeue();
  void printQueue();
};

Queue::Queue(int size) {
  this->size = size;
  front = rear = -1;
  Q = new int[size];
}

Queue::~Queue() {
  delete [] Q;
}

bool Queue::isEmpty() {
  if (front == rear) {
    return true;
  }
  return false;
}

bool Queue::isFull() {
  if (rear == size-1) {
    return true;
  }
  return false;
}

void Queue::enqueue(int x) {
  if (isFull()) {
    cout<<"Queue is Full"<<endl;
  } else {
    rear++;
    Q[rear] = x;
  }
}

int Queue::dequeue() {
  int x = -1;
  if (isEmpty()) {
    cout<<"Queue is Empty"<<endl;
  } else {
    front++;
    x = Q[front];
  }

  return x;
}

void Queue::printQueue() {
  for (int i = front + 1; i <= rear; i++) {
    cout<<Q[i]<<" ";
  }
  cout<<endl;
}

int main(int argc, char const *argv[])
{
  Queue *q = new Queue(6);

  q->enqueue(2);
  q->enqueue(3);
  q->enqueue(5);
  q->enqueue(7);
  q->printQueue();

  q->dequeue();
  q->printQueue();

  return 0;
}
