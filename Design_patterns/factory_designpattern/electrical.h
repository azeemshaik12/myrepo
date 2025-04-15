#ifndef ELECTRICAL_H
#define ELECTRICAL_H
#include"employee.h"
#include <iostream>
class electrical:public employees{
   inline static int deptid;
   std::string name;int age;
   public:
   electrical():employees(){
    std::cout<<"in electrical\n";
    deptid++;
   }
   void set_deteails(std::string m_name,int m_age);
   void get_deteails();
   ~electrical();
};
#endif
