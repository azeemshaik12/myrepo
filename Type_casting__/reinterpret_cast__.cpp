#include<iostream>

#include<iostream>
/*
reinterpret_cast<type>(expression);
1.allows any pointer type to be converted into any other type
2.allows any intergral type to be converted into any pointer type and vice versa
3.can be used to convert char* to int* or one class * to unrelated other class *
4.the result of this cast can't be used safely for anything other than being cast back to it's original type
5.can't cast away the const, volatile ___ unaligned attributes
*/
class A{};
class B:private A{};
class C:private A{};
int main(){
    int a=100;
    int *ip=&a;
    char *cp=reinterpret_cast<char *>(ip);//point 1 pointer --pointer
    double *dp=reinterpret_cast<double *>(a);//pint 2 variable --pointer
    std::cout<<"a: "<<a<<"\n";
    std::cout<<"*ip: "<<*ip<<"\n";
    std::cout<<"*cp: "<<*cp<<"\n";
    std::cout<<"dp: "<<dp<<"\n";
    A *obj1;
    B *ob1=reinterpret_cast<B*>(obj1);
    C *ob2=reinterpret_cast<C*>(obj1);//point 3
    
    //point 5
    int var=100;
    const int* cptr=&var;
   // char *chp=reinterpret_cast<char *>(cptr); //error
    const char *cchp=reinterpret_cast<const char *>(cptr);//works
    volatile int* vptr=&var;
    
   // char *vcp=reinterpret_cast<char *>(vptr); //error
    volatile char *vchp=reinterpret_cast<volatile char *>(vptr);//works
    return 0;
}
