#include<iostream>
#define MAX_SIZE 100

using namespace std;

struct CircularQueue {
    int front, rear;
    int arr[MAX_SIZE];

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE) == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued element: " << value << endl;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int element = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued element: " << element << endl;
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements in the queue: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
  CircularQueue q;
  q.enQueue (10);
  q.enQueue (20);
  q.enQueue (30);
  q.enQueue (40);

  q.display ();

  q.deQueue ();
  q.deQueue ();

  q.display ();

  q.enQueue (50);
  q.enQueue (60);

  q.display ();

    return 0;
}
