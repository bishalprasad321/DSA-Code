#include<bits/stdc++.h>
using namespace std;

/* Binary Search Tree : It is a special type of binary tree, in which each and every node of 
    the left part of the tree is less than each and every node of the right part of the tree


    If the inputs for a binary search tree are given as : 12->5->15->4->11->13->45
    Then, the tree will look like as shown below......

        12
       /  \
      5    15
    /  \  / \
   4  11 13  45
    
*/

class Node
{
    public:
        int data;
        Node *left, *right;

        // constructor
        Node (int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

// function for preOder traversal
void preOrder(Node *root)
{
    if (root)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// function for level order traversal 
void levelOrderTraversal (Node* root)
{
    if (root == NULL)
        return ;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            
            cout<<node->data<<" ";
        }
        cout<<endl;
    }
}

// function to build the binary search tree from the given inputs by the user
Node *buildBST(Node *root, int data)
{
    if (!root) // if root is NULL, then create a new node with the given data
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data) // insert into left subtree
    {
        root->left = buildBST(root->left, data);
    }

    else // insert into right subtree
    {
        root->right = buildBST(root->right, data);
    }
    
    return root;
}

// function to take input from the user and build the BST on runtime
void takeInput(Node* &root, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = buildBST(root, data);
    }
}

int main()
{
    int n;
    Node *root = NULL;
    cout << "Enter the total number of nodes : ";
    cin >> n;
    cout << "Enter the nodes .........."<<endl;

    takeInput(root, n);

    cout<<"preOrder of the BST formed : ";
    preOrder(root);

    cout<<endl<<"levelOrder of the BST formed : "<<endl;
    levelOrderTraversal(root);

    return 0;
}