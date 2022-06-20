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

    for K = 2 and node = 19, Kth ancestor is = 15 (i.e. 12->|15|->45->19)
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

pair<int, int> maxSum(Node* root)
{
    // base condition
    if (!root)
    {
        pair<int, int> result = make_pair(0, 0);
        return result;
    }

    // calling the left subtree for the sum of adjacent nodes
    pair<int, int> leftSum = maxSum(root->left);

    // calling the left subtree for the sum of adjacent nodes
    pair<int, int> rightSum = maxSum(root->right);

    pair<int, int> res;

    // first pair will contain the sum of root->data and recursively stored value in the second pair (included nodes)
    res.first = root->data + leftSum.second + rightSum.second;

    // second pair will contain the sum of max of leftSum pair and max of rightSun pair (excluded nodes)
    res.second = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);

    return res;
}

int sumAdjacentNodes(Node *root)
{
    pair<int, int> ans = maxSum(root);
    return max(ans.first, ans.second);
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

    cout<<"Max Sum of the adjacent nodes of the given binary tree is : "<<sumAdjacentNodes(root)<<endl;

    return 0;
}