#include <iostream>
#include <string>
template<typename T>
class autoptr{
  T *ptr;
  public:
  autoptr(T *p=nullptr):ptr(p){
    
  }
  autoptr(autoptr<T> &obj){
      ptr= obj.ptr;
      obj.ptr=nullptr;
  }
  autoptr& operator=(autoptr<T> &obj){
    if(this!=&obj){
          if(ptr!=nullptr){
             delete ptr; // if present object pointing to any memory location delete the memory and assign it with obj memory
          }
         ptr=obj.ptr;
         obj.ptr=nullptr;
      }
      return obj;   
  }
  autoptr(autoptr<T> &&obj){
      ptr= obj.ptr;
      obj.ptr=nullptr;
      
  }
  autoptr& operator=(autoptr<T> &&obj){
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
  ~autoptr(){
    delete ptr;
  }
  
};
int main()
{
  autoptr<int> x(new int[100]),y(new int[100]); 
  std::cout<<*x<<" "<<*y<<"\n";
  y=x;
  std::cout<<*y<<" "<<*y<<"\n";// x is null *x will give seg fault
  y.reset(new int(100));
  x.reset(new int(122));
  std::cout<<*x<<" "<<*y<<"\n";
  
  autoptr<std::string>a(new std::string ("azeemshaik"));
  std::cout<<*a<<" "<<*a<<"\n";
}
