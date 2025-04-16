#include<iostream>
class azeem{
  public:
  template<typename T>
  T operator()(T a,T b){ //functor
      std::cout<<a<<" , "<<b<<"\n";
      return a+b;
  }
  void operator()(){  //functor
      std::cout<<"dummy function\n";
  }
  template<typename T>
   T operator()(T a,T b,T c){ //functor
      std::cout<<a<<" , "<<b<<" ,"<<c<<"\n";
      return a+b+c;
  }
    
};
int main(){
    azeem a;
    std::cout<<a(10,20)<<"\n";
    a();
    std::cout<<a(10,20,30)<<"\n";
    return 0;
}
