#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

    boundary Traversal will print = 12->5->7->17->8->45->15
*/

class Tree
{
    public:
        int data;
        Tree* left;
        Tree* right;

        Tree(int data);
};

// constructor for the tree class
Tree :: Tree(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void leftTraversal(Tree* root, vector<int> &ans)
{
    if ((root == NULL) or ((root->left == NULL) and (root->right == NULL)))
    {
        return ;
    }

    ans.push_back(root->data);

    // traverse left
    if (root->left)
        leftTraversal(root->left, ans);

    // traverse right
    else
        leftTraversal(root->right, ans);
}

void leafTraversal(Tree* root, vector<int> &ans)
{
    if (root == NULL)
    {
        return ;
    }

    if ((root->left == NULL) and (root->right == NULL))
    {
        ans.push_back(root->data);
        return ;
    }

    // traverse in the inOrder fashion
    leafTraversal(root->left, ans);
    
    leafTraversal(root->right, ans);
}

void rightTraversal(Tree* root, vector<int> &ans)
{
    if ((root == NULL) or ((root->right == NULL) and (root->left == NULL)))
    {
        return ;
    }
    
    // traverse right first
    if (root->right)
        rightTraversal(root->right, ans);
    // traverse left then
    else
        rightTraversal(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Tree* root)
{
    vector<int> ans;
    // terminating condition
    if (root == NULL)
    {
        return ans;
    }

    // store the data in the data structure
    ans.push_back(root->data);
    
    // first traverse left for boundary traversal 
    leftTraversal(root->left, ans);

    // traverse all the leaf nodes

    // traverse left subtree
    leafTraversal(root->left, ans);
    // traverse right subtree
    leafTraversal(root->right, ans);
    // traverse the nodes of right of the tree in reverse fashion
    rightTraversal(root->right, ans);
}

int main()
{
    Tree *root = new Tree(12);
    Tree *child1 = new Tree(5);
    Tree *child2 = new Tree(15);
    Tree *child11 = new Tree(7);
    Tree *child12 = new Tree(17);
    Tree *child21 = new Tree(8);
    Tree *child22 = new Tree(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    cout<<"Boundary Traversal : "<<endl;
    vector<int> ans = boundaryTraversal(root);

    for (int i : ans)
    {
        cout<<i<<" ";
    }

    return 0;
}