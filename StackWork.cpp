#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    cout << "Input some elements onto the stack:" << endl;
    int num;
    while (true) {
        cin >> num;
        if (num == 0)
            break;
        myStack.push(num);
    }

    cout << "Stack elements are: ";
    stack<int> NewStack;


    int lowest = myStack.top();
    while (!myStack.empty()) {
        if (myStack.top() < lowest) {
            lowest = myStack.top();
        }
        NewStack.push(myStack.top());
        myStack.pop();
    }

    while (!NewStack.empty()) {
        if (NewStack.top() != lowest) {
            myStack.push(NewStack.top());
        }
        NewStack.pop();
    }

    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;

    return 0;
}
