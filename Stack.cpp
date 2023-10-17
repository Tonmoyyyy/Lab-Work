#include <iostream>
using namespace std;

#define SIZE 5
int top = -1;
int A[SIZE];

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack is Full" << endl;
    } else {
        top++;
        A[top] = value;
    }
}
bool isempty() {
    return top == -1;
}

void pop() {
    if (isempty())
        cout << "Stack is empty" << endl;
    else
        top--;
}

void show_top() {
    if (isempty())
        cout << "Stack is empty" << endl;
    else
        cout << "Element at top is: " << A[top] << endl;
}

void displayStack() {
    if (isempty()) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i =0; i <=top; i++) {
            cout << A[i] << " " << endl;
        }
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    displayStack();
    pop();
    displayStack();
    show_top();
    return 0;
}
