#include<bits/stdc++.h>
using namespace std;

/* It is a problem of moving discs from one tower to another and put them in the same manner as it was in the first one, but the rules are :
1. You can only move a disc at a time 
2. You cannot place the bigger discs on the top of the smaller one while rearranging them.
*/

void tower_of_hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        tower_of_hanoi(n-1, a, c, b);
        cout<<"("<<a<<" "<<c<<") "; // move from tower A to tower C
        tower_of_hanoi(n-1, b, a, c);
    }
}

int main()
{
    tower_of_hanoi(5, 1, 2, 3);
    return 0;
}