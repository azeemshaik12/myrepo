/*
Deferred Locking: You can create a std::unique_lock without immediately locking the mutex.
   This is useful when you need to perform some operations before locking.

   std::mutex mtx;
   std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
   // Perform some operations
   lck.lock(); // Lock the mutex later

   std::unique_lock<std::mutex> lck1(mtx1, std::defer_lock);
   std::unique_lock<std::mutex> lck2(mtx2, std::defer_lock);
   //created two uniquelocks 
   std::lock(lck1,lck2); //locked both later


Timed Locking: You can attempt to lock the mutex for a specified duration or until a specific time point.
   std::mutex mtx;
   std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
   if (lck.try_lock_for(std::chrono::seconds(1))) {
    // Critical section
   } else {
    // Handle timeout
   }

Condition Variables: std::unique_lock is often used with condition variables to wait for a condition to be met.
   std::condition_variable cv;
   std::unique_lock<std::mutex> lck(mtx);
   cv.wait(lck, []{ return condition_met; });

Transfer of Lock Ownership: You can transfer the ownership of a lock to another std::unique_lock
   std::unique_lock<std::mutex> lck1(mtx);
   std::unique_lock<std::mutex> lck2(std::move(lck1)); // Transfer ownership
  
Swapping two unique_locks
   std::mutex mtx1, mtx2;
   std::unique_lock<std::mutex> lock1(mtx1);
   std::unique_lock<std::mutex> lock2(mtx2);

   // Swap the locks
   std::swap(lock1, lock2);//non member function  
   lock1.swap(lock2);//member function 

Release function   -->return type std::mutex * (mutext_type *)
  std::mutex mtx,mtx2;
  std::unique_lock<std::mutex> lck(mtx);

  // Release the lock
  std::mutex* released_mtx = lck.release();

  // Now, lck no longer manages the mutex, and you must manually unlock it
  released_mtx->unlock();
  
  // Now, lck no longer manages any mutex
  // Assign a new mutex to lck
  lck = std::unique_lock<std::mutex>(mtx2);


Mutext()  function  -->return type std::mutex * (mutext_type *)
  std::mutex mtx;
  std::unique_lock<std::mutex> lck(mtx);

  // Get the pointer to the managed mutex
  std::mutex* mtx_ptr = lck.mutex();

  if (mtx_ptr) {
    // mtx_ptr points to mtx
    std::cout << "Mutex is managed by lck." << std::endl;
  } else {
    std::cout << "No mutex is managed by lck." << std::endl;
  }
  In this example, mtx_ptr will point to mtx because lck is managing it. If lck was not managing any mutex, mtx_ptr would be nullptr


owns_lock()  function --return type bool
  std::mutex mtx;
  std::unique_lock<std::mutex> lck(mtx);

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

lock()
try_lock()
try_lock_for()
try_lock_until()
unlock()

swap()
release()
mutex()
owns_lock()


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
#include <mutex>
using namespace std::chrono_literals;
std::mutex mtx;
void print_block_1(int n, char c) {
    std::unique_lock<std::mutex> lck(mtx);
    for (int i = 0; i < n; ++i) {
        std::cout << c;
    }
    std::cout << '\n';
}
void print_block(int n, char c) {
    std::unique_lock<std::mutex> lck(mtx, std::defer_lock); // Create a unique_lock without locking
    lck.lock(); // Lock the mutex
    for (int i = 0; i < n; ++i) {
        std::cout << c;
    }
    std::cout << '\n';
    lck.unlock(); // Unlock the mutex
    std::this_thread::sleep_for(2000ms);
    lck.lock(); // Lock the mutex
    for (int i = 0; i < n; ++i) {
        std::cout << c;
    }
    std::cout << '\n';
    lck.unlock(); // Unlock the mutex
}

int main() {
    std::jthread th1(print_block, 50, '*');
    std::jthread th2(print_block, 50, '$');
    std::jthread th3(print_block_1, 50, 'A');
    std::jthread th4(print_block_1, 50, 'B');
  
    return 0;
}

