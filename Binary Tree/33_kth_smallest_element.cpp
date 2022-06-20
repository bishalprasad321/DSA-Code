#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   let K = 3, Kth smallest element in the above BST : 11
    
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

int solveKth(Node *root, int &i, int k)
{
    if (!root)
        return -1;

    int left = solveKth(root->left, i, k);

    if (left != -1)
        return left;
    
    i++;
    if (i == k)
        return root->data;
    
    int right = solveKth(root->right, i, k);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    return solveKth(root, i, k);
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

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    cout << "Kth smallest element of the given BST : " << kthSmallest(root, k) << endl;

    return 0;
}