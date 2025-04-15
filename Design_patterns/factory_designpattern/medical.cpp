#include "medical.h"
void medical::set_deteails(std::string m_name,int m_age){
       name=m_name;age=m_age;
   }
   void medical::get_deteails(){
    std::cout<<"name: "<<name<<" age: "<<age<<" id: "<<get_id()<<" department id: "<<deptid<<"\n";
   }
    medical::~medical(){
    std::cout<<"medical object deleted\n";
   }
