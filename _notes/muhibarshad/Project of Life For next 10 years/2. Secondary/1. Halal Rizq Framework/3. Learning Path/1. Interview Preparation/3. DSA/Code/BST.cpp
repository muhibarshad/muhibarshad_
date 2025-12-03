#include <iostream>
using namespace std;

class BinaryTree
{
private:
    class Node
    {
    public:
        int data;
        Node *left, *right;
        Node(int value) : data(value), left(NULL), right(NULL) {}
    };

    Node *root;

public:
    // Constructor
    BinaryTree() { root = NULL; }

    // Function to insert a node
    Node *insert(Node *node, int value)
    {
        if (!node)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    void insert(int value) { root = insert(root, value); }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder() { inorder(root); }

    // Preorder Traversal (Root -> Left -> Right)
    void preorder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder() { preorder(root); }

    // Postorder Traversal (Left -> Right -> Root)
    void postorder(Node *node)
    {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorder() { postorder(root); }

    // Search for a value in the tree
    bool search(Node *node, int value)
    {
        if (!node)
            return false;
        if (node->data == value)
            return true;
        if (value < node->data)
            return search(node->left, value);
        return search(node->right, value);
    }

    bool search(int value) { return search(root, value); }
    
    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }
    
    // Delete a node
    Node* deleteNode(Node* root, int key) {
        if (!root) return root;
    
        // Step 1: Search for the node
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
    
        else {
            // Step 2: Node found — apply one of the cases
    
            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            // Case 2: One child
            else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* successor = findMin(root->right);
                root->data = successor->data;
                root->right = deleteNode(root->right, successor->data);
            }
        }
        return root;
    }
    // Destructor to delete tree nodes
    void destroyTree(Node *node)
    {
        if (!node)
            return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    ~BinaryTree() { destroyTree(root); }
};

// Main function to test the Binary Tree
int main()
{
    BinaryTree bt;
    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    cout << "Inorder Traversal: ";
    bt.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    bt.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorder();
    cout << endl;

    int key = 40;
    if (bt.search(key))
        cout << key << " found in the tree." << endl;
    else
        cout << key << " not found in the tree." << endl;

    return 0;
}
