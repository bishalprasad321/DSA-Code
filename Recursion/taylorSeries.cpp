#include<bits/stdc++.h>
using namespace std;

// Taylor series of e^(x)
// This method uses the method of multiplication as a O(n^2)

double taylorSeries(int x, int n)
{
    static double x_var = 1, fact_var = 1;
    double result;
    
    if (n == 0) 
        return 1;
    
    else
    {
        result = taylorSeries(x, n-1);
        x_var *= x;
        fact_var *= n;   
        return result + x_var/fact_var;
    }
}

// Horner's rule for taylor series
// This method reduces the steps of multiplication to O(n)

double taylorSeries_using_horner(int x, int n)
{
    static double result;
    if (n == 0)
        return result;
    result = 1 + x*result/n;
    return taylorSeries_using_horner(x, n-1);
}

int main()
{
    cout<<taylorSeries(2, 10)<<endl;
    cout<<taylorSeries_using_horner(2,10);
    return 0;
}