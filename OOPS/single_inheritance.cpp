#include<bits/stdc++.h>
using namespace std;

class baseClass
{
    // Default --> Private
    private:
        int parameter1; // This parameterwill not be inherited by derived classes
        float parameter2; // This parameter will not be inherited by derived classes
    public:
        // These functions will be accessible by all derived classes
        void function1(void); 
        void function2(void);
};

void baseClass::function1(void) // defining function1 using scope resolution operator (i.e ::)
{
    parameter1 = 7;
    parameter2 = 3.9;
    cout<<"Hi!, This is from function 1"<<endl;
    cout<<"I can access the private variables of baseClass, here they are : "<<parameter1<<parameter2<<endl;
}

void baseClass::function2(void) // defining function2 using scope resolution operator
{
    parameter1 = 10;
    parameter2 = 6.8;
    cout<<"Hi! This is from function 2"<<endl;
    cout<<"I can also access the private variables of baseClass, here they are after alteration : "<<parameter1<<parameter2<<endl;

// Deriving a child class from the baseClass in public mode using (--> :)
class childClass : public baseClass
{
    // The private definition of baseClass will not be inherited whether it is derived in public mode, protected mode or neither in public mode.
    public:
        void function3(void);
};

void childClass::function3(void)
{
    cout<<"Hi!, this is from function 3"<<endl;
    cout<<"I cannot access the private declarations of baseClass"<<endl;
}


int main()
{
   
    return 0;
}