#include <iostream>
#include <vector>
#include <list>
using namespace std;
//Function to convert a vector into a list
list<int> vectorToList(const vector<int>& vec) {
    list<int> myList(vec.begin(), vec.end());
    return myList;
}
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class List {
private:
    Node* head;
public:
    List() {
        head = nullptr;
    }
    // add a node at the start 
    void Start(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    // add a node at the end 
    void End(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    //  add a node at the middle 
    void Middle(int val, int position) {
        if (position <= 0) {
            Start(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* current = head;
        int count = 0;

        while (current && count < position - 1) {
            current = current->next;
            count++;
        }

        if (!current) {
            cout << "Position out of range.\n";
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // displaying the list of nodes
    void displayList() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    // delete a node from the start 
    void Start_1() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // delete a node from the end 
    void End_1() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // delete a node from the middle 
    void Middle_1(int position) {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        if (position == 1) {
            Start_1();
            return;
        }

        Node* current = head;
        int count = 0;

        while (current && count < position - 2) {
            current = current->next;
            count++;
        }

        if (!current || !current->next) {
            cout << "Position out of range.\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() 
{
    List list;
    int numInputs;

    // Ask the user for the number of inputs
    cout << "Enter the number of inputs you want to add to the list: ";
    cin >> numInputs;

    // Check if the input is valid
    if (numInputs <= 0) {
        cout << "Invalid input. Please enter a positive number of inputs." << endl;
        return 1; // Exit with an error code
    }

    // Create a vector to store the inputs
    vector<int> inputs;

    // Receive the inputs from the user
    for (int i = 0; i < numInputs; i++) {
        int input;
        cout << "Enter input " << i + 1 << ": ";
        cin >> input;
        inputs.push_back(input);
    }

    // Initialize the linked list from the vector
    list = vectorToList(inputs);

    // Display the list
     cout << "List content list is initialized: ";
    list.displayList();
    // Adding nodes to the list
    list.End(10);
   // list.End();
   // list.End();

    // Displaying the list
    cout << "List content after elements add to the list: ";
    list.displayList();

    // Adding nodes at different positions
    list.Start(0);
    cout << "List content after adding on the start: ";
    list.displayList();

    list.Middle(4, 3);

    // Displaying the updated list
    cout << "Updated list finally adding a number in the middle: ";
    list.displayList();

    // Deleting nodes from different positions
    list.Start_1();
    list.End_1();
    list.Middle_1(2);

    // Displaying the final list
    cout << "Final list: ";
    list.displayList();

    return 0;
}

