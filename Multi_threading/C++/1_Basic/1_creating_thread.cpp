#include <iostream>
#include <thread>
class azeem{
  public:
  azeem(){
      std::cout<<"object is created\n";
  }
  void operator()(int x,int y){ //functor
  std::cout<<"functor called\n";
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";
  }
  void function(int x,int y){
    std::cout<<"non static member function called\n";
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";  
  }
  static void func(int x,int y){
    std::cout<<"static member function called\n";
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";   
  }
    
};
void fun1() {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";
}

void fun2(int x, int y, int z) {
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << this_id << " thread\n";
}

int main() {
    std::thread t1(fun1); //1.using function without arguments
   
    std::thread t2(fun2,1,2,3); //2.using function with arguments
   
    std::thread t3([](){
     std::thread::id this_id = std::this_thread::get_id();
     std::cout << this_id << " thread\n";   
    });//3.using lambda function
   
    std::thread t4(azeem{},1,5);//4.using functor
    azeem obj;
    std::thread t5(&azeem::function,&obj,1,2);//5.usig non -static member function(need object )
    
    std::thread t6(&azeem::func,1,2); //6.using staic member function (no need of object)
    
    std::thread t7([&](){
        obj.function(1,2);
    }); //7.calling  non staic member function in side lambda  (need object)
    
    std::thread t8([](){
        azeem::func(1,3);
    }); //8.calling  staic member function in side lambda  (no need of object)
    
    std::thread t9([](){
        azeem{}(1,2);
    }); //9.calling  functor inside a lamda
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    return 0;
}


