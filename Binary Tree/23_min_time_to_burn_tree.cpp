#include <bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12
       /  \
      5    15
    /  \  / \
   7  17 8  45
       \      \
        4      19

    Target Node -> 45. 
    Minimum time to burn tree from target node -> 5 seconds

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

Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);

    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
            res = front;

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left); 
        }

        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}
int burnTree(Node *targetNode, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited;

    queue<Node *> q;

    q.push(targetNode);

    int time = 0;

    visited[targetNode] = true;

    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left and !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right and !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToParent[front] and !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag == 1)
            time++;
    }
    return time;
}

int minTime(Node *root, int target)
{
    // algorithm
    // 1st step : create node to Parent mapping
    // 2nd step : find the target node
    // 3rd step : burn the tree in the min time

    map<Node *, Node *> nodeToParent;

    Node *targetNode = createMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(7);
    Node *child12 = new Node(17);
    Node *child122 = new Node(4);
    Node *child21 = new Node(8);
    Node *child22 = new Node(45);
    Node *child222 = new Node(19);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child12->right = child122;

    child2->left = child21;
    child2->right = child22;

    child22->right = child222;

    int time = minTime(root, 45);
    cout<< "The time for burning the entire tree : " << time << endl;

    return 0;
}