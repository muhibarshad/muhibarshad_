#include <iostream>
using namespace std;
class Linkdlist
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
    };
    Node *tail;
    Node *head;
    void Reverse(Node *pre, Node *cur)
    {
        if (cur != nullptr)
        {
            Reverse(cur, cur->next);
            cur->next = pre;
        }
        else
            head = pre;
    }

public:
    Linkdlist()
    {
        head = tail = NULL;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    int count()
    {
        int c = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    int sum()
    {
        int sum = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int max()
    {
        if (!count())
            return 0;
        Node *temp = head;
        int max = temp->data;
        while (temp != NULL)
        {
            if (max < temp->data)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }
    int min()
    {
        Node *temp = head;
        int min = temp->data;
        while (temp != NULL)
        {
            if (min > temp->data)
                min = temp->data;
            temp = temp->next;
        }
        return min;
    }
    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void InsertAtStart(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void Insert(int pos, int n)
    {
        if (pos < 1 || pos > count() + 1) // For to insert at last+1 like if count ==5 and we want to insert at 6th position
            return;
        Node *temp = head;
        Node *newNode = new Node(n);
        if (pos == 1) // to insert at start
        {
            newNode->next = temp;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < pos - 1 && temp; i++) // Insert at given position it also covers the last position and last position +1
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            if (pos == count()) // because count has been updated to 5+1 = 6 so there is no need to write count+1
                tail = newNode;
        }
    }
    int Delete(int pos)
    {
        if (pos < 1 || pos > count())
            return -1;
        int x = -3245;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            x = temp->data;
            delete temp;
            return x;
        }
        else
        {
            Node *temp = head;
            Node *q = NULL;
            for (int i = 1; i < pos && temp; i++)
            {
                q = temp;
                temp = temp->next;
            }
            if (temp)
            {
                q->next = temp->next;
                x = temp->data;
                delete temp;
                return x;
            }
        }
    }
    void SInsert(int n)
    {
        Node *newNode = new Node(n);
        Node *q = NULL;
        Node *temp = head;
        while (n > temp->data && temp)
        {
            q = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            newNode->next = temp;
            q->next = newNode;
            if (!temp) // for update tail in case we insert at last
                tail = newNode;
        }
    }
    Node *search(int n)
    {
        Node *q = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                q->next = temp->next;
                temp->next = head;
                head = temp;
                return temp;
            }
            q = temp;
            temp = temp->next;
        }
        return NULL;
    }
    bool isSorted()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
                return false;
            temp = temp->next;
        }
        return true;
    }
    void duplicatesRemoveFromSortedLL()
    { /*here we are assuming that there shoulde be at least two elements in a list to remove duplicates so starting pre fom head and cur from head->next then if their data is same we are giving pre the next of cur,giving temp = cur and giving cur the next of cur to trvaerse in this way duplicate is deleted as we delete temp because temp=cur(which was duplicate.) if their data is not same then we are taversing as usually.*/
        Node *pre = head;
        Node *cur = head->next;
        Node *temp = NULL;
        while (cur != NULL)
        {
            if (pre->data == cur->data)
            {
                pre->next = cur->next;
                temp = cur;
                cur = cur->next;
                delete temp;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
    }
    void Reverse()
    {
        Node *temp = nullptr;
        Node *cur = head;
        Node *pre = nullptr;

        while (cur != NULL)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head = pre;
    }
    void Reverse2()
    {
        Node *cur = head;
        Node *pre1 = nullptr;
        Node *pre2 = nullptr;
        while (cur != NULL)
        {
            pre2 = pre1;
            pre1 = cur;
            cur = cur->next;
            pre1->next = pre2;
        }
        head = pre1;
    }

    void Revrese3()
    {
        Reverse(nullptr, head);
    }
    ~Linkdlist()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            head = temp;
            temp = temp->next;
            delete head;
        }
    }
};

int main()
{
    Linkdlist ll;
    ll.Insert(1, 1);
    ll.Insert(2, 2);
    ll.Insert(3, 3);
    ll.Insert(4, 4);
    ll.Insert(5, 4);
    ll.Revrese3();
    // ll.Reverse();
    cout << "--------\n";
    ll.display();

    return 0;
}