#include<bits/stdc++.h>
using namespace std;

/* 
        12
       /  \
      5    15
    /  \  / \
   4  11 13  45

   let Target = 20, find a pair in the BST, whose sum = target (in this case 5 and 15, so )
    
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

void inOrder(Node *root, vector<int> &ans)
{
    if (!root)
        return ;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool twoSum(Node *root, int target)
{
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);

    int i = 0, j = inOrderVal.size() - 1;

    while (i < j)
    {
        int sum = inOrderVal[i] + inOrderVal[j];

        if (sum == target)
            return true;
        
        else if (sum < target)
            i++;

        else 
            j--;
    }
    return false;
}

int main()
{
    Node *root = new Node(12);
    Node *child1 = new Node(5);
    Node *child2 = new Node(15);
    Node *child11 = new Node(4);
    Node *child12 = new Node(11);
    Node *child21 = new Node(13);
    Node *child22 = new Node(45);

    root->left = child1;
    root->right = child2;

    child1->left = child11;
    child1->right = child12;

    child2->left = child21;
    child2->right = child22;

    int target;
    cout << "Enter the target for sum : ";
    cin >> target;

    if (twoSum)
        cout << "Yes!! Pair Exists." << endl;

    else
        cout << "No!! No such pair exists in BST, which sum to target." << endl;
        
    return 0;
}