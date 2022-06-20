#include<bits/stdc++.h>
using namespace std;

#define SIZE 10

class Stack
{
    public:
        int top;
        int capacity;
        int *arr;

        // Constructor
        Stack(int size = SIZE);

        // Destructor
        ~Stack();

        // all the functions implementations
        bool isFull();
        bool isEmpty();
        int stackTop();
        int stackBottom();
        int peek(int position);
        void push(int value);
        void pop();
        int size();

        void printStack();
};

Stack :: Stack(int size)
{
    top = -1;
    arr = new int[size];
    capacity = size;
}

Stack :: ~Stack()
{
    delete []arr;
}

bool Stack :: isFull()
{
    if (top == capacity - 1) return true;
    else return false;
}

bool Stack :: isEmpty()
{
    if (top == -1) return true;
    else return false;
}

int Stack :: stackTop()
{
    return arr[top];
}

int Stack :: stackBottom()
{
    return arr[0];
}

int Stack :: peek(int position)
{
    if (position > capacity || position < 0)
    {
        cout<<"Position beyond stack capacity reach!!"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        return arr[(top - position) + 1];
    }
}

void Stack :: push(int value)
{
    if (isFull())
    {
        cout<<"Stack Overflow!!"<<" cannot push "<<value<<" to the stack!!"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout<<"Pushing into the stack ---"<<endl;
        arr[top += 1] = value;
    }
}

void Stack :: pop()
{
    if (isEmpty())
    {
        cout<<"Stack Underflow!!"<<endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout<<"Popping out "<<stackTop()<<endl;
        top -= 1;
    }
}

int Stack :: size()
{
    return top + 1;
}

void Stack :: printStack()
{
    int i = 1;
    while (i <= top + 1)
    {
        cout<<"Element : "<<peek(i)<<endl;
        i++;
    }
}

int main()
{
    Stack s(7);

    cout<<"Is stack empty at this point : "<<s.isEmpty()<<endl;
    
    s.push(12);
    s.push(98);
    s.push(45);
    s.push(78);
    s.push(19);
    s.push(13);
    s.push(7);
    
    cout<<"Is stack full at this point : "<<s.isFull()<<endl;
    
    s.pop();
    s.pop();
    s.pop();

    cout<<"Stack size at this point : "<<s.size()<<endl;

    s.printStack();

    return 0;
}