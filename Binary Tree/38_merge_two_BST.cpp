#include<bits/stdc++.h>
using namespace std;

/* 
    BST 01 ---------->

        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   BST 02 ----------->

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

vector<int> merge(vector<int> bst1, vector<int> bst2)
{
    int s1 = bst1.size();
    int s2 = bst2.size();
    
    vector<int> merged(s1 + s2, 0);
    
    int i = 0, j = 0, k = 0;
    
    while (i < s1 and j < s2)
    {
        if (bst1[i] < bst2[j])
            merged[k++] = bst1[i++];
        else
            merged[k++] = bst2[j++];
    }
    
    while (i < s1)
        merged[k++] = bst1[i++];
    
    while(j < s2)
        merged[k++] = bst2[j++];

    return merged;
}

Node *convertToBST(vector<int> merged, int start, int end)
{
    if (start > end)
        return NULL;
    
    int mid = (start + end)/2;
    
    Node *root = new Node (merged[mid]);
    
    root->left = convertToBST(merged, start, mid - 1);
    root->right = convertToBST(merged, mid + 1, end);
    
    return root;
}

Node *mergeBST(Node *root1, Node *root2){
    // Write your code here.
    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);
    
    vector<int> bst = merge(bst1, bst2);
    
    return convertToBST(bst, 0, bst.size() - 1);
}

int main()
{
    Node *root1 = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(4);
    Node *child12 = new Node(11);
    Node *child21 = new Node(13);
    Node *child22 = new Node(45);

    root1->left = child1;
    root1->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    Node *root2 = new Node(10);
    Node *Child1 = new Node(4);
    Node *Child2 = new Node(16);
    Node *Child11 = new Node(2);
    Node *Child12 = new Node(8);
    Node *Child21 = new Node(12);
    Node *Child22 = new Node(20);

    root2->left = Child1;
    root2->right = Child2;

    Child1->left = Child11;
    Child1->right = Child12;

    Child2->left = Child21;
    Child2->right = Child22;

    Node *root = mergeBST(root1, root2);

    cout << "After merging the given BST's" << endl;

    levelOrderTraversal(root);

    return 0;
}