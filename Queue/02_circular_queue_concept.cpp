#include<bits/stdc++.h>
using namespace std;

struct CircularQueue 
{
    int size, front, back, *arr;
};

bool isEmpty(struct CircularQueue *cq)
{
    if (cq->front == cq->back) return true;
    else return false;
}

bool isFull(struct CircularQueue *cq)
{
    if (cq->front == cq->size - 1) return true;
    else return false;
}

void enqueue(struct CircularQueue *cq, int value)
{
    if (isFull(cq))
    {
        cout<<"Queue is full!"<<" cannot add "<<value<<" to queue"<<endl;
    }
    else
    {
        cq->back = (cq->back + 1)%cq->size;
        cq->arr[cq->back] = value;
        cout<<value<<" has been added to the queue."<<endl;
    }
}

int dequeue(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        cout<<"Queue is empty, nothing to dequeue!!"<<endl;
        return -1;
    }
    else
    {
        cq->front = (cq->front + 1)%cq->size;
        int res = cq->arr[cq->front];
        return res;
    }
}

int main()
{
    struct CircularQueue cq;
    cq.size = 50;
    cq.front = cq.back = 0;
    cq.arr = new int[cq.size];

    enqueue(&cq, 20);
    enqueue(&cq, 81);
    enqueue(&cq, 17);

    cout<<"Dequeuing "<<dequeue(&cq)<<" from the queue!!"<<endl;
    cout<<"Dequeuing "<<dequeue(&cq)<<" from the queue!!"<<endl;

    return 0;
}