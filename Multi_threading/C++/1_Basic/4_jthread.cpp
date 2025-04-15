/*
1.jthread class is same like thread but we need not to write join() in parent thread  to wait for child thread to 
complete it's exectuion destructor of jthread class will have join() function internally.

2.so we need not to write join(),by default parent thread will wait untill all child threads compltes their exection.

3.if you want to detach any thread from parent you need to write detach() on jthread object 

*/
#include <iostream>
#include <thread>
#include <chrono>
void fun(){
    std::cout<<"fun thread started\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"fun thread ended\n";
}
void fun1(){
    std::cout<<"fun1 thread started\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"fun2 thread ended\n";
}
int main(){
    
    std::jthread t1(fun);
    std::jthread t2(fun1);
    if(t2.joinable()){
        std::cout<<"detach\n";
        t2.detach();    
    }
    return 0;
}
