#include <bits/stdc++.h>
using namespace std;

class Node
{
  public :
    int data;
    Node *left, *right;
    
    Node(int data);
};

Node :: Node (int data)
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

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return ;
        
    // left call
    inOrder(root->left, ans);
    
    // push the node's data
    ans.push_back(root->data);
    
    // right call 
    inOrder(root->right, ans);
}

void filledPreOrder(Node * &root, vector<int> inOrderVal, int *index)
{
    // base case
    if (!root)
        return ;
    
    // populate the node's data
    root->data = inOrderVal[++*index];
    
    // left call
    filledPreOrder(root->left, inOrderVal, index);
    
    // right call
    filledPreOrder(root->right, inOrderVal, index);
}

Node *BSTtoMinHeap(Node *root)
{
    vector<int> inOrderVal;
    
    // store inOrder values
    inOrder(root, inOrderVal);
    
    // populate the tree with the preorder condition
    int i = -1;
    filledPreOrder(root, inOrderVal, &i);
    
    return root;
}

int main() 
{
	Node *root = new Node(4);
    Node *child1 = new Node(2);
    Node *child2 = new Node(6);
    Node *child11 = new Node(1);
    Node *child12 = new Node(3);
    Node *child21 = new Node(5);
    Node *child22 = new Node(7);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;
    
    root = BSTtoMinHeap(root);
    
    // printing the tree after conversion
    levelOrderTraversal(root);
    
	return 0;
}