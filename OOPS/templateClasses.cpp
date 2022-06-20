#include<bits/stdc++.h>
using namespace std;

// Template are use to make a class generic so as it may not be necessary for a class to have only one data type. It can be of diferent data types.

template<class T>
class operations
{
    private: 
        T a;
        T b;
    public:
        operations(T a, T b);
        T add();
        T subtract();
};

template<class T>
operations<T>::operations(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T operations<T>::add()
{
    T c = a + b;
    return c;
}

template<class T>
T operations<T>::subtract()
{
   T c = a - b;
   return c; 
}

int main()
{
    operations<int> ops1(15,12);
    cout<<ops1.add()<<endl;
    operations<float> ops2(20.9, 16.8);
    cout<<ops2.subtract();
    return 0;
}