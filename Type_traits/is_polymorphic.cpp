#include <iostream>

class azeem{
    public:
    virtual void fun(){
        
    }
};
class vaseem:public azeem{
    public:
    void fun(){
        
    }
};
class some{
  public:
    void fun(){
        
    } 
};
template<typename T>
void fu(T obj){
  if(std::is_polymorphic<T>::value){
      std::cout<<"obj is polymorphic\n";
  } 
  else{
     std::cout<<"obj is not polymorphic\n"; 
  }
}
int main(){
    vaseem obj;
    some o;
    fu<vaseem>(obj);
    fu<some>(o);
    return 0;
}
