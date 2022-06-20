#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

    maxSum of the above tree = 72 (i.e. 12->15->45)
*/

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void solutionLongestSum(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // base case for the function 
    if (!root)
    {
        if (len > maxLen) // case when there is longer path than the previous len
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(maxSum, sum);
        }
        return ;
    }

    // increment the sum value as traversing the tree
    sum = sum + root->data;

    // traverse the left subTree to find longest path
    solutionLongestSum(root->left, sum, maxSum, len + 1, maxLen);
    
    // traverse the right subtree to find the longest path
    solutionLongestSum(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongestPath(Node *root)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int len = 0;
    int maxLen = INT_MIN;

    solutionLongestSum(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(7);
    Node *child12 = new Node(17);
    Node *child21 = new Node(8);
    Node *child22 = new Node(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    int maxSumOfLongestPath = sumOfLongestPath(root);

    cout<<"The maximum sum of the longest path of the given binary tree is : "<<maxSumOfLongestPath<<endl;

    return 0;
}