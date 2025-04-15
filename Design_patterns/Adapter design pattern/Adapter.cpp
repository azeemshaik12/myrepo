// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

class Target{
std::string x;
public:
 virtual void process_data(){
    std::cout<<"reversing the string  "<<x;
}
std::string getx(){
    return x;
}
void setx(std::string _x){
    x=_x;
}
};
class Adaptee{
int y;
public:
Adaptee(int _y=110){
    y=_y;
}
void sety(int _y){
    y=_y;
}   
int gety(){
    return y;
}
};

class Adapter:public Target,public Adaptee{
public: 
   void process_data(){
     setx(std::to_string(gety()));
     std::cout<<"some functionality "<<gety()<<"\n";
     Target::process_data();
   }
    
};

class client{
 public:
 void do_process(Target *ptr){
  ptr->process_data();
 }
};


int main() {
    Target *T_obj=new Adapter();
    client c_obj;
    c_obj.do_process(T_obj);
    return 0;
}
