#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Function for traversing the Linked List.
        void traverse(Node* node);

        // Functions for inserting elements at different positions in the Linked List.
        void push (Node** head, int data); 
        void insert (Node** head, int data, int index); 
        void append (Node** head, int data); 
        void insertAfterNode (Node** head, Node** prevNode, int data); 

        // Deletion of elements at different positions in the Linked List.
        void deleteHead (Node** head);
        void deleteAtIndex(Node** head, int index); 
        void pop (Node** head);
        void remove(Node** head, int data);
};

void Node :: traverse(Node* node)
{
    while (node != NULL)
    {
        cout<<"Element : "<<node->data<<endl;
        node = node->next;
    }
}

void Node :: push(Node** head, int data)
{
    Node* new_node = new Node();

    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void Node :: insert(Node** head, int data, int index)
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
}

void Node :: append(Node** head, int data)
{
    Node* new_node = new Node();
    Node* looping_node = (*head);

    while(looping_node->next != NULL)
    {
        looping_node = looping_node->next;
    }

    new_node->data = data;
    looping_node->next = new_node;
    new_node->next = NULL;
}

void Node :: insertAfterNode(Node** head, Node** prevNode, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*prevNode)->next;
    (*prevNode)->next = new_node;
}

void Node :: deleteHead(Node** head)
{
    Node* new_node = (*head);
    (*head) = (*head)->next;
    free(new_node);
}

void Node :: deleteAtIndex(Node** head, int index)
{
    Node* new_node = (*head);
    int i = 0;
    while (i != index - 1)
    {
        new_node = new_node->next;
        i++;
    }
    Node* temp_node = new_node->next;
    new_node->next = temp_node->next;
    free(temp_node);
}

void Node :: pop(Node** head)
{
    Node* new_node = (*head);
    Node* looping_node = (*head)->next;
    while (looping_node->next != NULL)
    {
        looping_node = looping_node->next;
        new_node = new_node->next;
    }
    new_node->next = NULL;
    free(looping_node);
}

void Node :: remove(Node** head, int value)
{
    Node* new_node = (*head);
    Node* looping_node = (*head)->next;
    while (looping_node->data != value && looping_node->next != NULL)
    {
        new_node = new_node->next;
        looping_node = looping_node->next;
    }

    if (looping_node->data == value)
    {
        new_node->next = looping_node->next;
        free(looping_node);
    }

    else
    {
        cout<<"Element not found in the given Linked List!!"<<endl;
    }

}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    Node LinkedList;

    head = new Node();    
    second = new Node();    
    third = new Node();    
    fourth = new Node();    

    head->data = 96;
    head->next = second;

    second->data = 82;
    second->next = third;

    third->data = 74;
    third->next = fourth;

    fourth->data = 46;
    fourth->next = NULL;

    cout<<"Before insertion at the start : "<<endl;
    LinkedList.traverse(head);

    head->push(&head, 12);
    cout<<"After insertion at the start : "<<endl;
    LinkedList.traverse(head);

    cout<<"After Inserting at a particular index : "<<endl;
    LinkedList.insert(&head, 102, 2);
    LinkedList.traverse(head);

    cout<<"After Inserting at the end : "<<endl;
    LinkedList.append(&head, 7);
    LinkedList.traverse(head);

    cout<<"After inserting at a specific node : "<<endl;
    LinkedList.insertAfterNode(&head, &third, 47);
    LinkedList.traverse(head);

    cout<<"Popping out the first element : "<<endl;
    LinkedList.deleteHead(&head);
    LinkedList.traverse(head);

    cout<<"Removing the element at a particular index : "<<endl;
    LinkedList.deleteAtIndex(&head, 3);
    LinkedList.traverse(head);

    cout<<"Popping out the last element : "<<endl;
    LinkedList.pop(&head);
    LinkedList.traverse(head);

    cout<<"Removing the last element of the list : "<<endl;
    LinkedList.remove(&head, 102);
    LinkedList.traverse(head);

    return 0;
}