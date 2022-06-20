#include<bits/stdc++.h>
using namespace std;

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

void diagonalTraverse(Node* root, vector<int> &ans, int level)
{
    if (!root) return;
    
    if (level == ans.size())
        ans.push_back(root->data);

    diagonalTraverse(root->left, ans, level + 1);

    diagonalTraverse(root->right, ans, level);
}

vector<int> diagonalView(Node* root)
{
    vector<int> ans;
    diagonalTraverse(root, ans, 0);
    return ans;
}

int main()
{
    
    return 0;
}