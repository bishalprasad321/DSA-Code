#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

    Top View Traversal will print = 7->5->12->15->45
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

void topView(Node* root)
{
    vector<int> ans; // data structure to store the traversal

    // condition to check empty tree node
    if (root == NULL)
    {
        for (int i : ans)
            cout<<i<<" ";
    }

    map<int, int> topNode; // map DS storing horizontal distance and tree node data
    queue<pair<Node*, int>> q; // Queue DS for storing the tree node and its horizontal distance

    q.push(make_pair(root, 0)); // push the pair for the root node with zero level

    while (!q.empty()) // loop until queue is empty
    {
        pair<Node*, int> temp = q.front(); // temporary pair to extract the tree node value and its horizontal distance
        q.pop(); 

        Node* frontNode = temp.first; // extracting tree node from the above pair
        int hd = temp.second; // extracting the horizontal distance

        if (topNode.find(hd) == topNode.end()) // check whether for a horizontal level, there is single node or not
            topNode[hd] = frontNode->data;

        if (frontNode->left) // pushing to the left sub tree, if present
            q.push(make_pair(frontNode->left, hd - 1));
        
        if (frontNode->right) // pushing to the right sub tree, if present
            q.push(make_pair(frontNode->right, hd + 1));
    }
    
    // storing into the desired data structure created for storing the traversal
    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    // consolling out whatever stored inside the desired data structure
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
    topView(root);

    return 0;
}