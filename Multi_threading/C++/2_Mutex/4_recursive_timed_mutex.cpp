/*
std::recursive_timed_mutex 

1.it is used when a function is recursive, this mutex will keep a count of no.of times function called that many times it 
will lock the critical section and same no.of times unlock the mutex 

2.member functions
  a.lock()
  b.try_lock()
  c.try_loc_for() :block for given time and then executes else part 
  d.try_lock_until() :block until given time and then executes else part 
  e.unlock()
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<chrono>
using namespace std::chrono_literals;
std::recursive_timed_mutex m1,m2,m3,m4;
int c1=0,c2=0,c3=0,c4=0;
void fun1(std::string id,int times){
    if(times<=0){
        return;
    }
    m1.lock();
    std::cout<<id<<" mutex locked, value: "<<++c1<<"\n";
    fun1(id,--times);
    m1.unlock();
    std::cout<<id<<" mutex unlocked\n";
}
void fun2(std::string id,int times){
    if(times<=0){
        return;
    }
    if(m2.try_lock()){
    std::cout<<id<<" try_locked, value: "<<++c2<<"\n";
    fun2(id,--times);
    m2.unlock();
    std::cout<<id<<" try_unlocked\n";
    }
    else{
      std::cout<<id<<"unable to lock\n";  
    }
    
}
void fun3(std::string id,int times){
    if(times<=0){
        return;
    }
    if(m3.try_lock_for(0.1ms)){
    std::cout<<id<<" try_lock_for_locked, value: "<<++c3<<"\n";
    fun3(id,--times);
    m3.unlock();
    std::cout<<id<<" try_lock_for_unlocked\n";
    }
    else{
      std::cout<<id<<" try_lock_for_unable to lock\n";  
    }
    
}
void fun4(std::string id,int times){
    if(times<=0){
        return;
    }
    if(m4.try_lock_until(std::chrono::high_resolution_clock::now()+0.1ms)){
    std::cout<<id<<" try_lock_until_locked, value: "<<++c4<<"\n";
    fun4(id,--times);
    m4.unlock();
    std::cout<<id<<" try_lock_until_unlocked\n";
    }
    else{
      std::cout<<id<<" try_lock_until_unable to lock\n";  
    }
    
}
int main(){
   std::jthread t1(fun1,"thread t1",3);
   std::jthread t2(fun1,"thread t2",3);
   std::jthread t3(fun2,"thread t3",3);
   std::jthread t4(fun2,"thread t4",3);
   std::jthread t5(fun3,"thread t5",3);
   std::jthread t6(fun3,"thread t6",3);
   std::jthread t7(fun4,"thread t7",3);
   std::jthread t8(fun4,"thread t8",3);
  return 0;  
}
