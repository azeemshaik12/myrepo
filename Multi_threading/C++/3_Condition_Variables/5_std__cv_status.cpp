#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

// Global variables
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

// Worker thread function 1
void worker1() {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait for 1 second or until notified
    if(cv.wait_for(lock, std::chrono::seconds(1)) == std::cv_status::no_timeout) {
        std::cout << "w1 Notification received, proceeding.\n";
    } else {
        std::cout << "w1 Timeout occurred, no notification received.\n";
    }
}

// Worker thread function 2
void worker2() {
    std::unique_lock<std::mutex> lock(mtx);
    // Wait for 1 second or until notified
    if(cv.wait_for(lock, std::chrono::seconds(1)) == std::cv_status::timeout) {
        std::cout << "w2 Timeout occurred, no notification received.\n";
    } else {
        std::cout << "w2 Notification received, proceeding.\n";
    }
}

// Notifier thread function
void notifier() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work for 0.5 seconds
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // Set the condition to true
    }
    cv.notify_one(); // Notify one waiting thread
    //cv.notify_all();// both workers get notification
}

int main() {
    // Create threads
    std::thread t1(worker1);
    std::thread t2(notifier);
    std::thread t3(worker2);

    // Wait for threads to finish
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
