/*
shred mutex have two types of locking mechanisms

1.Exclusive Lock: When a section is locked exclusively, only one thread can access it. No other thread can acquire either an exclusive or shared lock during this time.

2.Shared Lock: When a section is locked using a shared lock, multiple threads can access it concurrently. This is ideal for read-only sections, as it allows multiple readers without blocking each other.

member functions

for exclusive locking
----------------------
void lock()
void unlock()
bool try_lock()

for shared locking
----------------------
void lock_shared()
void unlock_shared()
bool try_lock_shared()



*/
#include <iostream>
#include <thread>
#include <shared_mutex>
int val=0;
std::shared_mutex mtx;
void reader1(){
    std::cout<<"in reader1 before lock\n";
    mtx.lock_shared();
    std::cout<<"reader1 got access\n";
    std::cout<<val<<"\n";
    mtx.unlock_shared();
}
void reader2(){
    std::cout<<"in reader2 before lock\n";
    mtx.lock_shared();
    std::cout<<"reader2 got access\n";
    std::cout<<val<<"\n";
    mtx.unlock_shared();
}
void writer(){
    mtx.lock();
     std::cout<<"writer got access\n";
     //std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    for(int i=0;i<1000000;i++){ val++;}
    mtx.unlock();
}
int main(){
  std::jthread t1(writer);
  std::jthread t2(reader1);
  std::jthread t3(reader2);
  return 0;  
}
