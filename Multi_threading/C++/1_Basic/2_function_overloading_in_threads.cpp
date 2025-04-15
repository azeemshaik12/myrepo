#include <iostream>
#include <thread>

void fun() {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";
}

void fun(int x, int y, int z) {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";
}

int main() {
    fun();
    std::thread t1(static_cast<void(*)()>(fun)); // Explicitly specify the function pointer
    std::thread t2(static_cast<void(*)(int, int, int)>(fun), 2, 3, 4); // Explicitly specify the function pointer
    std::thread t3([](){ fun(); }); // Using lambda to call fun()
    std::thread t4([](){ fun(1,2,3); }); // Using lambda to call fun(int, int, int)
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
