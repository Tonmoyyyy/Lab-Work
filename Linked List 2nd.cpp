#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void addFront(Node** head_ref, int new_data) {
    if (head_ref == NULL) {
        cout << "Invalid head reference";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void addAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void addEnd(Node** head_ref, int new_data) {
    if (head_ref == NULL) {
        cout << "Invalid head reference";
        return;
    }

    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->prev = NULL;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(Node** head_ref, Node* del) {
    if (head_ref == NULL || *head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    delete del;
}

Node* getMiddleNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void deleteMiddle(Node** head_ref) {
    if (head_ref == NULL || *head_ref == NULL || (*head_ref)->next == NULL) {
        cout << "Cannot delete from an empty list or with less than 2 nodes";
        return;
    }

    Node* middle = getMiddleNode(*head_ref);
    if (middle != NULL) {
        deleteNode(head_ref, middle);
    }
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    addEnd(&head, 9);
    addFront(&head, 5);
    addEnd(&head, 6);
    addAfter(head->next, 4);

    cout << "Linked list: ";
    printList(head);


    deleteMiddle(&head);

    cout << "Linked list  middle deletion: ";
    printList(head);


    Node* temp = head;
    head = head->next;
    deleteNode(&head, temp);

    cout << "Linked list before deletion: ";
    printList(head);


    temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    deleteNode(&head, temp->next);

    cout << "Linked list after deletion: ";
    printList(head);

    return 0;
}
