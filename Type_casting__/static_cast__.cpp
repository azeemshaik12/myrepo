#include<iostream>


/*
1.this will work for implicit conversions ,it is compile time cast
2.conversion from void* to other or converting others to void*
3.conversion involiving inheritance :is a (private)

static_cast<type>(expression);

*/
  class A{
        
    };
    class B:private A{
        
    }
int main(){
     
     //c-style cast
     char c;
    int *p1=(int *)(&c);//ok
    *p1=3;//pass at compile time but fail at run time gives wrong answers
    //static cast
    int *p2=static_cast<int *>(&c);  //gives compile time error


    //int to void *
    int i=10;
    void *v=static_cast<void *>(&i);

    //void * to int *

    int *p=static_cast<int *>(v);

    A *ptr=(A*)(&obj); //c stype works
    A *ptr2=static_cast<A*>(&obj); //private,protected  inheritance won't work only for public

}