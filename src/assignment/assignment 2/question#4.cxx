#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
  private:
    Node *head;
    Node *tail;

  public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value)
    {
        Node *newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void traverseBackward()
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main() {
      DoublyLinkedList list;

    // Inserting example values
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout << "Doubly linked list in backward order: ";
    list.traverseBackward();
    
    return 0;
}