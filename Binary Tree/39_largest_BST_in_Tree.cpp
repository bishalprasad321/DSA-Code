#include<bits/stdc++.h>
using namespace std;

/* 
    BST 01 ---------->

         5
       /  \
      2    4
    /  \ 
   1   3

   
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

class info
{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
};

info largestSize(Node* root, int &ans)
{
    if (!root)
        return {INT_MIN, INT_MAX, true, 0};

    info left = largestSize(root->left, ans);
    info right = largestSize(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);

    if (left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini))
        currNode.isBST = true;
    
    else
        currNode.isBST = false;

    if (currNode.isBST) 
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestSizeOfBST(Node *root)
{
    int maxSize = 0;
    info temp = largestSize(root, maxSize);
    return maxSize;
}

int main()
{
    Node *root = new Node(5);
    Node *child1 = new Node(2);
    Node *child2 = new Node(4);
    Node *child11 = new Node(1);
    Node *child12 = new Node(3);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    cout << "Size of largest BST in the given tree : " << largestSizeOfBST(root) <<endl;
        
    return 0;
}