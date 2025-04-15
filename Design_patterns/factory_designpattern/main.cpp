#include "humanresourcer.h"
#include<memory>
int main(){
   
    std::unique_ptr<employees> ptr(hr::create(emp::TRANSPORTATION,"azeem",24));
    std::unique_ptr<employees> ptr2(hr::create(emp::MEDICAL,"azeem",24));
    ptr->get_deteails();
    ptr2->get_deteails();
    return 0;

}
