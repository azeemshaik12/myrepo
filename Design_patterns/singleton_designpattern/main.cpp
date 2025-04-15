#include<iostream>
#include<thread>
#include<memory>
#include "singleton.h"

void fun(){
singleton *obj=singleton::getobject();
}
int main(){
     std::shared_ptr<singleton> obj(singleton::getobject());
     singleton *obj2=singleton::getobject();
     std::cout<<obj->get_var()<<"\n";
     obj->set_var(120);
     std::cout<<obj->get_var()<<"\n";
     std::thread t1(fun);
     std::thread t2(fun);
     //singleton *obj2=std::move(obj2); //gives error 
     t1.join();
     t2.join();
   return 0;
}
