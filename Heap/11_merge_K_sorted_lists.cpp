#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next, *tail;

        Node(int data);
};

Node :: Node(int data)
{
    this->data = data;
    this->next = NULL;
    this->tail = NULL;
}

class compare
{
    public:
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
};

Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    int k = listArray.size();
    
    if (k == 0)
        return NULL;
    
    for (int i = 0; i < k; i++)
    {
        if (listArray[i])
            minHeap.push(listArray[i]);
    }
    
    Node *head = NULL;
    Node *tail = NULL;
    
    while (minHeap.size() > 0)
    {
        Node *top = minHeap.top();
        minHeap.pop();
        
        if (top->next)
        {
            minHeap.push(top->next);
        }
        
        if (!head)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    // creation of linked list
    Node *head1 = new Node(4);
    Node *p1 = new Node(6);
    Node *p2 = new Node(8);

    Node *head2 = new Node(2);
    Node *q1 = new Node(5);
    Node *q2 = new Node(7);

    Node *head3 = new Node(1);
    Node *r1 = new Node(9);

    cout << "Merging the given lists produces -----"<<endl;
    
    vector<Node *> listArray{head1, p1, p2, NULL, head2, q1, q2, NULL, head3, r1, NULL};

    head1 = mergeKLists(listArray);

    while(head1)
    {
        cout << head1->data <<" ";
        head1 = head1->next;
    }

    return 0;
}