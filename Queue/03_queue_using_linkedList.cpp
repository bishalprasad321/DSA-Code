#include<bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

    public:
        void queue_with_linkedList_traversal(Node *front, Node *back);
        void enqueue(Node **front, Node **back, int value);
        int dequeue(Node **front, Node **back);
        bool isEmpty(Node **front, Node **back);
        bool isFull(Node **front, Node **back);
};

void Node :: queue_with_linkedList_traversal(Node *front, Node *back)
{
    while (front->next != NULL)
    {
        cout<<"Element : "<<front->data<<endl;
        front = front->next;
    }
}

bool Node :: isEmpty(Node **front, Node **back)
{
    if ((*front)->next == (*back)->next)
    {
        return true;
    }
    else return false;
}

bool Node :: isFull(Node **front, Node **back)
{
    Node *new_node = new Node();
    if (new_node == NULL)
    {
        return true;
    }
    else return false;
}

void Node :: enqueue(Node **front, Node **back, int value)
{
    if (isFull(front, back))
    {
        cout<<"Queue is full!! "<<value<<" cannot be added to the queue."<<endl;
    }
    else
    {
        Node *new_node = new Node();
        new_node->data = value;
        (*back)->next = new_node;
        new_node->next = NULL;
        (*back) = new_node;
    }
}

int Node :: dequeue(Node **front, Node **back)
{
    if (isEmpty(front, back))
    {
        cout<<"Queue is empty!!"<<endl;
        return -1;
    }
    else
    {
        Node *new_node = (*front);
        (*front) = (*front)->next;
        free(new_node);        
    }
}

int main()
{
    
    return 0;
}