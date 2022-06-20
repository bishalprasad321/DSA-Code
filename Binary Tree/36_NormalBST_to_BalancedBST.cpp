#include<bits/stdc++.h>
using namespace std;

/* 
        10
       /  \
      8    12
    /       \
   4        16
  /          \
 2           20

   Normal BST --------------->>> Balanced BST 

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

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return ;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

Node *normalToBalanced(int start, int end, vector<int> inOrderVal)
{
    // base case
    if (start > end)
        return NULL;

    // position of the root 
    int mid = (start + end)/2;

    // defining root of balanced BST
    Node *newRoot = new Node(inOrderVal[mid]);

    // left subtree 
    newRoot->left = normalToBalanced(start, mid - 1, inOrderVal);

    // right subtree
    newRoot->right = normalToBalanced(mid + 1, end, inOrderVal);

    return newRoot;
}

int main()
{
    Node *root = new Node(10);
    Node *child1 = new Node(8);
    Node *child2 = new Node(12);
    Node *child11 = new Node(4);
    Node *child22 = new Node(16);
    Node *child111 = new Node(2);
    Node *child222 = new Node(20);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child2->right = child22;

    child11->left = child111;
    child22->right = child222;

    vector<int> inOrderVal;

    inOrder(root, inOrderVal);

    root = normalToBalanced(0, inOrderVal.size() - 1, inOrderVal);

    cout << "LevelOrder after Balacing the given BST" << endl;

    levelOrderTraversal(root);
    
    return 0;
}