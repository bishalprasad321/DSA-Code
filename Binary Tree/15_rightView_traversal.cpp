#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node                     ]
       /  \                                 |
      5    15 -> parent node                |
    /  \  / \                               |
   7  17 8  45 -> child node (leaf node)    ]
                                            
    Right View Traversal will print = 12->15->45
*/

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void recursiveRightView(Node* root, vector<int> &ans, int level)
{
    if (root == NULL)
        return ;
    
    if (level == ans.size())
        ans.push_back(root->data);
    
    // traverse right subtree for the next level
    recursiveRightView(root->right, ans, level + 1);
    // traverse left subtree for the next level
    recursiveRightView(root->left, ans, level + 1);
}

vector<int> rightView(Node* root)
{
    vector<int> ans;
    recursiveRightView(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(7);
    Node *child12 = new Node(17);
    Node *child21 = new Node(8);
    Node *child22 = new Node(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    cout<<"Right View of the given Tree : "<<endl;
    vector<int> result = rightView(root);

    for (int i : result)
        cout<<i<<" ";

    return 0;
}