#include <bits/stdc++.h>
using namespace std;



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

void heapifyMax(int arr[], int size, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left <= size and arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size and arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifyMax(arr, size, largest);
    }

}

void sortMaxHeap(int arr[], int size)
{
    int n = size;

    while (n > 1)
    {
        swap(arr[n], arr[1]);
        n--;

        // call heapify to correct the position of the root node
        heapifyMax(arr, n, 1);
    }
}

int main()
{
    //  Heap Creation
    int arrMax[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    for (int i = n/2; i > 0; i--)
    {
        heapifyMax(arrMax, n, i);
    }

    // Heap sorting
    sortMaxHeap(arrMax, n);

    // printing the result
    cout << "Printing the sorted array : ";

    for (int i = 1; i <= n; i++)
        cout << arrMax[i] << " ";

    cout << endl;


    return 0;
}