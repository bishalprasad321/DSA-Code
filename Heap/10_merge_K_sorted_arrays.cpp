#include<bits/stdc++.h>
using namespace std;

/*
    You have been given ‘K’ different arrays/lists, which are sorted 
    individually (in ascending order). You need to merge all the given 
    arrays/list such that the output array/list should be sorted in ascending order.

*/
class node
{
    public: 
        int data;
        int row;
        int col;
    
    node (int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    // step 1 : insert the first element of k arrays in to min heap
    for (int i = 0; i < k; i++)
    {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
    while (minHeap.size() > 0)
    {
        node *tmp = minHeap.top();
        
        ans.push_back(tmp->data);
        minHeap.pop();
        
        int row = tmp->row;
        int col = tmp->col;
        
        if (col + 1 < kArrays[row].size())
        {
            node *next = new node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>> arrays{{1, 5, 9}, {45, 90}, {2, 6, 78, 100, 234}, {0}};

    cout << "Merged array is ----- "<<endl;

    vector<int> ans = mergeKSortedArrays(arrays, 4);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    
    return 0;
}