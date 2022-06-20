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

    Morris Traversal's Advantage -> It uses constant time to traverse

    inOrder trvaersal using Morris traversal will print -> 7, 5, 17, 4, 12, 8, 15, 45, 19

    preOrder traversal using Morris traversal will print -> 12, 5, 7, 17, 4, 15, 8, 45, 19
    
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

vector<int> morrisInTraversal(Node* root)
{
    vector<int> store;

    if (!root)
        return store;

    Node *pre; // Node for predecessor
    Node *current = root; // current node

    while (current) 
    {
        if (!current->left)
        {
            store.push_back(current->data);
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right and pre->right != current)
            {
                pre = pre->right;
            }

            if (!pre->right)
            {
                pre->right = current;
                current = current->left;
            }

            else
            {
                pre->right = NULL;
                store.push_back(current->data);
                current = current->right;
            }
        }
    }  
}

vector<int> morrisPreTraversal(Node* root)
{
    vector<int> store;

    if (!root)
        return store;

    Node *pre; // Node for predecessor
    Node *current = root; // current node

    while (current) 
    {
        if (!current->left)
        {
            store.push_back(current->data);
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right and pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }

            else
            {
                store.push_back(current->data);
                pre->right = current;
                current = current->left;
            }
        }
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

    cout<<"InOrder Traversal using Morris Traversal : ";

    vector<int> inMorris = morrisInTraversal(root);

    for (auto i : inMorris)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"PreOrder Traversal using Morris Traversal : ";

    vector<int> preMorris = morrisPreTraversal(root);

    for (auto i : preMorris)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}