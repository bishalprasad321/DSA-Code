#include <bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   Node to Delete : 15
   after deletion

        12
       /  \
      5    13
    /  \     \
   4  11     45
    
*/

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data);
};

Node ::Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

int minValue(Node *root)
{
    if (!root)
        return -1;

    Node *temp = root;

    while (temp->left)
    {
        temp = temp->left;
    }

    return temp->data;
}

int maxValue(Node *root)
{
    if (!root)
        return -1;

    Node *temp = root;

    while (temp->right)
    {
        temp = temp->right;
    }

    return temp->data;
}

Node *deleteBSTNode(Node *root, int value)
{
    if (root->data == value)
    {
        // case 01 : node with no child
        if (!root->left and !root->right)
        {
            delete root;
            return NULL;
        }

        // case 02 : node with single child
        // left child is present
        if (root->left and !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child is present
        if (root->right and !root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case 03 : node with double child
        if (!root->left and !root->right)
        {
            int mini = minValue(root);
            root->data = mini;
            root->right = deleteBSTNode(root->right, mini);
            return root;
        }
    }

    else if (value < root->data)
    {
        root->left = deleteBSTNode(root->left, value);
        return root;
    }

    else
    {
        root->right = deleteBSTNode(root->right, value);
        return root;
    }
}

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

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(4);
    Node *child12 = new Node(11);
    Node *child21 = new Node(13);
    Node *child22 = new Node(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    int del;

    cout << "Enter the node's data to delete : ";
    cin >> del;

    root = deleteBSTNode(root, del);

    cout << "Level Order of the BST after deletion of " << del << endl;
    levelOrderTraversal(root);

    return 0;
}