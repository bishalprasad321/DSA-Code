#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45
    
*/

class Node
{
    public:
        int data;
        Node *left, *right;

        // constructor
        Node (int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

bool searchInBST(Node *root, int value)
{
    Node *temp = root;

    if (!temp)
        return false;

    while (temp)
    {
        if (temp->data == value)
            return true;
        
        if (value < temp->data)
            temp = temp->left;

        else
            temp = temp->right;
    }
    return false;
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

    int data;

    cout << "Enter the value to search in BST : ";
    cin>>data;

    if (searchInBST(root, data))
        cout << data << " present in the BST!!"<<endl;

    else
        cout << data << " is not found in the BST!!"<<endl;


    return 0;
}