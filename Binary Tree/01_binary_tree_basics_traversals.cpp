#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node 
       /  \
      4    6 -> parent node
    /  \  / \ 
   8  10 7   5 -> child node (leaf node)
*/

class BinaryTree
{
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        // function for BinaryTree to set a new node
        BinaryTree* createNode(int data);
        // preOrder traversal function for binary tree
        void preOrderTraversal(BinaryTree* root);
        // postOrder traversal function for binary tree
        void postOrderTraversal(BinaryTree* root);
        // inOrder traversal function for binary tree
        void inOrderTraversal(BinaryTree* root);
};

BinaryTree* BinaryTree :: createNode(int data)
{
    BinaryTree *new_node = new BinaryTree(); // allocating free space in heap for a new node
    new_node->data = data; // binding the data of new node to given data
    new_node->left = NULL; // assigning the left leaf node to NULL
    new_node->right = NULL; // assigning the right leaf node to NULL
    return new_node;
}

void BinaryTree :: preOrderTraversal(BinaryTree* root)
{
    if (root != NULL) // recursively call until root is NULL
    {
        cout<<root->data<<" "; // [preOrder : root -> left -> right] following this order root->data is first printed
        preOrderTraversal(root->left); // calling preOrderTraversal for left node of the root
        preOrderTraversal(root->right); // calling preOrderTraversal for right node of the root
    }
}

void BinaryTree :: postOrderTraversal(BinaryTree* root)
{
    if (root != NULL) // [postOrder : left -> right -> root] following this oder postOrder traversal for left, then right & then root is printed
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

void BinaryTree :: inOrderTraversal(BinaryTree* root)
{
    if (root != NULL) // [inOrder : left -> root -> right] following this order inOrder traversal for left, then root node is printed & then right is called
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
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

    // calling preOrderTraversal for printing binary tree in (root -> left -> right) manner
    binaryTree.preOrderTraversal(root);
    cout<<endl;

    // calling postOrderTraversal for printing binary tree in (left -> right -> root) manner
    binaryTree.postOrderTraversal(root);
    cout<<endl;

    // calling inOrderTraversal for printing binary tree in (left -> root -> right) manner
    binaryTree.inOrderTraversal(root);
    cout<<endl;

    return 0;
}