/*
std::recursive_mutex 

1.it is used when a function is recursive, this mutex will keep a count of no.of times function called that many times it 
will lock the critical section and same no.of times unlock the mutex 

2.member functions
  a.lock()
  b.try_lock()
  c.unlock()
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>
std::recursive_mutex m1,m2;
int c1=0,c2=0;
void fun1(std::string id,int times){
    if(times<=0){
        return;
    }
    m1.lock();
    std::cout<<id<<" locked, value: "<<++c1<<"\n";
    fun1(id,--times);
    m1.unlock();
    std::cout<<id<<" unlocked\n";
}
void fun2(std::string id,int times){
    if(times<=0){
        return;
    }
    if(m2.try_lock()){
    std::cout<<id<<" locked, value: "<<++c2<<"\n";
    fun2(id,--times);
    m2.unlock();
    std::cout<<id<<"unlocked\n";
    }
    else{
      std::cout<<id<<"unable to lock\n";  
    }
    
}
int main(){
   std::jthread t1(fun1,"thread t1",3);
   std::jthread t2(fun1,"thread t2",3);
   std::jthread t3(fun2,"thread t3",3);
   std::jthread t4(fun2,"thread t4",3);
  return 0;  
}

