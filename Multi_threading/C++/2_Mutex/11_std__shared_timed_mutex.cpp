/*

Exclusive Locking: Only one thread can hold an exclusive lock at a time, preventing other threads from acquiring either shared or exclusive locks.
  std::shared_timed_mutex mtx;
  mtx.lock(); // Exclusive lock
  // Critical section
  mtx.unlock();

Shared Locking: Multiple threads can hold shared locks simultaneously, allowing concurrent read access
   std::shared_timed_mutex mtx;
   mtx.lock_shared(); // Shared lock
   // Read-only section
   mtx.unlock_shared();

Timed Exclusive Locking: Allows a thread to attempt to acquire an exclusive lock with a timeout.
   if (mtx.try_lock_for(std::chrono::seconds(1))) {
      // Critical section
      mtx.unlock();
    } 
    else {
      // Handle timeout
    }


Timed Shared Locking: Allows a thread to attempt to acquire a shared lock with a timeout

if (mtx.try_lock_shared_for(std::chrono::seconds(1))) {
    // Read-only section
    mtx.unlock_shared();
} else {
    // Handle timeout
}

member functions 

for exclusive locking
----------------------
void lock()
void unlock()
bool try_lock()
bool try_lock_for()
bool try_lock_until()

for shared locking
----------------------
void lock_shared()
void unlock_shared()
bool try_lock_shared()
bool try_lock_shared_for()
bool try_lock_shared_until()

*/
#include <iostream>
#include <thread>
#include <shared_mutex>

std::shared_timed_mutex mtx;
int shared_data = 0;

void read_data1() {
    if (mtx.try_lock_shared_for(std::chrono::milliseconds(100))) {
        // Safe read operation
        std::cout << "Read data 1: " << shared_data << std::endl;
        mtx.unlock_shared();
    } else {
        std::cout << "Failed to acquire shared lock for reading 1." << std::endl;
    }
}
void read_data2() {
    if (mtx.try_lock_shared_for(std::chrono::milliseconds(100))) {
        // Safe read operation
        std::cout << "Read data 2: " << shared_data << std::endl;
        mtx.unlock_shared();
    } else {
        std::cout << "Failed to acquire shared lock for reading 2." << std::endl;
    }
}

void write_data() {
    if (mtx.try_lock_for(std::chrono::milliseconds(100))) {
        // Safe write operation
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
    
    
    
    return 0;
}
