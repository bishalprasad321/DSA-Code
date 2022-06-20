#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node 
       /  \
      4    6 -> parent node
    /  \  / \ 
   8  10 7   5 -> child node (leaf node)

   Level Order Traversal will print -> 12, 4, 6, 8, 10, 7, 5
*/

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        // function for creating new nodes of the tree
        TreeNode* createNode(int data);
};

// constructor definition 
TreeNode* TreeNode :: createNode(int data)
{
    TreeNode* new_node = new TreeNode(); // allocating free space in heap for a new node
    new_node->data = data; // binding the data of new node to given data
    new_node->left = NULL; // assigning the left leaf node to NULL
    new_node->right = NULL; // assigning the right leaf node to NULL
    return new_node;
}

// Level Order Traversal implementation
vector<vector<int>> levelOrderTraversal (TreeNode* root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    TreeNode treeNode; // binary tree object

    TreeNode* root = treeNode.createNode(12); // creating root node
    TreeNode* parent1 = treeNode.createNode(4); // creating left parent node of root
    TreeNode* parent2 = treeNode.createNode(6); // creating right parent node of root 
    TreeNode* child11 = treeNode.createNode(8); // creating left child node of left parent from root
    TreeNode* child12 = treeNode.createNode(10); // creating right child node of left parent from root
    TreeNode* child21 = treeNode.createNode(7); // creating left child node of right parent from root
    TreeNode* child22 = treeNode.createNode(5); // creating right child node of right parent from root

    // linking the root with it's child(s) 
    root->left = parent1; 
    root->right = parent2;

    // linking left parent node from root to it's child(s)
    parent1->left = child11;
    parent1->right = child12;

    // linking right parent node from root to it's child(s)
    parent2->left = child21;
    parent2->right = child22;

    cout<<"Level Order Traversal : "<<endl;

    // level order traversal function execution
    vector<vector<int>> levelOrder = levelOrderTraversal(root);

    for(int i = 0; i < levelOrder.size(); i++)
    {
        for (int j = 0; j < levelOrder[i].size(); j++)
        {
            cout<<levelOrder[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}