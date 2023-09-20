#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
  private:
    Node *top;

  public:
    Stack()
    {
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.isEmpty())
    {
        cout << stack.peek() << " ";
        stack.pop();
    }
  return 0;
}