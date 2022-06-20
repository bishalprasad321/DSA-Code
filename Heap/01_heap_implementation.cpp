#include <bits/stdc++.h>
using namespace std;

/*
    What is Heap?
    -> It is a CBT (Complete Binary Tree), which follows a particular order of maxHeap
    or minHeap.

    CBT (Complete Binary Tree) -> Where all the levels are filled except the lowest one and the
    and all the nodes are lean towards the left.

    maxHeap -> where the parent->data is maximum of their child nodes.
    minHeap -> where the parent->data is minimum of their child nodes.

    example --------->
        50
       /  \
     40    30
    /  \
   20  10

   Implementation ----> (Using array)
   (1 based indexing)
   | X | 50 | 40 | 30 | 20 | 10 |  --> MaxHeap

   root = 50 (index = 1)
   left nodes = (index = 2*i, where i is the index of its parent node)
   Right nodes = (index = 2*i + 1)

   parent = (index = i/2)

*/

class Heap
{
public:
    int arr[100];
    int size;

    // constructor
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // modification functions
    void insert(int value);

    void deleteFromHeap();

    // output function
    void printHeap();
};

void Heap ::insert(int value)
{
    size = size + 1;
    int index = size;

    arr[index] = value;

    while (index > 1)
    {
        int parent = index / 2;

        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
            return;
    }
}

void Heap :: deleteFromHeap()
{
    if (size == 0)
    {
        cout << "There is nothing to delete" << endl;
        return ;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i < size)
    {
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;

        if (leftIndex < size and arr[i] < arr[leftIndex])
        {
            swap(arr[leftIndex], arr[i]);
            
            i = leftIndex;
        }

        else if(rightIndex < size and arr[i] < arr[rightIndex])
        {
            swap(arr[rightIndex], arr[i]);

            i = rightIndex;
        }

        else
            return ;

    }
}

void Heap :: printHeap()
{
    for (int i = 1; i <= size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Heap h;
    h.insert(30);
    h.insert(10);
    h.insert(50);
    h.insert(40);
    h.insert(20);

    cout << "After insertion of elements inside the heap" <<endl;

    h.printHeap();

    h.deleteFromHeap();

    cout << "After deletion of element from the heap" << endl;

    h.printHeap();

    return 0;
}