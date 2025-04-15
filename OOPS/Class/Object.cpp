//An Object is an instance of a Class. 
//When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
#include <iostream>
using namespace std;

class person 
{
    char name[20];
    int id;

public:
    person()
    {
        cout<<"default constructor";
    }
    ~person() // Destructor called
    {
        cout<<"Destructor called\n";
    }
};

int main()
{

    person p1; // p1 is a object
    return 0;
}

