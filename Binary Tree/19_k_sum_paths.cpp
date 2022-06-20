#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 
       /  \
      5    15 
    /  \  / \
   7  17 8  45
       \      \
        4      19

    for K = 17, the above tree has 2 kPathSum (i.e. 12->5 and 17)
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

void kSum(Node *root, int k, int &count, vector<int> path)
{
    if (!root)
        return ;
    
    path.push_back(root->data);

    kSum(root->left, k, count, path);
    kSum(root->right, k, count, path);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    path.pop_back();
}

int kSumPath(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    kSum(root, k, count, path);
    return count;
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

    int pathSum = kSumPath(root, 17);

    cout<<"K Sum Path according to given tree and K is : "<<pathSum<<endl;

    return 0;
}