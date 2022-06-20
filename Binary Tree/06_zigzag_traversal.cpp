#include <bits/stdc++.h>
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
    TreeNode *left;
    TreeNode *right;

    // Constructor for BinaryTree
    TreeNode(int data);
};

TreeNode ::TreeNode(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

vector<int> zigZagTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;

    bool leftToRight = true;
    
    q.push(root);

    while (!q.empty())
    {
        vector<int> level(q.size());
        for (int i = 0; i < q.size(); i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (q.size() - i - 1);
            level[index] = node->data;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        leftToRight = !leftToRight;
        for (auto i : level)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(12);
    TreeNode *child1 = new TreeNode(5);
    TreeNode *child2 = new TreeNode(15);
    TreeNode *child11 = new TreeNode(7);
    TreeNode *child12 = new TreeNode(17);
    TreeNode *child21 = new TreeNode(8);
    TreeNode *child22 = new TreeNode(45);

    // linking the nodes with each other
    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    cout << "Zig Zag Traversal of the given Binary Tree : " << endl;
    vector<int> traversal = zigZagTraversal(root);

    for (int i = 0; i < traversal.size(); i++)
    {
        cout << traversal[i] << " ";
    }

    return 0;
}