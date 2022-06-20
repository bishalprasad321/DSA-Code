#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)   // time complexity -> O(2^n)
{
    if (n<=1) return n;
    return fibonacci(n-2) + fibonacci(n-1);
}

int fibonacci_pro(int n)  // time complexity -> O(n) (Using memorization technique with the help of an array)
{
    int F[n];

    for (int i=0; i<n; i++)
    {
        F[i] = -1;
    }

    if (n<=1) 
    {
        F[n] = n;
        return n;
    }

    else
    {
        if (F[n-2] == -1) 
        {
            F[n-2] = fibonacci_pro(n-2);
        }

        if (F[n-1] == -1)
        {
            F[n-1] = fibonacci_pro(n-1);
        }

        return F[n-2] + F[n-1];
    }
}

int main()
{
    cout<<fibonacci(7)<<endl;
    cout<<fibonacci_pro(7);
    return 0;
}