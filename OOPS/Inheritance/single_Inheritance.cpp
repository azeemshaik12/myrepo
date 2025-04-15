// Single Inheritance

#include<iostream>
using namespace std;

class manager
{
    public:
    manager()
    {
        cout<<"I'm Manager of Base class\n";
    }
    
};

class employee: public manager
{
    public:
    employee()
    {
        cout<<"I'm Employee of Derived class\n";
    }
    
};

int main()
{
   
   employee e1;
}
