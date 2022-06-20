#include<bits/stdc++.h>
using namespace std;

class Node
{
    private:
        // Function for reversing the linked list - 01
        void reverse(Node* &head, Node* curr, Node* prev);

    public:
        int data;
        Node* next;

        // Function for traversing the Linked List.
        void traverse(Node* node);

        // Function for reversing recursively the linked list - 02
        Node* recursiveReverse(Node* head);
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

void Node :: reverse(Node* &head, Node* curr, Node* prev)
{
    // base condition for the recursive call 
    if (curr == NULL)
    {
        head = prev;
        return ;
    }
    
    // moving forward using the pointer and call the function recursively
    Node* forward = curr->next;
    reverse(head, forward, curr);

    // linking the next node to the previous pointer
    curr->next = prev;
}

Node* Node :: recursiveReverse(Node* head)
{
    // creating the nodes for the function
    Node* prev = NULL;
    Node* curr = head;

    // calling the reverse member function 
    reverse(head, curr, prev);

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

    cout<<"Linked List before reversing : ";
    LinkedList.traverse(head);

    head = LinkedList.recursiveReverse(head);
    cout<<"Linked List after recursive reversing : ";
    LinkedList.traverse(head);

    return 0;
}