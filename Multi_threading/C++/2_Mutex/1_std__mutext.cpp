/*
std::mutex :mutual exclusion
1.race condition is a situation two or more threads / process tries to change a comman data at the same time
2.if we have a race condition then we have to protect it and the protected section is called as critical section/region.
3.to avoid this race condtion and to protect critical section we use mutex
4.we use lock(),unlock() on mutex to avoid race condition.
5.The try_lock() function in C++ is used with mutexes to attempt to acquire a lock without blocking. Unlike lock(), which will block
  the calling thread until it can acquire the lock,
*/
#include<iostream>
#include<thread>
#include<mutex>

#define counts 10000000
int x=0,mx=0,tx=0;
std::mutex mut;
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
     for(int i=0;i<counts;i++){
           if(mut.try_lock()){
           tx++;
           mut.unlock();
           }
     }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

 
     std::cout << "Time taken by tfun: " << duration.count() << " microseconds" << std::endl; 

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
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    std::cout<<"Normal  out put: "<<x<<"\n";
    std::cout<<"trylock out put: "<<tx<<"\n";
    std::cout<<"mutex   out put: "<<mx<<"\n";
    return 0;
}