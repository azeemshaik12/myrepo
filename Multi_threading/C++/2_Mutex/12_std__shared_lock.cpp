/*
1. Deferred Locking: You can create a std::unique_lock without immediately
   locking the mutex.
   This is useful when you need to perform some operations before locking.

   std::shared_mutex mtx;
   std::shared_lock<std::shared_mutex> lck(mtx, std::defer_lock);
   // Perform some operations
   lck.lock(); // Lock the mutex later here lock calls lock_shared() 
   of shared mutex
   
   multiple mutexes locking

   std::shared_mutex mtx1, mtx2;
   std::unique_lock<std::shared_mutex> lck1(mtx1, std::defer_lock);
   std::unique_lock<std::shared_mutex> lck2(mtx2, std::defer_lock);
   std::lock(lck1, lck2);  //std::lock does exclusive locking

   std::shared_mutex mtx1, mtx2;
   std::unique_lock<std::shared_mutex> lck1(mtx1, std::defer_lock);
   std::unique_lock<std::shared_mutex> lck2(mtx2, std::defer_lock);
   std::lock(lck1, lck2);  
   
   //conveting to shared locking
   std::shared_lock<std::shared_mutex> shared_lck1(std::move(lck1));
   std::shared_lock<std::shared_mutex> shared_lck2(std::move(lck2));

2.Timed Locking: You can attempt to lock the mutex for a specified duration or until a specific time point.
   std::shared_mutex mtx;
   std::shared_lock<std::shared_mutex > lck(mtx, std::defer_lock);
   if (lck.try_lock_for(std::chrono::seconds(1))) { //try_lock_for calls try_lock_shared_for
    // Critical section
   } else {
    // Handle timeout
   }

3.Condition Variables:  This is a more flexible 
   condition variable     that can work with any lock type 
   that  meets    the BasicLockable requirements, such as std::shared_lock. This allows 
   forshared (read-only) access in multi-threaded environments.
   std::condition_variable_any cv;
   std::shared_lock<std::shared_mutex> lock(mtx);
   cv.wait(lock, []{ return ready; });

4.Transfer of Lock Ownership: You can transfer the ownership of a lock to another  std::shared_lock
   std::shared_lock<std::shared_mutex> lck1(mtx);
   std::shared_lock<std::shared_mutex> lck2(std::move(lck1)); // Transfer ownership

5.Swapping two unique_locks
   std::shared_mutex mtx1, mtx2;
   std::shared_lock<std::mutex> lock1(mtx1);
   std::shared_lock<std::mutex> lock2(mtx2);

   // Swap the locks
   std::swap(lock1, lock2);//non member function  
   lock1.swap(lock2);//member function 

Release function   
  std::shared_mutex mtx,mtx2;
  std::shared_lock<std::shared_mutex> lck(mtx);

  // Release the lock
  std::shared_mutex* released_mtx = lck.release();

  // Now, lck no longer manages the mutex, and you must manually unlock it
  released_mtx->unlock();
  
  // Now, lck no longer manages any mutex
  // Assign a new mutex to lck
  lck = std::shared_lock<std::shared_mutex>(mtx2);


Mutext()  function  
  std::shared_mutex mtx;
  std::shared_lock<std::shared_mutex> lck(mtx);

  // Get the pointer to the managed mutex
  std::shared_mutex* mtx_ptr = lck.mutex();

  if (mtx_ptr) {
    // mtx_ptr points to mtx
    std::cout << "Mutex is managed by lck." << std::endl;
  } else {
    std::cout << "No mutex is managed by lck." << std::endl;
  }
  In this example, mtx_ptr will point to mtx because lck is managing it. If lck was not managing any mutex, mtx_ptr would be nullptr


owns_lock()  function --return type bool
  std::shared_mutex mtx;
  std::shared_lock<std::shared_mutex> lck(mtx);

  if (lck.owns_lock()) {
    std::cout << "The lock is owned by lck." << std::endl;
  } else {
    std::cout << "The lock is not owned by lck." << std::endl;
  }
  In this example, owns_lock will return true because lck has locked mtx. If lck had released or not locked the mutex, owns_lock would return false 
  
  same thing you can check like this also
    if (lck) {
    std::cout << "The lock is owned by lck." << std::endl;
    } else {
    std::cout << "The lock is not owned by lck." << std::endl;
    }


member functions

void lock() : Effectively calls mutex()->lock_shared()
bool try_lock()  :Effectively calls mutex()->try_lock_shared()
bool try_lock_for()   :Effectively calls mutex()->try_lock_shared_for(timeout_duration)
bool try_lock_until()  :Effectively calls mutex()->try_lock_shared_until(timeout_time)
void unlock() :Effectively calls mutex()->unlock_shared()

void swap()
std::shared_mutex* release()
std::shared_mutex* mutex()
bool owns_lock()

*/

/*
----------------------------------------------------------------------------------
Type	            Effect(s)

----------------------------------------------------------------------------------
defer_lock_t	    do not acquire ownership of the mutex
----------------------------------------------------------------------------------
try_to_lock_t	    try to acquire ownership of the mutex without blocking
----------------------------------------------------------------------------------
adopt_lock_t	    assume the calling thread already has ownership of the mutex
----------------------------------------------------------------------------------
*/
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>
std::shared_timed_mutex mtx;
int shared_data = 0;

void read_data1() {
    std::shared_lock lk(mtx,std::defer_lock);
    if (lk.try_lock_for(std::chrono::milliseconds(100))) {
       std::cout << "Read data 1: " << shared_data << std::endl;
    } else {
        std::cout << "Failed to acquire shared lock for reading 1." << std::endl;
    }
}
void read_data2() {
    std::shared_lock lk(mtx,std::defer_lock);
    if (lk.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "Read data 2: " << shared_data << std::endl;
        mtx.unlock_shared();
    } else {
        std::cout << "Failed to acquire shared lock for reading 2." << std::endl;
    }
}
void read_data3(){
    std::shared_lock lk(mtx);
    std::cout << "Read data 3: " << shared_data << std::endl;
}
void read_data4(){
    std::shared_lock lk(mtx);
    std::cout << "Read data 4: " << shared_data << std::endl;
}
void write_data() {
    std::unique_lock lk(mtx,std::defer_lock);
    if (lk.try_lock_for(std::chrono::milliseconds(100))) {
        for(int i=0;i<100000;i++){
        shared_data ++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Wrote data: " << shared_data << std::endl;
        mtx.unlock();
    } else {
        std::cout << "Failed to acquire exclusive lock for writing." << std::endl;
    }
}

int main() {
    std::jthread t3(write_data);
    std::jthread t1(read_data1);
    std::jthread t2(read_data2);
    std::jthread t4(read_data3);
    std::jthread t5(read_data4);
    
    return 0;
}
