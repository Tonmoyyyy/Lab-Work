#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void addFront(Node** head, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head;
    *head = new_node;
}

void addAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }
    Node* new_node = new Node(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void addEnd(Node** head, int new_data) {
    Node* new_node = new Node(new_data);
    if (*head == nullptr) {
        *head = new_node;
        return;
    }
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    } else {
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        prev->next = temp->next;
        delete temp;
    }
}

int getNth(Node* head, int index) {
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addEnd(&head, 1);
    addEnd(&head, 2);
    addFront(&head, 3);
    addAfter(head->next, 4);

    cout << "Linked list: ";
    displayList(head);

    cout << "Element at index 2: " << getNth(head, 2) << endl;

    deleteNode(&head, 3);

    cout << "Linked list after deleting element 3: ";
    displayList(head);

    return 0;
}
