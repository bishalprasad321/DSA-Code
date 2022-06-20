#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   LCA (lowest common ancestor) of 5 and 11 is : 5
    
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

Node *LCAinBST(Node *root, Node *a, Node *b)
{
    if (root->data > a->data and root->data > b->data)
        return LCAinBST(root->left, a, b);

    if (root->data < a->data and root->data < b->data)
        return LCAinBST(root->right, a, b);

    return root;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(4);
    Node *child12 = new Node(11);
    Node *child21 = new Node(13);
    Node *child22 = new Node(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    Node *ans = LCAinBST(root, child1, child12);

    cout << "Lowest common ancestor of 5 and 11 is : " << ans->data << endl;

    return 0;
}