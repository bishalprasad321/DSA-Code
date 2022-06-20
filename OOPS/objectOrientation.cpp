#include<bits/stdc++.h>
using namespace std;

class rectangle
{
    private:
        int length, breadth;
    
    public:
        rectangle(int l, int b);

        int calculateArea();
        int calculatePerimeter();
        void updateDimensions(int l1, int b1)
        {
            length = l1;
            breadth = b1;
        };
        string getDimensions();
};

rectangle::rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int rectangle::calculateArea()
{
    return length*breadth;
}

int rectangle::calculatePerimeter()
{
    return 2*(length + breadth);
}

string rectangle::getDimensions()
{
    return "Length = " + to_string(length) + ", breadth = " + to_string(breadth);
}

int main()
{
    rectangle rect(10,5);
    cout<<rect.calculateArea()<<endl;
    cout<<rect.calculatePerimeter()<<endl;
    cout<<rect.getDimensions()<<endl;
    rect.updateDimensions(12, 9);
    cout<<rect.getDimensions()<<endl;
    return 0;
}