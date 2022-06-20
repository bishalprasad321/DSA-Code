#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

    Bottom View will print = 7->5->8->15->45
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

// function is exact same as the top View of a tree 
void bottomView(Node* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        for (int i : ans)
            cout<<i<<" ";
    }

    map<int, int> topNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // there is no condition to check topNode.find(hd) == topNode.end(), as we have to update the values as going down the tree in same vertical line
        topNode[hd] = frontNode->data; 

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    for (int i : ans)
        cout<<i<<" ";
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

    cout<<"Top View Traversal : "<<endl;
    bottomView(root);

    return 0;
}