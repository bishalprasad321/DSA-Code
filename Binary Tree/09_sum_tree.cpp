#include<bits/stdc++.h>
using namespace std;

class Tree
{
    public:
        int data;
        Tree* left;
        Tree* right;

        // Comstructor of the tree
        Tree(int data);
};

Tree :: Tree(int value)
{
    this->data = value;
    this->left = NULL;
    this->right = NULL;
}

pair<bool, int> sumTree(Tree* root)
{
    // Base Condition
    if (root == NULL)
    {
        pair<bool, int> ans = make_pair(true, 0);
        return ans;
    }

    // Condition for leaf nodes
    if (root->left == NULL and root->right == NULL)
    {
        pair<bool, int> ans = make_pair(true, root->data);
        return ans;
    }

    pair<bool, int> leftCheck = sumTree(root->left);
    pair<bool, int> rightCheck = sumTree(root->right);

    bool leftSum = leftCheck.first;
    bool rightSum = rightCheck.first; 

    bool condn = root->data == (leftCheck.second + rightCheck.second);

    pair<bool, int> ans;

    if (leftSum and rightSum and condn)
    {
        ans.first = true;
        ans.second = root->data + leftCheck.second + rightCheck.second;
    }
    else
        ans.first = false;
    
    return ans;
}

bool isSumTree(Tree* root)
{
    return sumTree(root).first;
}

int main()
{
    Tree* root = new Tree(12);
    Tree* child1 = new Tree(5);
    Tree* child2 = new Tree(7);

    root->left = child1;
    root->right = child2;

    bool ans = isSumTree(root);
    string result = ans ? "Yes": "No";
    cout<<"Is this a valid Sum Tree : "<<result;

    return 0;
}