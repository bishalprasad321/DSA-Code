#include<bits/stdc++.h>
using namespace std;

class StackNode
{
    public:
        int data;
        StackNode* next;

        void traverse(StackNode *top);

        void push(StackNode **top, int value);
        void pop(StackNode **top);
        int peek(StackNode **top);
        int peekAt(StackNode **top, int position);
};

void StackNode:: push(StackNode **top, int value)
{
    StackNode *new_node = new StackNode();
    if (new_node == NULL)
    {
        cout<<"Stack overflow!!, cannot push "<<value<<" into the stack"<<endl;
    }
    else
    {
        new_node->data = value;
        new_node->next = (*top);
        (*top) = new_node;
    }
}

void StackNode:: pop(StackNode **top)
{
    if ((*top) == NULL)
    {
        cout<<"Stack Underflow!!"<<endl;
    }
    else
    {
        StackNode *new_node = (*top);
        (*top) = (*top)->next;
        free(new_node);
        cout<<"Popped Successfully!"<<endl;
    }
}

void StackNode :: traverse(StackNode *top)
{
    while (top->next != NULL)
    {
        cout<<"Element : "<<top->data<<endl;
        top = top->next;
    }
}

int StackNode :: peek(StackNode **top)
{
    return (*top)->data;
}

int StackNode :: peekAt(StackNode **top, int position)
{
    StackNode *looping_node = (*top);
    int i = 1;
    while (i != position)
    {
        looping_node = looping_node->next;
        i++;
    }
    if (looping_node != NULL)
    {
        return looping_node->data;
    }
    else
    {
        cout<<"ERROR!! No element at exist at this position."<<endl;
        exit(EXIT_FAILURE);
    }
}

int main()
{
    StackNode *top = NULL;
    top = new StackNode();
    StackNode stackLinkedList;
    stackLinkedList.push(&top, 7);
    stackLinkedList.push(&top, 17);
    stackLinkedList.push(&top, 7);
    stackLinkedList.push(&top, 13);
    stackLinkedList.push(&top, 18);
    stackLinkedList.push(&top, 21);
    stackLinkedList.push(&top, 13);

    cout<<"Element at the top is : "<<stackLinkedList.peek(&top)<<endl;
    cout<<"Element at a particular position is : "<<stackLinkedList.peekAt(&top, 3)<<endl;
    
    cout<<"Stack elements after pushing : "<<endl;
    stackLinkedList.traverse(top);

    stackLinkedList.pop(&top);
    stackLinkedList.pop(&top);
    stackLinkedList.pop(&top);

    cout<<"Stack Elements after popping : "<<endl;
    stackLinkedList.traverse(top);


    return 0;
}