#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include<string>
class employees{
    inline static int id=0;
  public:
  employees(){
    id++;
  }
   int  get_id(){
    return id;
   }
  virtual void get_deteails()=0;
  virtual void set_deteails(std::string name,int age)=0;
  virtual ~employees(){
    
  }
};

#endif
