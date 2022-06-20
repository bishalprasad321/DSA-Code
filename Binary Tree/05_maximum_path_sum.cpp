#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node 
       /  \
      5    15 -> parent node
    /  \  / \ 
   7  17 8  45 -> child node (leaf node)

*/

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        // Constructor for BinaryTree
        TreeNode(int data);
};

TreeNode :: TreeNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

/* 
    Function logic : 

    standing on a node, calculate the left path sum and right path sum
    calculate the maximum of both the path -> to select the maximum path 
    calculate the maximum sum from the current node
*/

int maxPathDown(TreeNode* root, int& maxi)
{
    if (root == nullptr) return 0;
    int leftSum = max(0, maxPathDown(root->left, maxi));
    int rightSum = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, leftSum + rightSum + root->data);
    return max(leftSum, rightSum) + root->data;
}

int maxPathSum(TreeNode* root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main()
{
    TreeNode* root = new TreeNode(12);
    TreeNode* child1 = new TreeNode(5);
    TreeNode* child2 = new TreeNode(15);
    TreeNode* child11 = new TreeNode(7);
    TreeNode* child12 = new TreeNode(17);
    TreeNode* child21 = new TreeNode(8);
    TreeNode* child22 = new TreeNode(45);

    // linking the nodes with each other
    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    int maxi = maxPathSum(root);
    cout<<"The max path Sum of the given tree is : "<<maxi<<endl;

    return 0;
}