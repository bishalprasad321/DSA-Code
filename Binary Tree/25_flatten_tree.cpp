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

    After flattening the above tree : 12->5->7->17->4->15->8->45->19
    
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

void flatten(Node *root)
{
    Node *curr = root;

    while (curr)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
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

    flatten(root);

    cout<<"After flattening the tree : ";

    while(root)
    {
        cout<<root->data<<" ";
        root = root->right;
    }

    return 0;
}