/*
std::lock_guard

std::lock_guard<mutex type> variable_name(mutex object)
When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
When control leaves the scope in which the lock_guard object was created, 
the lock_guard is destructed and the mutex is released (unlocked).

https://youtu.be/cTJfG_BnQLU?si=L4L0JQrGpCzP6mvn
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>

std::mutex m1;
std::timed_mutex m2;
std::recursive_mutex m3;
std::recursive_timed_mutex m4;

int x=0;
void fun(std::string id,int times){
    
    for(int i=0;i<times;i++){
    std::lock_guard<std::mutex> l(m1);
    x++;
    std::cout<<id<<x<<"\n";
    }
    std::cout<<id<<"completed\n";
}
void fun2(std::string id,int times){
    if(times<=0) return;
    std::lock_guard<std::recursive_mutex> l(m3);
    x++;
    std::cout<<id<<x<<" time "<<times<<"\n";
    fun2(id,--times);
}

int main(){
   std::cout<<"size of mutex is: "<<sizeof(m1)<<" bytes\n";
   std::cout<<"size of timed_mutex is: "<<sizeof(m2)<<" bytes\n";
   std::cout<<"size of recursive_mutex is: "<<sizeof(m3)<<" bytes\n";
   std::cout<<"size of recursive_timed_mutex is: "<<sizeof(m4)<<" bytes\n";
   
   std::jthread t1(fun,"thread 1 ",10);
   std::jthread t2(fun2,"thread 2 ",5);
  return 0;  
}
