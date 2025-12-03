#include <iostream>
using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node *top;

public:
    // Constructor
    Stack() { top = NULL; }

    // Push operation (Insert at top)
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation (Remove top element)
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! No elements to pop." << endl;
            return -1;
        }
        Node *temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Peek operation (Get top element)
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Display stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

// Main function to test stack
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
