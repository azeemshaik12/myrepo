/*
std::try_lock(mutex1,mutex2,..........);

std::try_lock()  tries to lock all the lockable objects passed int it one bye one in given orderr

on suuccess it will return -1 otherwise 
it will send index of mutex which unable to lock(first mutex index is 0)
ex:
std::try_lock(m1,m2,m3,m4,m5);
      index    0  1  2  3  4

if it fails to lock any of the mutex then it will unlock all the mutexes which locked before

if a call to try_lock results in exception,unlock will be called for any locke dobjects before rethrowing

https://youtu.be/r-PDHNWYdes?si=o4ATaQDf4aMYsAZQ
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#define counts 100000
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
void try_lock_1(std::string id){
    for(int i=0;i<counts;i++){
        if(std::try_lock(m1,m2)==-1){
        x++;
        std::cout<<"x value is "<<x<<" "+id<<" locked both mutexes \n";
        m1.unlock();
        m2.unlock();
        }else{
            std::cout<<id<<" unable to lock mutexes\n";
        }
        }
}
void try_lock_2(std::string id){
    for(int i=0;i<counts;i++){
        if(std::try_lock(m1,m2)==-1){
        x++;
         std::cout<<"x value is "<<x<<" "+id<<" locked both mutexes \n";
        m1.unlock();
        m2.unlock();
        }else{
            std::cout<<id<<" unable to lock mutexes\n";
        }
        }
}

int main(){
   //std::jthread t1(deadlock1,"thread 1"); //dead lock
   //std::jthread t2(deadlock2,"thread 2"); //dead lock
    std::jthread t3(try_lock_1,"thread 1");
    std::jthread t4(try_lock_2,"thread 2");
    
   return 0;
}

