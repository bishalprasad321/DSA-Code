#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        // constructor 
        Node(int value)
        {
            this->data = value;
            this->next = NULL;
        }

        // Function for traversing the Linked List.
        void traverse(Node* node);
};

class LinkedList
{
    public:
        Node* head;
        Node* tail;

        LinkedList()
        {
            this->head = NULL;
            this->tail = NULL;
        }

        void insertNode(int data);
};

void LinkedList :: insertNode(int data)
{
    Node* node = new Node(data);

    if (!this->head)
        this->head = node;
    else
        this->tail->next = node;
    
    this->tail = node;
}

void Node :: traverse(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Compare Linked List function implementation starts here.....
bool compareLinkedList(Node* head1, Node* head2)
{
    int countNode1 = 0, countNode2 = 0; // for counting the length of the linked lists
    Node* node1 = head1;
    Node* node2 = head2;

    while (head1 != NULL) // counting the length of the first linked list
    {
        countNode1++;
        head1 = head1->next;
    }

    while (head2 != NULL) // countting the length of the second linked list
    {
        countNode2++;
        head2 = head2->next;
    }

    if (countNode1 != countNode2) // checking if the length is same or not
        return 0;
    else
    {
        while (node1 && node2) 
        {
            if (node1->data != node2->data) // return false if the data at each of the nodes is different
                return 0;
            node1 = node1->next; // iterate to the next node of first linked list
            node2 = node2->next; // iterate to the next node of second linked list
        }
        return 1; // if the linked lists passes through the while loop, then return true.
    }
}

int main()
{
    int size1, size2;

    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();

    cout<<"Enter the size of the first linked list : ";
    cin>>size1;

    cout<<"Enter the values of the first linked list : ";
    for (int i = 0; i < size1; i++)
    {
        int list1Item;
        cin >> list1Item;

        list1->insertNode(list1Item);
    }

    cout<<"Enter the size of the second linked list : ";
    cin>>size2;

    cout<<"Enter the values of the second linked list : ";
    for (int i = 0; i < size2; i++)
    {
        int list2Item;
        cin>>list2Item;

        list2->insertNode(list2Item);
    }

    bool result = compareLinkedList(list1->head, list2->head);

    if (result)
        cout<<"Linked Lists are equal"<<endl;
    else
        cout<<"Linked Lists are not equal"<<endl;
    return 0;
}