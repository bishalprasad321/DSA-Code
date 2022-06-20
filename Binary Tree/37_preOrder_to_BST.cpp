#include<bits/stdc++.h>
using namespace std;

/* 
        10
       /  \
      4    16
    /  \  / \
   2   8 12  20


    
*/

class Node
{
    public:
        int data;
        Node *left, *right;

        Node(int data);
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

Node* preOrderToBST(vector<int> &preOrder, int mini, int maxi, int &i)
{
    if (i >= preOrder.size())
        return NULL;
    
    if (preOrder[i] < mini or preOrder[i] > maxi)
        return NULL;
    
    Node *newRoot = new Node(preOrder[i++]);
    
    newRoot->left = preOrderToBST(preOrder, mini, newRoot->data, i);
    newRoot->right = preOrderToBST(preOrder, newRoot->data, maxi, i);
    
    return newRoot;
}

int main()
{
    vector<int> preOrder{20, 10, 5, 15, 13, 35, 30, 42};

    int i = 0;

    Node *root = preOrderToBST(preOrder, INT_MIN, INT_MAX, i);

    cout << "Level Order Traversal of BST from PreOrder"<<endl;

    levelOrderTraversal(root);
    
    return 0;
}