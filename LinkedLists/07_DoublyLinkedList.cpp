#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data; 
        Node* next;
        Node* previous;

        void traverse(Node* head);
        void traverse_back(Node* tail);

        void insertStart(Node** head, int data);
        void insertAt(Node** head, int data, int index);
};

void Node :: traverse(Node* head)
{
    while (head != NULL)
    {
        cout<<"Element : "<<head->data<<endl;
        head = head->next;
    }
}

void Node :: traverse_back(Node* tail)
{
    while (tail != NULL)
    {
        cout<<"Element : "<<tail->data<<endl;
        tail = tail->previous;
    }
}

void Node :: insertStart(Node** head, int data)
{
    Node* new_node = new Node();
    new_node-> data = data;
    new_node->next = (*head);
    (*head) = new_node;
    new_node->previous = NULL;
}

void Node :: insertAt(Node** head, int data, int index)
{
    Node* new_node = new Node();
    Node* looping_node = (*head);
    int i = 0;
    while (i != index - 1)
    {
        looping_node = looping_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = looping_node->next;
    looping_node->next = new_node;
    new_node->previous = looping_node;
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* tail = new Node();

    Node doublyLinkedList; 

    head->data = 96;
    head->next = second;
    head->previous = NULL;

    second->data = 82;
    second->next = third;
    second->previous = head;

    third->data = 74;
    third->next = tail;
    third->previous = second;

    tail->data = 46;
    tail->next = NULL;
    tail->previous = third;

    cout<<"Traversing the elements of Doubly Linked List from front to back : "<<endl;
    doublyLinkedList.traverse(head);

    cout<<"Traversing the elements of Doubly Linked List from tail to head : "<<endl;
    doublyLinkedList.traverse_back(tail);

    cout<<"After the insertStart operation in Doubly Linked List : "<<endl;
    doublyLinkedList.insertStart(&head, 16);
    doublyLinkedList.traverse(head);
    
    cout<<"After the insertAt operation in Doubly Linked List : "<<endl;
    doublyLinkedList.insertAt(&head, 31, 2);
    doublyLinkedList.traverse(head);
    return 0;
}