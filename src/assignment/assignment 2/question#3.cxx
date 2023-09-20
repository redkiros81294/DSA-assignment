#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void deleteNode(Node* &head, int key) {
    Node* current = head;

    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Element not found in the list." << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

void printBackward(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    
    while (current->next != nullptr) {
        current = current->next;
    }

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }

    cout << endl;
}

int main() {

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Original List: ";
    printBackward(head);

    int keyToDelete = 2;
    deleteNode(head, keyToDelete);

    cout << "List after deleting " << keyToDelete << ": ";
    printBackward(head);

    delete head;
    delete second;
    delete third;

    return 0;
}
