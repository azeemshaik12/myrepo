#include <iostream>
#include <string>
template<typename T>
class uniqueptr{
  T *ptr;
  public:
  uniqueptr(T *p=nullptr):ptr(p){
    
  }
  uniqueptr(uniqueptr<T> &obj)=delete;
  uniqueptr& operator=(uniqueptr<T> &obj)=delete;
  uniqueptr(uniqueptr<T> &&obj){
      ptr= obj.ptr;
      obj.ptr=nullptr;
      
  }
  uniqueptr& operator=(uniqueptr<T> &&obj){
      if(this!=&obj){
          if(ptr!=nullptr){
             delete ptr; // if present object pointing to any memory location delete the memory and assign it with obj memory
          }
         ptr=obj.ptr;
         obj.ptr=nullptr;
      }
      return obj;
  };
   T* operator->(){
    return ptr;
  }
  T& operator*(){
    return *ptr;
  }
   T* get(){
    return ptr;
  }
  void reset(T *ptr2=nullptr){
      if(ptr!=nullptr){
          delete ptr;
      }
      ptr=ptr2;
  }
  ~uniqueptr(){
    delete ptr;
  }
  
};
int main()
{
  uniqueptr<int> x(new int[100]),y(new int[100]); 
  std::cout<<*x<<" "<<*y<<"\n";
  y=std::move(x);
  std::cout<<*y<<" "<<*y<<"\n";// x is null *x will give seg fault
  y.reset(new int(100));
  x.reset(new int(122));
  std::cout<<*x<<" "<<*y<<"\n";
  
  uniqueptr<std::string>a(new std::string ("azeemshaik"));
  std::cout<<*a<<" "<<*a<<"\n";
}