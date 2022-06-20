#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   after flattening the above BST, LL will look like : 4->5->11->12->13->15->45
    
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

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return ;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

Node *flatten(Node *root)
{
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);
    Node *newRoot = new Node(inOrderVal[0]);
    
    Node *curr = newRoot;
    
    for (int i = 1; i < inOrderVal.size(); i++)
    {
        Node *temp = new Node(inOrderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    curr->left = NULL;
    curr->right = NULL;
    
    return newRoot;
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

    cout << "Linked List after flattening the given BST : "<<endl;
    root = flatten(root);

    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
        
    return 0;
}