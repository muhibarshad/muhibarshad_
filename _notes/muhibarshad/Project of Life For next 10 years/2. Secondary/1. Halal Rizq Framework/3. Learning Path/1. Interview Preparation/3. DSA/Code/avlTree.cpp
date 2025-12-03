#include <iostream>
using namespace std;

class AVLTree
{
    class Node
    {
    public:
        int data, height;
        Node *left;
        Node *right;
        Node(int value) : data(value), height(1), left(NULL), right(NULL) {}
    };

    Node *root;

    int height(Node *node)
    {
        return node ? node->height : 0;
    }

    int balanceFactor(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x; // New root after rotation
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y; // New root after rotation
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node; // Duplicates not allowed

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // **Balancing the Tree**
        // Left Heavy (Right Rotation)
        if (balance > 1 && key < node->left->data)
            return rotateRight(node);
        // Right Heavy (Left Rotation)
        if (balance < -1 && key > node->right->data)
            return rotateLeft(node);
        // Left-Right Case (Left-Right Rotation)
        if (balance > 1 && key > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // Right-Left Case (Right-Left Rotation)
        if (balance < -1 && key < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; // Return unchanged node if balanced
    }

    Node *findMin(Node *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (!node)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else
        {
            if (!node->left || !node->right)
            {
                Node *temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (!node)
            return node;

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = balanceFactor(node);

        // **Balancing the Tree**
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rotateRight(node);
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return rotateLeft(node);
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inOrder(Node *node)
    {
        if (node)
        {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    AVLTree() { root = NULL; }

    void insert(int key) { root = insert(root, key); }

    void deleteKey(int key) { root = deleteNode(root, key); }

    void display()
    {
        inOrder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "In-order traversal of AVL Tree: ";
    avl.display();

    avl.deleteKey(30);
    cout << "After deleting 30: ";
    avl.display();

    return 0;
}
