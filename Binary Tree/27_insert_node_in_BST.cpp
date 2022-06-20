#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   new Node data = 3
   After inserting 3, in the above BST : 

        12
       /  \
      5    15
    /  \  / \
   4  11 13  45
  /
3 
    
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

Node* insertNode(Node* root, int data)
{
    if (!root) // create new node, if root is NULL
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data) // insert into the left subtree
    {
        root->left = insertNode(root->left, data);
    }

    if (data > root->data) // insert into the right subtree
    {
        root->right = insertNode(root->right, data);
    }
    return root;
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

    int newNodeData;

    cout << "Enter the node's data for the insertion in BST : ";
    cin >> newNodeData;

    root = insertNode(root, newNodeData);

    cout << "After insertion of the node : "<<endl;
    levelOrderTraversal(root);

    return 0;
}