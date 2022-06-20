#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

   Balanced Tree is the tree which satisfies the below condition :

   height of (leftNode - rightNode) <= 1

*/

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data);
};

TreeNode :: TreeNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

pair<bool, int> balanced(TreeNode* root)
{
    if (root == nullptr)
    {
        pair<bool, int> result = make_pair(true, 0);
        return result;
    }

    pair<bool, int> leftCheck = balanced(root->left);
    pair<bool, int> rightCheck = balanced(root->right);

    bool leftAns = leftCheck.first;
    bool rightAns = rightCheck.first;

    bool diff = abs(leftCheck.second - rightCheck.second) <= 1;

    pair<bool, int> ans;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
        return ans;
    }
    else
    {
        ans.first = false;
        return ans;
    }
    
}

bool isTreeBalanced(TreeNode* root)
{
    return balanced(root).first;
}

int main()
{
    TreeNode *root = new TreeNode(12);
    TreeNode *child1 = new TreeNode(5);
    // TreeNode *child2 = new TreeNode(15);
    TreeNode *child11 = new TreeNode(7);
    TreeNode *child12 = new TreeNode(17);
    // TreeNode *child21 = new TreeNode(8);
    // TreeNode *child22 = new TreeNode(45);

    // linking the nodes with each other
    root->left = child1;
    // root->right = child2;

    child1->left = child11;
    child1->right = child12;

    // child2->left = child21;
    // child2->right = child22;

    string ans = (isTreeBalanced(root)) ? "Yes" : "No!";
    cout<<"Is the tree balanced ? " + ans;
    
    return 0;
}