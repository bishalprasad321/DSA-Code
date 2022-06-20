#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        void traverse(Node* head);

        void push_start(Node** head, int data);
        void push_at(Node** head, int data, int index);
        void push_end(Node** head, int data);
        void push_after(Node** head, Node** prevNode, int data);

        void deleteHead(Node** head);
        void deleteAt(Node** head, int index);
        void deleteEnd(Node** head);
        void deleteAfter(Node** head, Node** prevNode);
        void remove(Node** head, int data);
};

void Node :: traverse(Node* head)
{
    Node* new_node = head;

    /*while (new_node->next != (*head))
    {
        cout<<"Element : "<<new_node->data<<endl;
        new_node = new_node->next;
    }
    cout<<"Element : "<<new_node->data<<endl;*/

    do 
    {
        cout<<"Element : "<<new_node->data<<endl;
        new_node = new_node->next;
    }
    while (new_node != head);
}

void Node :: push_start(Node** head, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    Node* looping_node = (*head)->next;

    while(looping_node->next != (*head))
    {
        looping_node = looping_node->next;
    }

    looping_node->next = new_node;
    new_node->next = (*head);
    (*head) = new_node;
}

void Node :: push_at(Node** head, int data, int index)
{
    Node* new_node = new Node();
    Node* looping_node = (*head);
    new_node->data = data;
    int i = 0;
    while (i != index - 1)
    {
        looping_node = looping_node->next;
        i++;
    }
    new_node->next = looping_node->next;
    looping_node->next = new_node;
}

void Node :: push_end(Node** head, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    Node* looping_node = (*head);

    while(looping_node->next != (*head))
    {
        looping_node = looping_node->next;
    }

    looping_node->next = new_node;
    new_node->next = (*head);
}

void Node :: push_after(Node** head, Node** prevNode, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    Node* looping_node = (*head);

    while (looping_node != (*prevNode))
    {
        looping_node = looping_node->next;
    }
    new_node->next = looping_node->next;
    looping_node->next = new_node;
}

void Node :: deleteHead(Node** head)
{
    Node* new_node = (*head);
    while (new_node->next != (*head))
    {
        new_node = new_node->next;
    }
    Node* temp_node = new_node->next;
    new_node->next = temp_node->next;
    (*head) = new_node->next;
    free(temp_node);
}

void Node :: deleteAt(Node** head, int index)
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

void Node :: deleteEnd(Node** head)
{
    Node* new_node = (*head);
    Node* looping_node = new_node->next;

    while (looping_node->next != (*head))
    {
        looping_node = looping_node->next;
        new_node = new_node->next;
    }
    new_node->next = looping_node->next;
    free(looping_node);
}

void Node :: deleteAfter(Node** head, Node** prevNode)
{
    Node* new_node = (*head);
    Node* looping_node = new_node->next;

    while(looping_node != (*prevNode))
    {
        looping_node = looping_node->next;
        new_node = new_node->next;
    }
    new_node->next = looping_node->next;
    free(looping_node);
}

void Node :: remove(Node** head, int data)
{
    Node* new_node = (*head);
    Node* looping_node = new_node->next;

    while (looping_node->data != data && looping_node != (*head))
    {
        looping_node = looping_node->next;
        new_node = new_node->next;
    }

    if (looping_node->data == data)
    {
        new_node->next = looping_node->next;
        free(looping_node);
    }

    else
    {
        cout<<"Element not found in the given Circular Linked List!!!"<<endl;
    }
}

int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    Node circularLinkedList; 

    head->data = 96;
    head->next = second;

    second->data = 82;
    second->next = third;

    third->data = 74;
    third->next = fourth;

    fourth->data = 46;
    fourth->next = head;

    cout<<"Before any operation on Linked List : "<<endl;
    circularLinkedList.traverse(head);

    cout<<"Linked List after push_start operation : "<<endl;
    circularLinkedList.push_start(&head, 19);
    circularLinkedList.traverse(head);

    cout<<"Linked List after pushing at specific index : "<<endl;
    circularLinkedList.push_at(&head, 73, 2);
    circularLinkedList.traverse(head);

    cout<<"Linked List after push_end operation : "<<endl;
    circularLinkedList.push_end(&head, 7);
    circularLinkedList.traverse(head);

    cout<<"Linked List after push_after operation : "<<endl;
    circularLinkedList.push_after(&head, &third, 22);
    circularLinkedList.traverse(head);

    cout<<"Linked List after deleteHead operation : "<<endl;
    circularLinkedList.deleteHead(&head);
    circularLinkedList.traverse(head);

    cout<<"Linked List after deleteAt operation :"<<endl;
    circularLinkedList.deleteAt(&head, 4);
    circularLinkedList.traverse(head);

    cout<<"Linked List after deleteEnd operation : "<<endl;
    circularLinkedList.deleteEnd(&head);
    circularLinkedList.traverse(head);

    cout<<"Linked List after deleteAfter operation : "<<endl;
    circularLinkedList.deleteAfter(&head, &fourth);
    circularLinkedList.traverse(head);

    cout<<"Linked List after remove operation : "<<endl;
    circularLinkedList.remove(&head, 74);
    circularLinkedList.traverse(head);

    return 0;
}