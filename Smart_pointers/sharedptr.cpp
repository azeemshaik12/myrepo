// sharedptr
/*
this code still have memomry leaks need to write this in a better way
*/
#include <iostream>
#include <string>
template<typename T>
class sharedptr{
T *ptr;
int *count;
void increment(){
    if(ptr!=nullptr){
     ++(*count); 
    // std::cout<<"incr\n";
    }
    else{
     // std::cout<<"init\n";
      count=new int(0);  
    }
}
void decrement(){
    if(ptr!=nullptr){
      if((*count)==1){
          delete ptr;
          delete count;
         //  std::cout<<"delted\n";
      }
      else{
        //  std::cout<<"decre\n";
      --(*count);  
      }
    }
}
public:
sharedptr(T *p=nullptr):ptr(p),count(new int(0)){
   // std::cout<<"ctor called\n";
    if(ptr!=nullptr){
        ++(*count);
    }
}
sharedptr(sharedptr<T> &obj){
    ptr=obj.ptr;
    count=obj.count;
    increment();
}
sharedptr& operator=(sharedptr<T> &obj){
    if(this!=&obj){
    if(ptr==nullptr){
    ptr=obj.ptr;
    count=obj.count;
    increment();
    }
    else{
     decrement();
     ptr=obj.ptr;
     count=obj.count;
     increment();
    }
    }
    return *this;
}
int use_count(){
    return *count;
}
void reset(T *p=nullptr){
   decrement();
   ptr=nullptr; 
   increment();
   if(p!=nullptr){
   ptr=p;
   increment();
   }
}
T* operator->(){
    return ptr;
  }
  T& operator*(){
   return *ptr;   
  }  

T* get(){
   return ptr; 
}
bool unique(){
    return (*count)==1;
}
~sharedptr(){
 decrement();   
}
template<typename u>
friend std::ostream& operator<<(std::ostream& o,sharedptr<u> &p);
template<typename u>
friend std::istream& operator<<(std::istream& i,sharedptr<u> &p);

sharedptr(sharedptr<T> &&obj){
  ptr=obj.ptr;
    count=obj.count;
    obj.ptr=nullptr;
    obj.count=new int(0);  
}


sharedptr& operator=(sharedptr<T> &&obj){
    if(this!=&obj){
    if(ptr==nullptr&&obj.ptr!=nullptr){
    ptr=obj.ptr;
    count=obj.count;
    obj.ptr=nullptr;
    obj.count=new int(0);
    }
    else if(ptr==nullptr&&obj.ptr==nullptr){
      //do nothing  
    }
    else if(ptr!=nullptr&&obj.ptr==nullptr){
       decrement();
       ptr=obj.ptr;
       count=obj.count;
    }
    else{
     decrement();
     ptr=obj.ptr;
     count=obj.count;
     obj.ptr=nullptr;
     *obj.count=0;
    }
    }
    return *this;
}


};
template<typename u>
 std::ostream& operator<<(std::ostream& o,sharedptr<u> &p){
     o<<p.ptr;
     return o;
 }
 template<typename u>
 std::istream& operator<<(std::istream& i,sharedptr<u> &p){
    i>>(*p.ptr);
    return i;
}
int main() {
   sharedptr<int> p(new int(10)),q(new int(10)),x,y;
   q=p;
   x=p;
   x.reset(new int(30));
   p.reset(new int(44));
   y.reset(new int(88));
   p=y;
   q=p;
   x=q;
   std::cout<<p.use_count()<<" "<<q.use_count()<<"\n";
   std::cout<<x.use_count()<<" "<<y.use_count()<<"\n";
   
    std::cout<<p<<" "<<q<<"\n";
    std::cout<<x<<" "<<y<<"\n";
    
    std::cin>>*p;
    std::cout<<*p<<" "<<*q<<"\n";
    std::cout<<*x<<" "<<*y<<"\n";
    
sharedptr<std::string> a(new std::string("azeem"));
 std::cout<<*a<<"\n";
 std::cin>>*a;
 std::cout<<*a;
    
    return 0;
}