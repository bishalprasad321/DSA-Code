#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int top;
    char *arr;
    int size;
    Stack()
    {
        top = -1;
        size = 100;
    }
};

bool isFull(struct Stack *sp)
{
    if (sp->top == sp->size - 1) return true;
    else return false;
}

bool isEmpty(struct Stack *sp)
{
    if (sp->top == -1) return true;
    else return false;
}

void push(struct Stack *sp, char data)
{
    if (isFull(sp))
    {
        cout<<"Stack Overflow!! Cannot push more expressions!!"<<endl;
    }
    else
    {
        sp->arr[sp->top + 1] = data;
    }
}

void pop(struct Stack *sp)
{
    if (isEmpty(sp))
    {
        cout<<"Stack Underflow!! No element present in expression!"<<endl;
    }
    else
    {
        char val = sp->arr[sp->top];
        sp->top -= 1;
    }
}

int paranthesisMatcher(struct Stack *sp, string exp)
{
    sp->arr = new char[50];
    sp->top = -1;
    sp->size = 100;
    for (int i=0; i<= exp.size(); i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp)) return 1;
    else return 0;
}

int main()
{
    struct Stack *sp = new Stack;
    // sp->top = -1;
    // sp->size = 100;
    // sp->arr = new char[sp->size];
    string exp = "((()))";
    if (paranthesisMatcher(sp, exp))
    {
        cout<<"Paranthesis are matched!!"<<endl;
    }
    else 
    {
        cout<<"Paranthesis are not matched!!"<<endl;
    }
    delete sp;
    return 0;
}