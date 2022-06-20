#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // Function for traversing the Linked List.
        void traverse(Node* node);

        // Function for reversing the linked list
        Node* reverse(Node* head);
};

void Node :: traverse(Node* node)
{
    while (node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

Node* Node :: reverse(Node* head)
{
    // using 3 pointers
    Node* firstPtr = head;
    Node* secondPtr = nullptr;
    Node* thirdPtr = nullptr;

    while (firstPtr != nullptr)
    {
        thirdPtr = secondPtr;
        secondPtr = firstPtr;
        firstPtr = firstPtr->next;

        secondPtr->next = thirdPtr;
    }
    head = secondPtr;
    return head;
}

int main()
{
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;

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

    cout<<"LinkedList before reversing : ";
    LinkedList.traverse(head);

    head = LinkedList.reverse(head);

    cout<<"LinkedList after reversing : ";
    LinkedList.traverse(head);

    return 0;
}