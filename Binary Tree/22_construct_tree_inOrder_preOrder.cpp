#include<bits/stdc++.h>
using namespace std;

/* Binary Tree Representation
        12 
       /  \
      5    15 
    /  \  / \
   7  17 8  45

    inOrder = [7,5,17,12,8,15,45]
    preOrder = [12,5,7,17,15,8,45]
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

int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}

Node *buildTree (int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    if (index >= n or inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = findPosition(in, element, n);

    // left call
    root->left = buildTree(in, pre, index, inOrderStart, position - 1, n);
    // right call
    root->right = buildTree(in, pre, index, position + 1, inOrderEnd, n);

    return root;
}

void postOrderTraversal(Node *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    int in[] = {7,5,17,12,8,15,45};
    int pre[] = {12,5,7,17,15,8,45};

    int n = 7;

    int preOrderIndex = 0;

    Node *constructedTree = buildTree(in, pre, preOrderIndex, 0, n - 1, n);

    cout<<"Post Order Traversal of the constructed Binary Tree is : "<<endl;

    postOrderTraversal(constructedTree);

    return 0;
}