/*
std::condition_variable_any var_name;
 
 member functions:
 
 void notify_one()
 void notify_all()
 
 template< class Lock >
  void wait( Lock& lock );
 
 template< class Lock, class Predicate >
   void wait( Lock& lock, Predicate pred );
 template< class Lock, class Predicate >
   bool wait( Lock& lock, std::stop_token stoken, Predicate pred );
 
 template< class Lock, class Rep, class Period >
  std::cv_status wait_for( Lock& lock,const std::chrono::duration<Rep, Period>& rel_time );

template< class Lock, class Rep, class Period, class Predicate >
 bool wait_for( Lock& lock, const std::chrono::duration<Rep, Period>& rel_time,Predicate pred );

 template< class Lock, class Rep, class Period, class Predicate >
  bool wait_for( Lock& lock, std::stop_token stoken,const std::chrono::duration<Rep, Period>& rel_time,Predicate pred );

template< class Lock, class Clock, class Duration >
  std::cv_status wait_until( Lock& lock,const std::chrono::time_point<Clock, Duration>& abs_time );

template< class Lock, class Clock, class Duration, class Predicate >
  bool wait_until( Lock& lock,const std::chrono::time_point<Clock, Duration>& abs_time,Predicate pred );

template< class Lock, class Clock, class Duration, class Predicate >
  bool wait_until( Lock& lock, std::stop_token stoken,const std::chrono::time_point<Clock, Duration>& abs_time,Predicate pred );

*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
int gv=0;
bool status=false;
std::shared_mutex  mtx;
std::condition_variable_any cv;
void function1(){ //need to do function1's job  first
    std::cout<<"function1 invoked\n";
    std::lock_guard<std::shared_mutex> lk(mtx); 
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 1 "<<gv<<"\n";
    // notify the thread function2 after job done by making waiting condtion true
    status =true;  //if commented this t2 will be wait forevr
    cv.notify_all(); //all threads will work fine without blocking if we use  cv.notify_all();
    //cv.notify_one(); //if we use this we need to add  cv.notify_one(); in every thread  [point 1]
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void function2(){ //function2 will wait untill function1 compltes it's job
    std::cout<<"function2 invoked\n";
    std::unique_lock<std::shared_mutex> lk(mtx);
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
    std::shared_lock<std::shared_mutex> lk(mtx);
    cv.wait(lk,[]{return status;}); //this will take only unique lock
    for(int i=0;i<10000000;i++){
        gv++;
    }
    std::cout<<"done the job by function 3 "<<gv<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void function4(){ //function2 will wait untill function1 compltes it's job
    std::cout<<"function4 invoked\n";
    std::shared_lock<std::shared_mutex> lk(mtx);
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
