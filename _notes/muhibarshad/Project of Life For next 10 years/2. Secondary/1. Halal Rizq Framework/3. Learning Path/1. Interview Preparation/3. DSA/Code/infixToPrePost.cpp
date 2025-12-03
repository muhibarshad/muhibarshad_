#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for Linked List Stack
struct Node
{
    char data;
    Node *next;
    Node(char val) : data(val), next(nullptr) {}
};

// Stack implemented using Linked List
class Stack
{
private:
    Node *topNode;

public:
    Stack() { topNode = nullptr; }

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    void push(char value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    char pop()
    {
        if (isEmpty())
            return '\0';
        char value = topNode->data;
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        return value;
    }

    char top()
    {
        return isEmpty() ? '\0' : topNode->data;
    }
};

// Function to get precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convert Infix to Postfix using Stack (Linked List)
string infixToPostfix(string infix)
{
    Stack st;
    string postfix = "";

    for (char c : infix)
    {
        if (isalnum(c))
        { // Operand
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isEmpty() && st.top() != '(')
            {
                postfix += st.pop();
            }
            st.pop(); // Remove '('
        }
        else
        { // Operator
            while (!st.isEmpty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        postfix += st.pop();
    }

    return postfix;
}

// Convert Infix to Prefix using Stack (Linked List)
string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    // Reverse brackets
    for (char &c : infix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix = "(a+b)*(c+d)";

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    return 0;
}
