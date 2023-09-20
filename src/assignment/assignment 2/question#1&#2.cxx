#include <iostream>
#include <string>
using namespace std;

struct People
{
    string name;
    int age;
    double height;
};
//2
struct Node
{
    int data;
    Node *next;
};
void append(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}
int main()
{
    People person1 = {"Alice", 25, 5.7};
    People person2 = {"Bob", 30, 6.0};

    const int size = 2;
    People people[size];

    // Using for loop to populate the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name: ";
        cin >> people[i].name;
        cout << "Enter age: ";
        cin >> people[i].age;
        cout << "Enter height: ";
        cin >> people[i].height;
    }

    // Using range-based for loop to iterate through the array
    for (const People &person : people)
    {
        cout << "Name: " << person.name << ", Age: " << person.age << ", Height: " << person.height << endl;
    }

    //2. Adding a Node at the End of a Linked List:
    Node *head = nullptr; // Initialize an empty linked list

    // Append values to the linked list
    append(head, 1);
    append(head, 2);
    append(head, 3);

    // Print the linked list
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}