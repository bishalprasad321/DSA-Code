#include<bits/stdc++.h>
using namespace std;

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

bool isIdentical(TreeNode* root1, TreeNode* root2)
{
    if (!root1 and !root2)
        return true;
    if (root1 and !root2)
        return false;
    if (!root1 and root2)
        return false;

    bool leftCheck = isIdentical(root1->left, root2->left);
    bool rightCheck = isIdentical(root1->right, root2->right);

    bool value = root1->data == root2->data;

    if (value and leftCheck and rightCheck)
        return true;
    else
        return false;
}

int main()
{
    TreeNode *root1 = new TreeNode(12);
    TreeNode *child1 = new TreeNode(5);
    TreeNode *child2 = new TreeNode(15);
    TreeNode *child11 = new TreeNode(7);
    TreeNode *child12 = new TreeNode(17);
    TreeNode *child21 = new TreeNode(8);
    TreeNode *child22 = new TreeNode(45);

    root1->left = child1;
    root1->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    TreeNode *root2 = new TreeNode(12);
    TreeNode *_child1 = new TreeNode(5);
    TreeNode *_child2 = new TreeNode(15);
    TreeNode *_child11 = new TreeNode(7);
    TreeNode *_child12 = new TreeNode(17);
    TreeNode *_child21 = new TreeNode(8);
    TreeNode *_child22 = new TreeNode(45);

    root2->left = _child1;
    root2->right = _child2;

    _child1->left = _child11;
    _child1->right = _child12;

    _child2->left = _child21;
    _child2->right = _child22;

    cout<<"Checking whether the given trees are identical or not : "<<endl;
    bool result = isIdentical(root1, root2);
    if (result)
        cout<<"Yes they are Identical!"<<endl;
    else
        cout<<"No, the given trees are not Identical!"<<endl;;
    
    return 0;
}