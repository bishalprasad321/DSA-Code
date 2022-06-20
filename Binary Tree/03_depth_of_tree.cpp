#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node 
       /  \
      4    6 -> parent node
    /  \  / \ 
   8  10 7   5 -> child node (leaf node)

   depth of the above tree - 3
*/

class BinaryTree
{
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        // function for BinaryTree to set a new node
        BinaryTree* createNode(int data);
        // function for calculating the maximum depth of the tree
        int maxDepth(BinaryTree* root);
};

BinaryTree* BinaryTree :: createNode(int data)
{
    BinaryTree *new_node = new BinaryTree(); // allocating free space in heap for a new node
    new_node->data = data; // binding the data of new node to given data
    new_node->left = NULL; // assigning the left leaf node to NULL
    new_node->right = NULL; // assigning the right leaf node to NULL
    return new_node;
}

int BinaryTree :: maxDepth(BinaryTree* root)
{
    // Base condition
    if (root == NULL)
        return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (1 + max(left, right));
}

int main()
{
    BinaryTree binaryTree; // binary tree object

    BinaryTree* root = binaryTree.createNode(12); // creating root node
    BinaryTree* parent1 = binaryTree.createNode(4); // creating left parent node of root
    BinaryTree* parent2 = binaryTree.createNode(6); // creating right parent node of root 
    BinaryTree* child11 = binaryTree.createNode(8); // creating left child node of left parent from root
    BinaryTree* child12 = binaryTree.createNode(10); // creating right child node of left parent from root
    BinaryTree* child21 = binaryTree.createNode(7); // creating left child node of right parent from root
    BinaryTree* child22 = binaryTree.createNode(5); // creating right child node of right parent from root

    // linking the root with it's child(s) 
    root->left = parent1; 
    root->right = parent2;

    // linking left parent node from root to it's child(s)
    parent1->left = child11;
    parent1->right = child12;

    // linking right parent node from root to it's child(s)
    parent2->left = child21;
    parent2->right = child22;

    int depth = binaryTree.maxDepth(root);
    cout<<"The depth of the given tree is : "<<depth<<endl;
    
    return 0;
}