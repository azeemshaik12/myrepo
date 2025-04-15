#include<iostream>
/*
dynamic_cast<type> (expresiion);
1.involvs run time type check
2.base class should be polymorphic at least have one virtual function
3.on succes returns a new type
4.on failure 
if new type is pointer returns nullptr 
if new type is refernce returns bad_cast exception

*/

class A{
public:
virtual void fun() {

}
};

class B:public A{
public:
virtual void fun() {

}
};

class C:public A{
public:
virtual void fun() {

}
};

int main(){
    A *p1=new B;
    A *p2=new C;
    
    B *ptr3=dynamic_cast<B *>(p1);
    B *ptr4=dynamic_cast<B *>(p2);
    std::cout<<"succes :"<<ptr3<<" , failure :"<<ptr4<<"\n";
    
    C *ptr5=dynamic_cast<C *>(p1);
    C *ptr6=dynamic_cast<C *>(p2);
    std::cout<<"succes :"<<ptr6<<" , failure :"<<ptr5<<"\n";
    
    return 0;
}

