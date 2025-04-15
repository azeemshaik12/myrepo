/*
https://youtu.be/x0sHzDyETUc?si=ReFjCs4PKnKVEiSD
1.std::timed_mutex is blocked till the given time and after that time 
executes other blocks if any avilable (else condition).
on success return true failure return false 

2.member functions
  a.lock()
  b.try_lock()
  c.try_lock_for()
  d.try_lock_until()
  e.unlock()

*/
#include<iostream>
#include<thread>
#include<mutex>

#define counts 10000000

using namespace std::chrono_literals;
int x=0,mx=0,tx=0,mxt=0;
std::timed_mutex mut,mm,mmx;
void fun(){
    auto start = std::chrono::high_resolution_clock::now();
     for(int i=0;i<counts;i++){
       x++;
     }
     auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

 
     std::cout << "Time taken by  fun: " << duration.count() << " microseconds" << std::endl; 

}
void Mfun(){
    auto start = std::chrono::high_resolution_clock::now();
     for(int i=0;i<counts;i++){
           mut.lock();
           mx++;
           mut.unlock();
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

 
     std::cout << "Time taken by Mfun: " << duration.count() << " microseconds" << std::endl; 

}
void tfun(){
    auto start = std::chrono::high_resolution_clock::now();
    static int x=0;
     for(int i=0;i<counts;i++){
           if(mm.try_lock_for(1ms)){
           tx++;
           mm.unlock();
           }
           else{
               x++;
           }
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

      
     std::cout << "Time taken by tfun: " << duration.count() << " microseconds"; 
     std::cout<<"missed mutex "<<x<<"\n";
}
void tfun2(){
    auto start = std::chrono::high_resolution_clock::now();
    static int x=0;
     for(int i=0;i<counts;i++){
           if(mmx.try_lock_until(std::chrono::high_resolution_clock::now()+1ms)){
           mxt++;
           mmx.unlock();
           }
           else{
               x++;
           }
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

      
     std::cout << "Time taken by tfu2: " << duration.count() << " microseconds"; 
     std::cout<<"missed mutex "<<x<<"\n";
}
int main(){
    std::thread t1(fun);
    std::thread t2(fun);
    std::thread t3(Mfun);
    std::thread t4(Mfun);
    std::thread t5(Mfun);
    std::thread t6(tfun);
    std::thread t7(tfun);
    std::thread t8(tfun);
    std::thread t9(tfun2);
    std::thread t10(tfun2);
    std::thread t11(tfun2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    std::cout<<"Normal  out put: "<<x<<"\n";
    std::cout<<"tl_for  out put: "<<tx<<"\n";
    std::cout<<"tl_unt  out put: "<<mxt<<"\n";
    std::cout<<"mutex   out put: "<<mx<<"\n";
    return 0;
}