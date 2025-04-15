#include<iostream>

namespace anu{   
template<typename T,typename... args>
class tuple{
T data;tuple<args...> Args;
public:
tuple(T val,args... o):data(val),Args(o...){
    
}

void display(){
    std::cout<<data<<",";
    Args.display();
}
template<int num>
auto& get(){
    if constexpr (num==0){
    return data;
    }
    else{
        return Args.template get<num-1>();
    }
}
};


template<typename T>
class tuple<T>{
T data;
public:
tuple(T val):data(val){
    
}
void display(){
    std::cout<<data<<"\n";
}
template<int num>
auto& get(){
 static_assert(num==0,"error");
    return data;
}
};
}
int main(){
  anu::tuple a(1,2,3,9,"azeem");
  a.display();
  std::cout<<a.get<0>()<<"\n";
  std::cout<<a.get<1>()<<"\n";
  std::cout<<a.get<2>()<<"\n";
  std::cout<<a.get<3>()<<"\n";
  std::cout<<a.get<4>()<<"\n";
}
