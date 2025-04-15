#include "electrical.h"
void electrical::set_deteails(std::string m_name,int m_age){
       name=m_name;age=m_age;
   }
   void electrical::get_deteails(){
    std::cout<<"name: "<<name<<" age: "<<age<<"id: "<<get_id()<<" department id: "<<deptid<<"\n";
   }
    electrical::~electrical(){
    std::cout<<"electrical object deleted\n";
   }
// this is design patterns file structure 