#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void LinkedListTraversal(Node *node)
{
    while (node != NULL)
    {
        cout <<"Element : "<< node->data << endl;
        node = node->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 63;
    head->next = second;

    second->data = 82;
    second->next = third;

    third->data = 74;
    third->next = fourth;

    fourth->data = 96;
    fourth->next = NULL;

    LinkedListTraversal(head);

    return 0;
}