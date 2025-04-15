#include<iostream>
#include<thread>

void fun1(int x){
   std::cout<<"passing by value\n";
   x=100;
}
void fun2(int &x){
   std::cout<<"passing by reference\n";
   x=100; 
}
void fun3(int *x){
  std::cout<<"passing by pointer\n";
   *x=1000;   
}

int main(){
    int x=10;
    std::thread t1(fun1,x);
    t1.join();
    std::cout<<"after passing by vlaue "<<x<<"\n";
    std::thread t2(fun2,std::ref(x));
    t2.join();
    std::cout<<"after passing by reference "<<x<<"\n";
    std::thread t3(fun3,&x);
    //t3.join();  //we are moving thread 3 to thread 4 so t3 no more thred now so we are not joining it 
    std::thread t4(std::move(t3)); //moving one thread to another 
    t4.join();
    std::cout<<"after passing by pointer "<<x<<"\n";
    return 0;
}



