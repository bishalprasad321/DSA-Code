#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 
       /  \
      5    15 
    /  \  / \
   7  17 8  45
       \      \
        4      19

    for K = 2 and node = 19, Kth ancestor is = 15 (i.e. 12->|15|->45->19)
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

Node *kAncestor(Node *root, int node, int k)
{
    if (!root)
        return NULL;
    
    if (root->data == node)
        return root;
    
    Node *leftPath = kAncestor(root->left, node, k);

    Node *rightPath = kAncestor(root->right, node, k);

    if (leftPath and !rightPath)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftPath;
    }

    if (!leftPath and rightPath)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightPath;
    }
    return NULL;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(7);
    Node *child12 = new Node(17);
    Node *child122 = new Node(4);
    Node *child21 = new Node(8);
    Node *child22 = new Node(45);
    Node *child222 = new Node(19);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child12->right = child122;

    child2->left = child21;
    child2->right = child22;

    child22->right = child222;

    Node *ans = kAncestor(root, 19, 2);

    int result;
    if (!ans or ans->data == 17)
        result = -1;
    else
        result = ans->data;

    cout<<"Kth ancestor of 19 node of the tree is : "<<result<<endl;

    return 0;
}