#include "transportation.h"
void transportation::set_deteails(std::string m_name,int m_age){
       name=m_name;age=m_age;
   }
   void transportation::get_deteails(){
    std::cout<<"name: "<<name<<" age: "<<age<<" id: "<<get_id()<<" department id: "<<deptid<<"\n";
   }
   transportation::~transportation(){
    std::cout<<"transportation object deleted\n";
   }
