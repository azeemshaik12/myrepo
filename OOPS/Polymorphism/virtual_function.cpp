#include <iostream>
// without virtual 
class base{
    public:
    void fun(){
      std::cout<<"base class\n";
    }
};
class derived1:public base{
    public:
    void fun(){
      std::cout<<"derived1 class\n";
    }
};
class derived2:public base{
    public:
    void fun(){
      std::cout<<"derived2 class\n";
    }
};

//with virtual
class base2{
    public:
    virtual void fun(){  //virtual keyword cretes a vptr(virtual pointer)
      std::cout<<"base class\n";
    }
};
class d1:public base2{
    public:
    void fun(){
      std::cout<<"derived1 class\n";
    }
};
class d2:public base2{
    public:
     void fun(){
      std::cout<<"derived2 class\n";
    }
};

int main()
{
    base *ptr1=new derived1();
    base *ptr2=new derived2();
    
    base2 *p1=new d1();
    base2 *p2=new d2();
    
    ptr1->fun();
    ptr2->fun();
    
    p1->fun();
    p2->fun();
    
    
    std::cout<<"size of base "<<sizeof(base)<<"\n";
    std::cout<<"size of base "<<sizeof(base2)<<"\n";
    return 0;
}
