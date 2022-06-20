#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   predecessor of 11 : 5
   successor of 11 : 12
    
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

void preSucBST(Node * root, int key, Node* &pre, Node* &suc)
{
    if (!root)
        return ;
    
    if (root->data == key)
    {
        if (root->left)
        {
            Node *temp = root->left;

            while (temp->right)
                temp = temp->right;
        
            pre = temp;
        }

        if (root->right)
        {
            Node *temp = root->right;

            while(temp->left)
                temp = temp->left;

            suc = temp;
        }

        return ;
    }

    if (root->data > key)
    {
        pre = root;
        preSucBST(root->left, key, pre, suc);
    }

    if (root->data < key)
    {
        suc = root;
        preSucBST(root->right, key, pre, suc);
    }
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

    Node* pre = NULL;
    Node* suc = NULL;

    preSucBST(root, 11, pre, suc);

    cout << "Predecessor of 11 is : "<< pre->data << endl;

    cout << "Successor of 11 is : "<< suc->data << endl;

    return 0;
}