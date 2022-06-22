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

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < size and arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < size and arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }

}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array after heapify call : ";
    
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    
    cout << endl;
    
    return 0;
}