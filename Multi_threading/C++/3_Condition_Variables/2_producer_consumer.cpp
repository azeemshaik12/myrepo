//still have some errors in this code
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <deque>

std::mutex mtx;
std::condition_variable cv;
std::deque<int> a;

void producer(int count) {
    while (count) {
        std::unique_lock<std::mutex> l(mtx);
        cv.wait(l, [] { return a.size() < 50; });
        a.push_back(count);
        std::cout << "produced " << count << "\n";
        count--;
        cv.notify_all();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> l(mtx);
        //cv.wait(l, [] { return !a.empty(); }); //failng at a.size()== 0 so code is blocking temperoey solution is wait_for()
        if(!cv.wait_for(l,std::chrono::seconds(1), [] { return !a.empty(); })){
            std::cout<<a.size()<<" failed case \n";
            return ;
        }
        std::cout << "consumed " << a.front() << "\n";
        a.pop_front();
        cv.notify_all();
    }
}

int main() {
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    if(t1.joinable())
        t1.join();
    if(t2.joinable())
    t2.detach(); // Detach the consumer thread to run indefinitely

    return 0;
}
