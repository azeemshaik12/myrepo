#include<iostream>
/*
const_cast<type>(expression);

1.use to cast away the constness of a variable
2.passing const data to a function which doesn't receive a const data
3.changing non-const class members inside a const member function
4.undefined behaviour to modify a value initially decleared as a const 
5.can't cast to a type different from original object

*/
class azeem{
    int x=33;
    public:
    //point 4
    void fun(int i)const{
        //x=i; error 
        const_cast<azeem *>(this)->x=i; //works
        std::cout<<x<<"\n";
    }
    
};
int fun(int *ptr){
    *ptr=100;
    return *ptr;
}
int main(){
    const int val=5;
    //points 1,2,4
    std::cout<<fun(const_cast<int*>(&val))<<"\n";//100 
    std::cout<<val<<"\n";//5 
    azeem a;
    a.fun(100);
    
    //point 4
    const int a1=10;
    const int *p1=&a1;
    int *p2=const_cast<int *>(p1);
    *p2=100;
     std::cout<<"*p2: "<<*p2<<"\n";//100
     std::cout<<"*p1: "<<*p1<<"\n";//100
     std::cout<<"a1 : "<<a1<<"\n";//10
     
     //point 5
     
     int x=10;
     char *cch=(char*)&x; //c style works
     char *ch=const_cast<char *>(&x); //gives error
     /*
     we are trying to convert int* char * so getting error 
     */
    return 0;
}

