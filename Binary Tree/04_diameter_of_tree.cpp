#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node 
       /  \
      5    15 -> parent node
    /  \  / \ 
   7  17 8  45 -> child node (leaf node)

   diameter -> it is the longest length between two nodes of a binary tree, which may or may not pass through the root of the tree.

   diameter of the above tree - 4 (passing through : 7->5->12->15->45)
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

void preOrder(TreeNode* root)
{
    if (root)
    {
        cout<< root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* 
    function logic : 

    standing on a node, calculate the left height and right height of the tree from there. (maximum of left height and right height is considered)

    sum up the left height and right height sum and store it as diameter

    Time Complexity -> O(N)
*/

int heightOfTree(TreeNode* root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int lh = heightOfTree(root->left, diameter);
    int rh = heightOfTree(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfTree(TreeNode* root)
{
    int diameter = 0;
    heightOfTree(root, diameter);
    return diameter;
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

    int diameter = diameterOfTree(root);
    cout<<"Diameter of the given tree : "<<diameter<<endl;

    return 0;
}