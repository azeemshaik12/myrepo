#include <iostream>
//without virtual 
class base{
    public:
    base(){
        std::cout<<"base ctr\n";
    }
    ~base(){
        std::cout<<"base dtr\n";
    }
};

class derived:public base{
    public:
    derived(){
        std::cout<<"derived ctr\n";
    }
    ~derived(){
        std::cout<<"derived dtr\n";
    }
};
//with virtual
class basev{
    public:
    basev(){
        std::cout<<"basev ctr\n";
    }
    virtual ~basev(){
        std::cout<<"basev dtr\n";
    }
};

class derivedv:public basev{
    public:
    derivedv(){
        std::cout<<"derivedv ctr\n";
    }
    ~derivedv(){
        std::cout<<"derivedv dtr\n";
    }
};
int main()
{
    base *ptr1=new derived();
    delete ptr1;
    std::cout<<"\n";
    basev *ptr2=new derivedv();
    delete ptr2; 
    
    return 0;
}
