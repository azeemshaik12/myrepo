/*
join
1.once a thread is started we wait for thread to complete it's task, by calling  jion() function on thread object

2.double join() (calling join 2 times on same thread ) will lead program termination

3.we solve above problem by using joinable() function 


detach
1.this is used to detach newly crated thread from parent thread (parent thread won't wait for child thread to complete it's task unlike join())

2.always check before detaching a thread that is joinable(),otherwise we may end up double detach which will result program termination.

3.if we have detached thread and main function returning then detached thread execution is suspended.

* either join() or detach() should be called on thread object, otherwise during thread object destruction it will terminate the program. because destructor checks if thread is still joinable? if yes then it will terminate the program.

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
    
    std::thread t1(fun);
    std::thread t2(fun1);
    if(t1.joinable()){
        std::cout<<"first joinable\n";
        t1.join();
    }
    
    if(t1.joinable()){
        std::cout<<"second joinable\n";
        t1.join();
    }
    if(t2.joinable()){
        std::cout<<"first detach\n";
        t2.detach();
    }
    if(t2.joinable()){
        std::cout<<"second detach\n";
        t2.detach();
    }
    
    return 0;
}

