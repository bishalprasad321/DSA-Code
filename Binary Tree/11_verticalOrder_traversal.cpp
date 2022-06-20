#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 -> root node
       /  \
      5    15 -> parent node
    /  \  / \
   7  17 8  45 -> child node (leaf node)

    verticalOrder Traversal will print = 7->5->12->17->8->15->45
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

vector<int> verticalOrder(Node* root)
{
    vector<int> order; // data structure to store the traversed nodes

    queue<pair<Node*, pair<int, int>>> q; // Queue -> {Node, (horizontal distance, Vertical distance)}

    map<int, map<int, vector<int>>> nodes; // Map -> {Horizontal distance, (Vertical distance, vector of elements in the same vertical line)}

    // condition to check empty tree
    if (root == NULL)
        return order;

    // push the root into the zeroth horizontal and vertical distance of the queue
    q.push(make_pair(root, make_pair(0, 0)));

    // loop until the queue is empty
    while (!q.empty())
    {
        pair<Node*, pair<int, int>> temp = q.front(); // store the front pair temporarily for the current iteration of the loop
        q.pop();

        Node* node = temp.first; // extract the node from the above pair
        int hd = temp.second.first; // exrtact the horizontal distance
        int vd = temp.second.second; // extract the vertical distance

        nodes[hd][vd].push_back(node->data); // pushBack the node->data into its correct hd and vd

        if (node->left) // push the pair for the left subtree, if available
            q.push(make_pair(node->left, make_pair(hd-1, vd+1)));

        if (node->right) // push the pair for the right subtree, if available
            q.push(make_pair(node->right, make_pair(hd+1, vd+1))); 
    }

    // storing the node datas from the map into our desired data structure
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k: j.second)
            {
                order.push_back(k);
            }
        }
    }

    return order;

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

    cout<<"Vertical Order Traversal : "<<endl;

    vector<int> result = verticalOrder(root);
    for (int i : result)
    {
        cout<<i<< " ";
    }
   
    return 0;
}