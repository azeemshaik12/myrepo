/*
std::notify_all_at_thread_exit
void notify_all_at_thread_exit( std::condition_variable& cond, std::unique_lock<std::mutex> lk );

*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
int gv=0;
bool status=false;
std::mutex mtx;
std::condition_variable cv;
void function1(){ //need to do function1's job  first
    std::cout<<"function1 invoked\n";
    std::unique_lock<std::mutex> lk(mtx);
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 1 "<<gv<<"\n";
    // notify the thread function2 after job done by making waiting condtion true
    status =true;  //if commented this t2 will be wait forevr
    //cv.notify_all(); //all threads will work fine without blocking if we use  cv.notify_all();
    //cv.notify_one(); //if we use this we need to add  cv.notify_one(); in every thread  [point 1]
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::notify_all_at_thread_exit(cv, std::move(lk));
}
void function2(){ //function2 will wait untill function1 compltes it's job
    std::cout<<"function2 invoked\n";
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk,[]{return status;}); //this will take only unique lock
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 2 "<<gv<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //cv.notify_one();  //[point 1]
}
void function3(){ //function2 will wait untill function1 compltes it's job
    std::cout<<"function3 invoked\n";
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk,[]{return status;}); //this will take only unique lock
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 3 "<<gv<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void function4(){ //function2 will wait untill function1 compltes it's job
    std::cout<<"function4 invoked\n";
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk,[]{return status;}); //this will take only unique lock
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 4 "<<gv<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //cv.notify_one();  //[point 1]
}
int main()
{
   std::jthread t2(function2);
   std::jthread t3(function3);
   std::jthread t4(function4);
   std::jthread t1(function1);
    return 0;
}
