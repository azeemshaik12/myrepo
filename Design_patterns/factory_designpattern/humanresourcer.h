#include"employee.h"
#include"transportation.h"
#include"medical.h"
#include"electrical.h"
enum emp{
   TRANSPORTATION,
   MEDICAL,
   ELECTRICAL,
};
class hr{
    inline static employees *ptr=nullptr;
    public:
    static employees* create(int a,std::string name,int age){
       if(a==emp::TRANSPORTATION)
       {
         ptr=new transportation();
       }
      else  if(a==emp::MEDICAL)
       {
         ptr=new medical();
       }
        else  if(a==emp::ELECTRICAL)
       {
         ptr=new electrical();
       }
        ptr->set_deteails(name,age);
       return ptr;
        
    }
};
