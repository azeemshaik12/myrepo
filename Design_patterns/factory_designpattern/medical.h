#ifndef MEDICAL_H
#define MEDICAL_H
#include"employee.h"
#include <iostream>
class medical:public employees{
   inline static int deptid;
   std::string name;int age;
   public:
   medical():employees(){
    std::cout<<"in medical\n";
    deptid++;
   }
   void set_deteails(std::string m_name,int m_age);
   void get_deteails();
   ~medical();
};
#endif
