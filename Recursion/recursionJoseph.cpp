#include<bits/stdc++.h>
using namespace std;

int josephusGame(int n, int k)
{
    if ( n == 1 ) 
    {
        return 0;
    }
    else
    {
        return ((josephusGame(n-1, k) + k) % n);
    }
}

int main()
{
    cout<<josephusGame(5, 3);
    return 0;
}