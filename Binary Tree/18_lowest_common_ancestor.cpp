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

    lowest common ancestor for the node 8 and node 19 = 15
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


Node* lowestCommonAncestor(Node *root, int node1, int node2)
{
    if (!root) return NULL;

    if (root->data == node1 || root->data == node2)
        return root;

    
    Node *leftAns = lowestCommonAncestor(root->left, node1, node2);
    Node *rightAns = lowestCommonAncestor(root->right, node1, node2);

    if (!leftAns and rightAns)
        return rightAns;
    
    if (leftAns and !rightAns) 
        return leftAns;

    if (leftAns and rightAns)
        return root;
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

    Node *lca = lowestCommonAncestor(root, 8, 19);

    cout<<"Lowest commmon ancestor of the given tree and nodes is : "<<lca->data;

    return 0;
}