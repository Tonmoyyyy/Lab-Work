#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int myqueue[MAX_SIZE];
    int front=-1;
    int rear=-1;

public:
    Queue() {

    };

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear || rear == -1);
    }

    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is full!!" << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear++;
            myqueue[rear] = value;
            cout << value << " ";
        }
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!!" << endl;
            return -1;
        } else {
            int value = myqueue[front];
            front++;
            cout << "Deleted => " << value << " from myqueue" << endl;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
            return value;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Front = " << front << endl;
            cout << "Queue elements : ";
            for (int i = front; i <= rear; i++) {
                cout << myqueue[i] << " ";
            }
            cout << endl << "Rear = " << rear << endl;
        }
    }
};

int main() {
    Queue my;

    my.deQueue();

    cout << "Queue created:" << endl;

    my.enQueue(10);
    my.enQueue(20);
    my.enQueue(30);
    my.enQueue(40);
    my.enQueue(50);
    my.enQueue(60);

    my.displayQueue();

    my.deQueue();

    my.displayQueue();

    return 0;
}
