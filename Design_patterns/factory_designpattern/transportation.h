#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H
#include"employee.h"
#include <iostream>
class transportation:public employees{
   inline static int deptid;
   std::string name;int age;
   public:
   transportation():employees(){
    std::cout<<"in transportation\n";
    deptid++;
   }
   void set_deteails(std::string m_name,int m_age);
   void get_deteails();
   ~transportation();
};
#endif
