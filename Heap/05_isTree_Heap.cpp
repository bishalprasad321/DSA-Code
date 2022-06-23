#include<bits/stdc++.h>
using namespace std;

/* 
        60
       /  \
      40   30
    /  \ 
   20  10

    A Binary Tree is called a max heap, if it is a complete binary tree and it follows the maxorder property.

    (i.e. where every parent node is grater than it's child node)
    
*/

class Node
{
    public:
        int data;
        Node *left, *right;

        Node(int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

int countNodes(Node *root)
{
    if (!root) 
        return 0;
    
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCBT(Node *root, int index, int nodeCount)
{
    if (!root)
        return true;
    
    if (index >= nodeCount)
        return false;

    else
    {
        // 0 based indexing
        bool left = isCBT(root->left, 2*index + 1, nodeCount);
        bool right = isCBT(root->right, 2*index + 2, nodeCount);

        return (left && right);
    }
}

bool isMaxOrder(Node *root)
{
    // leaf node
    if (!root->left and !root->right)
        return true;
    
    // only right child
    if (!root->right)
        return (root->data > root->left->data);

    // heap condition
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return ((left and right) and (root->data > root->left->data and root->data > root->right->data));
    }
}

bool isHeap(Node *root)
{
    int index = 0;
    int totalNodes = countNodes(root);
    if ((isCBT(root, index, totalNodes)) and isMaxOrder(root))
        return true;
    else
        return false;
}

int main()
{
    Node *root = new Node(60);
    Node *child1 = new Node(40);
    Node *child2 = new Node(30);
    Node *child11 = new Node(20);
    Node *child12 = new Node(10);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    if (isHeap(root))
        cout << "The given tree is a max heap" <<endl;

    else
        cout << "The given tree is not a heap!!!" <<endl;

    return 0;
}