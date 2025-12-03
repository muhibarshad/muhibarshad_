#include <iostream>
using namespace std;

// Singly Linked List
class SinglyLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
    };
    Node *head;

public:
    SinglyLinkedList() { head = NULL; }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void Reverse()
    {
        Node *prev = NULL, *cur = head, *next = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Doubly Linked List
class DoublyLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(NULL), prev(NULL) {}
    };
    Node *head;

public:
    DoublyLinkedList() { head = NULL; }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void Reverse()
    {
        Node *temp = NULL, *cur = head;
        while (cur)
        {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if (temp)
            head = temp->prev;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Singly Circular Linked List
class SinglyCircularLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
    };
    Node *head;
    Node *tail;

public:
    SinglyCircularLinkedList() { head = tail = NULL; }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void Reverse()
    {
        if (!head || head->next == head)
            return;
        Node *prev = NULL, *cur = head, *next = NULL, *last = head;
        do
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        } while (cur != head);
        last->next = prev;
        head = prev;
    }

    void Display()
    {
        if (!head)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Doubly Circular Linked List
class DoublyCircularLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(NULL), prev(NULL) {}
    };
    Node *head;
    Node *tail;

public:
    DoublyCircularLinkedList() { head = tail = NULL; }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void Reverse()
    {
        if (!head || head->next == head)
            return;
        Node *cur = head, *temp = NULL;
        do
        {
            temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = temp;
        } while (cur != head);
        tail = head;
        head = head->prev;
    }

    void Display()
    {
        if (!head)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{
    cout << "Singly Linked List:\n";
    SinglyLinkedList sll;
    sll.InsertAtEnd(1);
    sll.InsertAtEnd(2);
    sll.InsertAtEnd(3);
    sll.Display();
    sll.Reverse();
    sll.Display();

    cout << "\nDoubly Linked List:\n";
    DoublyLinkedList dll;
    dll.InsertAtEnd(4);
    dll.InsertAtEnd(5);
    dll.InsertAtEnd(6);
    dll.Display();
    dll.Reverse();
    dll.Display();

    cout << "\nSingly Circular Linked List:\n";
    SinglyCircularLinkedList scll;
    scll.InsertAtEnd(7);
    scll.InsertAtEnd(8);
    scll.InsertAtEnd(9);
    scll.Display();
    scll.Reverse();
    scll.Display();

    cout << "\nDoubly Circular Linked List:\n";
    DoublyCircularLinkedList dcll;
    dcll.InsertAtEnd(10);
    dcll.InsertAtEnd(11);
    dcll.InsertAtEnd(12);
    dcll.Display();
    dcll.Reverse();
    dcll.Display();

    return 0;
}
