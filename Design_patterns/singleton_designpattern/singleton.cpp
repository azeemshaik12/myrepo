#include "singleton.h"

singleton* singleton::ptr;
std::mutex singleton::m;
singleton::singleton(){
    m_var=100;
    std::cout<<"object created\n";
}
singleton* singleton::getobject(){
if(ptr==nullptr){
m.lock();
if(ptr==nullptr){  
ptr=new singleton();  
}
m.unlock();
}
else{
    std::cout<<"object already created\n";
}
return ptr;
}

void singleton::set_var(int x){
   m_var=x; 
  }
int singleton::get_var(){
  return m_var;
  }
singleton::~singleton(){
std::cout<<"out of scope\n";
}
