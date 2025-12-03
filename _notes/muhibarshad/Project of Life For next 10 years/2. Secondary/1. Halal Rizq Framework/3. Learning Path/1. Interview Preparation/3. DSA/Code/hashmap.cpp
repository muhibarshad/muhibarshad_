#include <iostream>
using namespace std;

class HashMap
{
private:
    static const int TABLE_SIZE = 10; // Size of the hash table

    // Node structure for linked list (chaining)
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    Node *table[TABLE_SIZE]; // Hash table as an array of linked lists

    // Hash function
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr; // Initialize all table slots as NULL
    }

    // Insert key-value pair
    void put(int key, int value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        // If no collision, insert directly
        if (!table[index])
        {
            table[index] = newNode;
        }
        else
        {
            // Collision: use chaining (insert at the beginning)
            Node *temp = table[index];
            while (temp)
            {
                if (temp->key == key)
                {
                    temp->value = value; // Update value if key exists
                    return;
                }
                temp = temp->next;
            }
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    // Get value by key
    int get(int key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];

        while (temp)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return -1; // Key not found
    }

    // Remove a key from HashMap
    void remove(int key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];
        Node *prev = nullptr;

        while (temp)
        {
            if (temp->key == key)
            {
                if (prev)
                    prev->next = temp->next;
                else
                    table[index] = temp->next; // If first node is to be deleted
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // Display HashMap
    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *temp = table[i];
            while (temp)
            {
                cout << "(" << temp->key << "," << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node *temp = table[i];
            while (temp)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
};

int main()
{
    HashMap hashMap;

    hashMap.put(1, 10);
    hashMap.put(2, 20);
    hashMap.put(12, 120); // Collision with key 2
    hashMap.put(22, 220); // Collision with key 2

    cout << "Value at key 2: " << hashMap.get(2) << endl;

    hashMap.display();

    hashMap.remove(12);

    cout << "\nAfter deleting key 12:" << endl;
    hashMap.display();

    return 0;
}
