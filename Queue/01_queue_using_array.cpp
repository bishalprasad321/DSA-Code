#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int front, back, *arr;
};

bool isFull(struct Queue *q)
{
    if (q->back == q->size - 1)
        return true;
    else
        return false;
}

bool isEmpty(struct Queue *q)
{
    if (q->front == q->back)
        return true;
    else
        return false;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        cout<<"The Queue is Full!! "<<value<<" cannot be added to the queue."<<endl;
    }
    else
    {
        q->back++;
        q->arr[q->back] = value;
        cout<<value<<" added to the queue"<<endl;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main()
{
    struct Queue q;
    q.size = 50;
    q.front = q.back = -1;
    q.arr = new int[q.size];
    enqueue(&q, 23);
    enqueue(&q, 12);
    int d = dequeue(&q);
    cout<<d<<" removed from the queue!!"<<endl;
    return 0;
}