/*
std::lock(mutex1,mutex2,..........); is a function in C++ that is used to lock multiple 
mutexes simultaneously while avoiding deadlocks.
usesage: to avoid dead lock


what is dead lock:


the deadlock happens when two threads are waiting for a mutex owned by
the other. One of the most common ways of avoiding a deadlock is to 
always lock the two mutexes in the same order.
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#define counts 1000
std::mutex m1,m2;
int x=0;
void deadlock1(std::string id){
    for(int i=0;i<counts;i++){
        m1.lock();
        std::cout<<"m1 locked by "<<id<<"\n";
        m2.lock();
        std::cout<<"m2 locked by "<<id<<"\n";
        x++;
        std::cout<<"x value is "<<x<<"\n";
        m2.unlock();
        m1.unlock();
        }
}

void deadlock2(std::string id){
    for(int i=0;i<counts;i++){
        m2.lock();
        std::cout<<"m2 locked by "<<id<<"\n";
        m1.lock();
        std::cout<<"m1 locked by "<<id<<"\n";
        x++;
        std::cout<<"x value is "<<x<<"\n";
        m1.unlock();
        m2.unlock();
        }
}
void lock_free1(std::string id){
   for(int i=0;i<counts;i++){
        std::lock(m1,m2);
        x++;
        std::cout<<id<<" x value is "<<x<<"\n";
        m1.unlock();
        m2.unlock();
        } 
}
void lock_free2(std::string id){
   for(int i=0;i<counts;i++){
        std::lock(m2,m1);
        x++;
        std::cout<<id<<" x value is "<<x<<"\n";
        m2.unlock();
        m1.unlock();
        } 
}

int main(){
   std::jthread t1(deadlock1,"thread 1"); //dead lock
   std::jthread t2(deadlock2,"thread 2"); //dead lock
    //std::jthread t3(lock_free1,"thread 1");
    //std::jthread t4(lock_free2,"thread 2");
   return 0;
}

