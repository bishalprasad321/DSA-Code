#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   The above example is a valid BST!
    
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
    if (root)
    {
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
}

bool checker(Node *root, int min, int max)
{
    // base case
    if (!root)
        return true;

    // node between the min and max range
    if (root->data > min and root->data < max)
    {
        bool left = checker(root->left, min, root->data); // left range : (-inf, root->data)

        bool right = checker(root->right, root->data, max); // right range : (root->data, inf)

        return left and right; // return if both are true
    }

    else
        return false;
}


bool validateBST(Node *root)
{
    return checker(root, INT_MIN, INT_MAX);
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

    if (validateBST(root))
        cout << "This is a valid BST!!"<<endl;

    else
        cout<< "Not a valid BST";

    return 0;
}