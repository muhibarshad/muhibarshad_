#include <iostream>
using namespace std;

const int TABLE_SIZE = 10; // Hash table size

// Node for Separate Chaining (Linked List)
struct Node
{
    int key;
    Node *next;
    Node(int k) : key(k), next(NULL) {}
};

// Hash Table Class
class HashTable
{
private:
    Node *table[TABLE_SIZE];    // Separate Chaining Table
    int openTable[TABLE_SIZE];  // Open Addressing Table
    bool isDeleted[TABLE_SIZE]; // For marking deleted elements

    // Hash function
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = NULL;
            openTable[i] = -1; // -1 means empty slot
            isDeleted[i] = false;
        }
    }

    // **Insert using Separate Chaining**
    void insertChaining(int key)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // **Insert using Open Addressing (Linear Probing)**
    void insertOpenAddressing(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        while (openTable[(index + i) % TABLE_SIZE] != -1 && !isDeleted[(index + i) % TABLE_SIZE])
        {
            i++;
            if (i == TABLE_SIZE)
                return; // Table full
        }
        openTable[(index + i) % TABLE_SIZE] = key;
        isDeleted[(index + i) % TABLE_SIZE] = false;
    }

    // **Search using Separate Chaining**
    bool searchChaining(int key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];
        while (temp)
        {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // **Search using Open Addressing**
    bool searchOpenAddressing(int key)
    {
        int index = hashFunction(key);
        int i = 0;
        while (openTable[(index + i) % TABLE_SIZE] != -1)
        {
            if (openTable[(index + i) % TABLE_SIZE] == key && !isDeleted[(index + i) % TABLE_SIZE])
                return true;
            i++;
            if (i == TABLE_SIZE)
                return false;
        }
        return false;
    }

    // **Delete using Separate Chaining**
    void deleteChaining(int key)
    {
        int index = hashFunction(key);
        Node *temp = table[index];
        Node *prev = NULL;

        while (temp)
        {
            if (temp->key == key)
            {
                if (prev)
                    prev->next = temp->next;
                else
                    table[index] = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    // **Delete using Open Addressing**
    void deleteOpenAddressing(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        while (openTable[(index + i) % TABLE_SIZE] != -1)
        {
            if (openTable[(index + i) % TABLE_SIZE] == key)
            {
                openTable[(index + i) % TABLE_SIZE] = -1; // Mark as deleted
                isDeleted[(index + i) % TABLE_SIZE] = true;
                return;
            }
            i++;
            if (i == TABLE_SIZE)
                return; // Not found
        }
    }

    // **Display Separate Chaining Table**
    void displayChaining()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " -> ";
            Node *temp = table[i];
            while (temp)
            {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    // **Display Open Addressing Table**
    void displayOpenAddressing()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (openTable[i] == -1)
                cout << i << " -> EMPTY\n";
            else
                cout << i << " -> " << openTable[i] << "\n";
        }
    }
};

// **Main Function**
int main()
{
    HashTable ht;

    // Insert Elements
    ht.insertChaining(10);
    ht.insertChaining(20);
    ht.insertChaining(30);
    ht.insertOpenAddressing(10);
    ht.insertOpenAddressing(20);
    ht.insertOpenAddressing(30);

    cout << "Separate Chaining Hash Table:\n";
    ht.displayChaining();

    cout << "\nOpen Addressing Hash Table:\n";
    ht.displayOpenAddressing();

    // Search Elements
    cout << "\nSearch 20 in Chaining: " << (ht.searchChaining(20) ? "Found" : "Not Found") << endl;
    cout << "Search 25 in Open Addressing: " << (ht.searchOpenAddressing(25) ? "Found" : "Not Found") << endl;

    // Delete Elements
    ht.deleteChaining(10);
    ht.deleteOpenAddressing(10);

    cout << "\nAfter Deleting 10:\n";
    ht.displayChaining();
    cout << "\n";
    ht.displayOpenAddressing();

    return 0;
}
