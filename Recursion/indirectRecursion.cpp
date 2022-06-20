#include <bits/stdc++.h>
using namespace std;
// When function calls itself by calling indirectly via another function, is called indirect recursion
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        funA(n / 2);
    }
}

int main()
{
    funA(20);
    return 0;
}